# Introduction
We executed emfrp-repl with some changes below and this document presents a log 

# Source Code Changes
We changed in include/vm/gc.h:
 * MEMORY_MANAGER_HEAP_SIZE 512 -> 8192
 * MEMORY_MANAGER_WORK_LIST_SIZE 256 -> 1024

# The programs to be executed
## Direct
```
node gpio17 = gpio16
```

## Tuple
```
node (v, a, b) = (gpio16, 1, 2)
node gpio17 = v
```

## 10 Nodes
```
node (node0, a0, b0) = (gpio16, 1, 2)
node (node1, a1, b1) = (node0, 1, 2)
...
node (node9, a9, b9) = (node8, 1, 2)
node gpio17 = node9
```

# Log output
## Measuring memory usage
### Initial state (not present in the extended abstract.)

```
sizeof(object_t) is 16.
Initial memory usage is:
  Heap free size: 139948, Managed available: 8190
```

### Direct
```
Initial   : Heap free size: 139828, Managed available: 8190
10 times  : Heap free size: 139828, Managed available: 8190
100 times : Heap free size: 139828, Managed available: 8190
```

### Tuple
```
Initial   : Heap free size: 139420, Managed available: 8190
10 times  : Heap free size: 139260, Managed available: 8180
100 times : Heap free size: 137812, Managed available: 8090
```

### 10 Nodes
```
Initial   : Heap free size: 135720, Managed available: 8190
10 times  : Heap free size: 134104, Managed available: 8090
100 times : Heap free size: 119688, Managed available: 7190
```

## Measuring latency
### Direct
```
$ dotnet run -- write 120000 emfrp-repl-direct.dat
Reading Startnn
Start time: 1/20/2023 4:12:25 PM
End time: 1/20/2023 4:22:32 PM
```

### Tuple
```
$ dotnet run -- write 120000 emfrp-repl-tuple.dat
Reading Start
Start time: 1/20/2023 4:32:45 PM
End time: 1/20/2023 4:42:52 PM
```

### 10 Nodes
```
$ dotnet run -- write 120000 emfrp-repl-10nodes.dat
Reading Start
Start time: 1/20/2023 4:53:04 PM
End time: 1/20/2023 5:03:10 PM
```

