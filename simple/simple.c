#include <string.h>


// emcc -g -sWASM=1 -sSIDE_MODULE=1 -o simple.wasm simple.c
// All functions are exported by default in side module mode

// Imported JS functions from env object
extern void print(char*);

char src[] = "someRandomString";

int main(){
    print("testing123");

    // We can directly read/write to linear memory with dereferencing
    // *(char*)0x0 = 'b';

    char* dest = 0x0;
    strcpy(dest, src);

    return 0;
}