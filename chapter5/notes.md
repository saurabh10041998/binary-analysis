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
