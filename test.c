#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// emcc test.c -g -o test.js -sEXPORTED_FUNCTIONS=_func,_g,_main -sEXPORTED_RUNTIME_METHODS=ccall,cwrap
// emcc test.c -g -o test.js -sEXPORTED_FUNCTIONS=_func,_g,_main

// Minimal:
// emcc -g -s WASM=1 -s SIDE_MODULE=1 -o test.wasm test.c

// fn + shift + f5 for edge since it will cache stuff

int func(int x) {
    return x*x;
}

char* g() {
    char* src = (char *) malloc(20);
    strcpy(src, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaapoopyscoopyaaaaaaa");

    char* dest = (char *) malloc(10);

    strcpy(dest, src);
    printf("%s\n", dest);
    return dest;
}

int main(){

    g();
    return 0;
}