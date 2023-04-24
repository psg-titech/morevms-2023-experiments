# Introduction
This document provides programs running on MicroPython and logs of HPS program on FPGA and the running MicroPython program.

# Memory measurement
## Direct
### 10 times
```python
>>> import machine
>>> gpio16 = machine.Pin(16, machine.Pin.IN)
>>> gpio17 = machine.Pin(17, machine.Pin.OUT)

>>> import gc
>>>
>>> gc.mem_free()
108720
>>> for i in range(10):
...   gpio17.value(gpio16.value())
... gc.mem_free()
...
108272
```

### 100 times
```python
>>> import machine
>>> gpio16 = machine.Pin(16, machine.Pin.IN)
>>> gpio17 = machine.Pin(17, machine.Pin.OUT)

>>> import gc
>>>
>>> gc.mem_free()
108720
>>> for i in range(100):
...   gpio17.value(gpio16.value())
... gc.mem_free()
...
108112
```

## Tuple
### 10 times
```python
>>> import machine
>>> gpio16 = machine.Pin(16, machine.Pin.IN)
>>> gpio17 = machine.Pin(17, machine.Pin.OUT)

>>> import gc
>>>
>>> gc.mem_free()
108720
>>> for i in range(10):
...   (v, a, b) = (gpio16.value(), 1, 2)
...   gpio17.value(v)
... gc.mem_free()
...
107808
```

### 100 times
```python
>>> import machine
>>> gpio16 = machine.Pin(16, machine.Pin.IN)
>>> gpio17 = machine.Pin(17, machine.Pin.OUT)

>>> import gc
>>>
>>> gc.mem_free()
108720
>>> for i in range(100):
...   (v, a, b) = (gpio16.value(), 1, 2)
...   gpio17.value(v)
... gc.mem_free()
...
104928
```

# Latency measurement
## Direct
### MicroPython
```python
>>> import machine
>>> gpio16 = machine.Pin(16, machine.Pin.IN)
>>> gpio17 = machine.Pin(17, machine.Pin.OUT)
>>> def irq_handler(p):
...   gpio17.value(gpio16.value())
...
>>> gpio16.irq(irq_handler)
```

### HPS Program
```
$ dotnet run -- write 120000 MicroPython-direct.dat
Reading Start
Start time: 1/20/2023 9:01:24 AM
End time: 1/20/2023 9:11:30 AM
```

## Tuple
### MicroPython
```python
>>> import machine
>>> gpio16 = machine.Pin(16, machine.Pin.IN)
>>> gpio17 = machine.Pin(17, machine.Pin.OUT)
>>> def irq_handler(p):
...   (v, a, b) = (gpio16.value(), 1, 2)
...   gpio17.value(v)
...
>>> gpio16.irq(irq_handler)
```

### HPS Program
```
$ dotnet run -- write 120000 MicroPython-tuple.dat
Reading Start
Start time: 1/20/2023 2:53:27 PM
End time: 1/20/2023 3:03:32 PM
```
