//#include <stdlib.h>
#include <string.h>


// emcc -g -sWASM=1 -sSIDE_MODULE=1 -o simple.wasm simple.c
// All functions are exported by default in side module mode

// Imported JS functions from env object
extern void imported_func(int);

float g(float x) {
    return x + 1.1;
}

int main(){
    int x = 1;

    imported_func(42);

    return x+1;
}