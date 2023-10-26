#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "emscripten.h"


// emcc complex.c -g -o complex.js -sEXPORTED_FUNCTIONS=_main,_func -sEXPORTED_RUNTIME_METHODS=ccall,cwrap --js-library ./lib.js


extern void external_js_function();


int func(int x) {
    return x+1;

}

void run_js_code() {
    emscripten_run_script("console.log('Can call JS code!')");
}

int main(){
    
    char* x = (char*) malloc(24);
    strcpy(x, "testing123");
    printf("Location of str in memory: %x\n", x);

    printf("Ensure can call C from JS: 11 == %d\n", func(10));

    // Can still do arbitrary writes and reads
    // Note that can't write to first few bytes since
    // glue code does integrity check on that
    *(char*)0x20 = 'x';

    // Test calling JS
    run_js_code();

    // Test external JS API
    external_js_function();
    

    return 0;
}