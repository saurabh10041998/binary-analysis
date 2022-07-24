## libbfd
1. binary file descriptor library
2. under binutils-dev package
3. header file: /usr/include/bfd.h


## loader output

```bash
$ ./test_loader /bin/ls
aded binary '/bin/ls' elf64-x86-64i386:x86-64 (64 bits) entry@0x0000000000006180
[*] Total detected sections -> 28
    0x00000000000002a8 28       .interp              CODE
    0x00000000000002c4 36       .note.gnu.build-id   CODE
    0x00000000000002e8 32       .note.ABI-tag        CODE
    0x0000000000000308 172      .gnu.hash            CODE
    0x00000000000003b8 3072     .dynsym              CODE
    0x0000000000000fb8 1477     .dynstr              CODE
    0x000000000000157e 256      .gnu.version         CODE
    0x0000000000001680 160      .gnu.version_r       CODE
    0x0000000000001720 5184     .rela.dyn            CODE
    0x0000000000002b60 2520     .rela.plt            CODE
    0x0000000000004000 23       .init                CODE
    0x0000000000004020 1696     .plt                 CODE
    0x00000000000046c0 24       .plt.got             CODE
    0x00000000000046e0 81118    .text                CODE
    0x00000000000183c0 9        .fini                CODE
    0x0000000000019000 20233    .rodata              CODE
    0x000000000001df0c 2372     .eh_frame_hdr        CODE
    0x000000000001e850 12904    .eh_frame            CODE
    0x0000000000023350 8        .init_array          CODE
    0x0000000000023358 8        .fini_array          CODE
    0x0000000000023360 2680     .data.rel.ro         CODE
    0x0000000000023dd8 496      .dynamic             CODE
    0x0000000000023fc8 56       .got                 CODE
    0x0000000000024000 864      .got.plt             CODE
    0x0000000000024360 616      .data                CODE
    0x00000000000245e0 4824     .bss                 CODE
    0x0000000000000000 73       .gnu_debugaltlink    CODE
    0x0000000000000000 52       .gnu_debuglink       CODE
[*] Scanned symbol table
    __ctype_toupper_loc                      0x0000000000000000 FUNC
    getenv                                   0x0000000000000000 FUNC
    fgetfilecon                              0x0000000000000000 FUNC
    sigprocmask                              0x0000000000000000 FUNC
    __snprintf_chk                           0x0000000000000000 FUNC
    raise                                    0x0000000000000000 FUNC
    abort                                    0x0000000000000000 FUNC
    __errno_location                         0x0000000000000000 FUNC
    strncmp                                  0x0000000000000000 FUNC
    _ITM_deregisterTMCloneTable              0x0000000000000000 FUNC
    localtime_r                              0x0000000000000000 FUNC
    _exit                                    0x0000000000000000 FUNC
    strcpy                                   0x0000000000000000 FUNC
    __fpending                               0x0000000000000000 FUNC
    isatty                                   0x0000000000000000 FUNC
    sigaction                                0x0000000000000000 FUNC

```
