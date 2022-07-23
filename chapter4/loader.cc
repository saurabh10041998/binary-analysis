#include<bfd.h>
#include "loader.h"


int 
load_binary(string fname, Binary *bin, Binary::BinaryType type) { 
    return load_binary_bfd(fname, bin, type);
}


void
unload_binary(Binary *bin) {
    size_t i;
    Section *sec; 
    for(i = 0; i < bin->sections.size(); ++i){ 
        if(sec->bytes) {
            free(sec->bytes);
        }
    }
}
