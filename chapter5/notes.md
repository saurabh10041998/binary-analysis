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

