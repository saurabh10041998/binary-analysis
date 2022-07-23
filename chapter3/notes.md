## PE file format
1. Stands for Portable Executable File Format
2. modified version of Common Object File Format(COFF)
3. 64 bit PE is PE32+
4. WinNT.h file has info

## MS-DOS header and MS-DOSstub
1. MS-DOS Header - for backward compact with DOS user
2. Describes how to load MS-DOS stub
3. MSDOS-stub -> prints "this program is not supported on DOS"
4. one imp field from MSDOS header -> `e_lfanew` which tells from where actual PE binary begins
5. MSDOS header == MZheader

##  PE signature, file header, optional header
1. PE exe header  -> 3 parts (32 bit signature, file header, optional header)
2. struct name: `IMAGE_NT_HEADERS64`
3. Examining the PE binary using objdump
```bash
objdump -x main.exe
```
### PE signature
just "PE"

### PE file header
1. properties of PE file
2. important sections => Machine, NumberOfSections, SizeOfOptionalHeader and Characteristics
3. ELF's machine = pE machine flag
4. NumberOfSections, number of entries in file header
5. SizeOfOptionalHeader => size of optional header
6. Characteristics => specify flags like endianess, DLL or not, debug info stripped etc.

## PE Optional Header
1. PE Optional header: properties of binary, lots of fields
2. magic value(16 bit) => PE32+ (64 bit version)
3.  Fields that specify minor and major version of linker + field to specify min OS version to run binary
4. ImageBase : base virtual address where PE is to be loaded
5. Other pointers are specified as Relative Virtual Addresses(RVAs).
6. For example BaseOfCode = Base address of code sections as an RVA
So actual base virtual address of code = BaseOfImage + BaseOfCode
7. AddressOfEntryPoint = Address of entry point as an RVA
8. DataDirectory section = entries of type `IMAGE_DATA_DIRECTORY` 
9. DD has entries of RVA and size of important sections
10. most important entries index 0 =>  export directory and index 5 => relocation table

