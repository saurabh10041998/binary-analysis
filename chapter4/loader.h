#ifndef LOADER_H
#define LOADER_H

#include<stdint.h>
#include<string>
#include<vector>
#include<bfd.h>

class Binary;
class Section;
class Symbol;

using namespace std;

class Symbol {
public:
   enum SymbolType {
    SYM_TYPE_UKN = 0,
    SYM_TYPE_FUNC = 1
   };

    Symbol(): type(SYM_TYPE_UKN), name(), addr(0) {}
    
    SymbolType type;
    string name;
    uint64_t addr;
};

class Section {
public:
    enum SectionType {
        SEC_TYPE_NONE = 0,
        SEC_TYPE_CODE = 1,
        SEC_TYPE_DATA = 2
    };
    
    Section(): binary(NULL), type(SEC_TYPE_NONE), vma(0), size(0), bytes(NULL) {}
    bool contains(uint64_t addr){ return (addr >= vma) && (addr - vma < size); }

    Binary  *binary;
    string name;
    SectionType type;
    uint64_t vma;
    uint64_t size;
    uint8_t *bytes;
};

class Binary {
public:
    enum BinaryType {
        BIN_TYPE_AUTO = 0,
        BIN_TYPE_ELF = 1,
        BIN_TYPE_PE = 2
    };
    enum BinaryArch {
        ARCH_NONE = 0,
        ARCH_X86 = 1
    };
    Binary() : type(BIN_TYPE_AUTO), arch(ARCH_NONE), bits(0), entry(0) {}

    Section  *get_text_section() {
        for(auto &s: sections) {
            if(s.name == ".text")
                return &s;
        }
        return NULL;
    }
    string filename;
    BinaryType type;
    string type_str;
    BinaryArch arch;
    string arch_str;
    unsigned bits;
    uint64_t entry;
    vector<Section> sections;
    vector<Symbol> symbols;
};

int load_binary(string &fname, Binary* bin, Binary::BinaryType type);
void unload_binary(Binary *bin);

static int load_binary_bfd(string &fname, Binary *bin, Binary::BinaryType type);
static bfd* open_bfd(string &fname);
static int load_symbols_bfd(bfd* bfd_h, Binary *bin);
static int load_dynsym_bfd(bfd* bfd_h, Binary *bin);
static int load_sections_bfd(bfd* bfd_h, Binary *bin);

#endif /* LOADER_H */ 
