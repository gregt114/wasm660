#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "emscripten.h"


// emcc complex.c -g -o complex.js -sEXPORTED_FUNCTIONS=_main,_vuln -sEXPORTED_RUNTIME_METHODS=ccall,cwrap


// Function that is vulnerable to buffer overflow
void vuln(char* string) {

    // Allocate space to copy string to
    char* target = (char*) malloc(68072);
    printf("Target string: %x\n", target);

    // copy string into memory
    strcpy(target, string); 

    // Format string test
    printf(string);
}



int main(){

    // Allocate some memory
    char* x = (char*) malloc(16);
    char* ip = (char*) malloc(16);
    strcpy(ip, "127.0.0.1");

    printf("Original: 0x%x\n", x);
    printf("IP:       0x%x\n", ip);

    
    // Do some operations on x, then free
    free(x);

    int y = 0;
    printf("1234567890%n\n", &y);
    printf("Y == %d\n", y);
    
    
    return 0;
}