# Introduction
We executed emfrp programs available on emfrp_programs.
This document provides a log of HPS program on FPGA and the running emfrp program.

# Log output
## Direct
### Running Emfrp Program (Memory measurement)
Same result in both 10 and 100 times.
```
From: 294544
To: 294544
```

### HPS program (Latency measurement)
```
$ dotnet run -- write 120000 emfrp-direct.dat
Reading Start
Start time: 1/20/2023 3:12:46 PM
End time: 1/20/2023 3:22:51 PM
```

## Tuple
### Running Emfrp Program (Memory measurement)
Same result in both 10 and 100 times.
```
From: 294504
To: 294504
```

### HPS program (Latency measurement)
```
$ dotnet run -- write 120000 emfrp-tuple.dat
Reading Start
Start time: 1/20/2023 3:35:30 PM
End time: 1/20/2023 3:45:36 PM
```

## 10 Nodes
### Running Emfrp Program (Memory measurement)
Same result in both 10 and 100 times.
```
From: 294360
To: 294360
```

### HPS program (Latency measurement)
```
dotnet run -- write 120000 emfrp-10nodes.dat
Reading Start
Start time: 1/20/2023 3:53:02 PM
End time: 1/20/2023 4:03:09 PM
```
