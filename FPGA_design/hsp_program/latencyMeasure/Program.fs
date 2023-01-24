module LatencyMeasure

open System
open System.IO
open Mono.Unix.Native
open System.Net.Sockets
open System.Collections.Concurrent
open System.Threading
open System.Runtime.InteropServices

let AXI_BASE = 0xFF200000UL
let MY_IP_BASE = 0x4000UL
let MY_IP_SPAN = 0x1024UL
let MY_IP_MAX_SIZE = 256

let mutable isContinue = true
let mutable isStop = false

[<EntryPoint>]
let main (argv : string []) =
    if argv.Length = 0 then
        printfn "give out or write"
        System.Environment.Exit(0)
    let (writeLen, filename) =
        if argv.[0] = "out" then (0, String.Empty) else
            if argv.Length <> 3 then
                printfn "Give the second argument, number of samples."
                printfn "Give the third argument, the output file name."
                System.Environment.Exit(0)
                (0, String.Empty)
            else
                match System.Int32.TryParse argv.[1] with
                | true, i -> (i, argv.[2])
                | false, _ ->
                    printfn "The second argument is number of samples."
                    System.Environment.Exit(0)
                    (0, String.Empty)

    let mutable fd = Unchecked.defaultof<int>
    let mutable virtualBase = Unchecked.defaultof<IntPtr>
    
    Console.CancelKeyPress.Add(fun _ -> isContinue <- false)

    fd <- Mono.Unix.Native.Syscall.``open``("/dev/mem", Mono.Unix.Native.OpenFlags.O_RDWR ||| Mono.Unix.Native.OpenFlags.O_SYNC)
    if fd = -1 then
        Console.WriteLine "ERROR: could not open \"/dev/mem\"..."
        exit 1
    virtualBase <- Mono.Unix.Native.Syscall.mmap(IntPtr.Zero, MY_IP_SPAN, Mono.Unix.Native.MmapProts.PROT_READ, Mono.Unix.Native.MmapFlags.MAP_SHARED, fd, int64 (AXI_BASE + MY_IP_BASE))

    if virtualBase = nativeint -1 then
        Console.WriteLine "ERROR: mmap() failed..."
        Mono.Unix.Native.Syscall.close fd |> ignore
        exit 1

    Console.WriteLine("Reading Start")
    let TheMem = new ReadOnlySpan<Int32>((virtualBase).ToPointer(), MY_IP_MAX_SIZE)
    let mutable counter = TheMem.[0]
    let mutable writeCount = 0
    if writeLen = 0 then
        while isContinue do
            let nc = TheMem.[0]
            while nc <> counter do
                let new_counter = TheMem.[0]
                if new_counter < counter then
                    while counter < MY_IP_MAX_SIZE do
                        System.Console.WriteLine(TheMem.[counter])
                        counter <- counter + 1
                    counter <- 1
                while counter < new_counter do
                    System.Console.WriteLine(TheMem.[counter])
                    counter <- counter + 1
            Thread.Sleep(10)
    else
        let fs = File.Open(filename, FileMode.Create)
        let m = MemoryMarshal.Cast<System.Int32, System.Byte>(TheMem)
        printfn "Start time: %A" DateTime.Now
        while isContinue && (writeCount < writeLen) do
            let nc = TheMem.[0]
            while (nc <> counter) && (writeCount < writeLen) do
                let new_counter = TheMem.[0]
                if new_counter < counter then
                    fs.Write(m.Slice(counter*4, (MY_IP_MAX_SIZE - counter)*4))
                    writeCount <- writeCount + MY_IP_MAX_SIZE - counter
                    counter <- 1
                fs.Write(m.Slice(counter*4, (new_counter - counter)*4))
                writeCount <- writeCount + new_counter - counter
                counter <- new_counter
            Thread.Sleep(2)
        printfn "End time: %A" DateTime.Now
        fs.Close()


    if Mono.Unix.Native.Syscall.munmap(virtualBase, MY_IP_SPAN) <> 0 then
        Console.WriteLine "ERROR: munmap() failed.."
        Mono.Unix.Native.Syscall.close fd |> ignore
        1
    else
        Mono.Unix.Native.Syscall.close fd |> ignore
        0 // return an integer exit code
