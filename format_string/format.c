#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "emscripten.h"


// emcc format.c -g -o format.js -sEXPORTED_FUNCTIONS=_main,_vuln -sEXPORTED_RUNTIME_METHODS=ccall,cwrap


// %p leaks seem to leak address starting at 0x0
// bc the "emscgT" string is leaked from memory
//
// It looks like %n is disabled since it generates an out of bounds error
// for many different strings
void vuln(char* string) {

    char arr[] = "aaaaaaaa";
    printf("Stack address: 0x%p\n", arr);

    printf(string);
    printf("\n");
}



int main(){

    return 0;
}