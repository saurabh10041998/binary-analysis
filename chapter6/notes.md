## Dynamic tracing using gdb
1. Loading binary using gdb
```bash
gdb /bin/ls
```
2. Getting the entry point of the binary
```bash
info files
```
3. gdb to dynamic tracing
```bash
(gdb) set pagination off
(gdb) set logging on
(gdb) set logging redirect on
(gdb) while 1
> si
> end
```

4. 
