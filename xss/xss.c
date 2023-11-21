#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "emscripten.h"


// emcc xss.c -g -o xss.js -sEXPORTED_FUNCTIONS=_main,_analyze -sEXPORTED_RUNTIME_METHODS=ccall,cwrap



/*
PAYLOAD:
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaadocument.write('<script type=\'text/javascript\'>alert(\'XSS!\')</script>')
*/


void analyze(char* input) {

    char command[] = "document.getElementById('output').innerHTML = 'Done with analysis!'";
    char text[32];

    strcpy(text, input); // buffer overflow

    // For debugging
    // printf("Command: 0x%x\n", command);
    // printf("Text   : 0x%x\n", text);

    // Write to DOM
    emscripten_run_script(command);

}



int main(){
    
    return 0;
}