#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "emscripten.h"


// emcc heap.c -g -o heap.js -sEXPORTED_FUNCTIONS=_main -sEXPORTED_RUNTIME_METHODS=ccall,cwrap


// use after free and double free do not raise errors
// heap allocator seems to do first smallest fit matching. It will also merge adjacent frees for big allocations if needed.
// If no good match, it will allocate at the top of the heap. Pretty similar implementation to libc's malloc.
int main(){

    char* a = malloc(8);
    
    memcpy(a-0x4, "\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff", 20);

    free(a);
    printf("%p\n", a);


    char* b = malloc(8);
    char* c = malloc(8);
    printf("%p   %p\n", b, c);
    
    return 0;
}