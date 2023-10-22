#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// emcc -g -o complex.js complex.c



int main(){
    
    char* x = (char*) malloc(24);
    strcpy(x, "testing123");
    printf("val: %x\n", x);

    // Can still do arbitrary writes and reads
    // Note that can't write to first few bytes since
    // glue code does integrity check on that
    *(char*)0x20 = 'x';

    return 0;
}