# basic binary analysis

## challenge 1: payload

1. Finding out type of file
```bash
file build/payload
```
2. Checking the contents of text file 
```bash
head build/payload
```
3. base64 decode payload
```bash
base64 -d build/payload  > build/decoded_payload  
```

4. -z flag to look inside the type of file
```bash
 file -z build/decoded_payload
```
5. Extracting tar bundle
```bash
 tar -xvzf decoded_payload
```
6. Finding out program dependancy on Shared Object file 
```bash
 ldd ctf
```
7. grepping ELF to  figure out how many are binaries 
```bash
 grep "ELF" *
```
8. ASCII table for ref
```bash
man ascii
```
9. running xxd to figure out bitmap file structure
```bash
xxd 67b8601 | head -n 15
```
10. output xxd in cstyle array
```bash
 xxd -i 67b8601 | head -n 15
```
11. carving out elf header(64 bytes for 64 bit bin) from bitmap
```bash
dd skip=52 count=64 if=bitmap of=elf_header bs=1
```
12. readelf header recon
```bash
readelf -h elf_header
```
13. Computing the size of binary
```bash
    size = sh_offset + e_shentsize * e_shnum
         = 8568 + 64 * 27
         = 10,296
```
Since section header is last part of ELF, you have given offset of section header table
(`sh_offset`),size of section header entry (shentsize) and number of entries (shnum)

14. carving .so from bitmap using dd
```bash
 dd skip=52 count=10296 if=67b8601 of=lib5ae9b7f.so bs=1 
``` 
15. readelf to check symbols and header for so file
```bash
 readelf -h lib5ae9b7f.so
```
16. parsing static symbol table with nm
```bash
 nm lib5ae9b7f.so
```
17. parsing dynamic symbol table with nm
```bash
nm -D lib5ae9b7f.so
```
18. demangle symbols with nm
```bash
 nm -D --demangle lib5ae9b7f.so
```
19. c++filt to demangle 
```bash
 c++filt  _Z11rc4_decryptP11rc4_state_tPhi
```
20. using binwalk to extract the files
```bash
 binwalk --dd=".*" 67b8601
```
21. linking to custom so file
```bash
$ export LD_LIBRARY_PATH=`pwd` 
$ ./ctf
$ echo $?   
```
22. running strings to get some idea
```bash
strings ctf
```
23. running the strace on file
```bash
 strace -o ctf.strace ./ctf show_me_the_flag
```
24. running ltrace(need to install)
```bash
 ltrace -i -C ./ctf show_me_the_flag   
 GUESSME="pleaseSubscribe" ltrace -i -C ./ctf show_me_the_flag
```
25. observing the readonly data secton using objdump
```bash
 objdump -s --section .rodata ctf   
```
### mangling
mangled string -> combination of original function name and an encoding of function paramters
disadv -> difficult to read
adv -> free paramters type info for reverse engineering
