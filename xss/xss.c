#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "emscripten.h"


// emcc xss.c -g -o xss.js -sEXPORTED_FUNCTIONS=_main,_analyze -sEXPORTED_RUNTIME_METHODS=ccall,cwrap



/*
PAYLOAD:
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaadocument.write('<script type=\'text/javascript\'>alert(\'Hacked!\')</script>')
*/


void analyze(char* input) {

    //char command[] = "document.write('Done with analysis!')";
    char command[] = "document.getElementById('output').innerHTML = 'Done with analysis!'";
    char text[32];

    strcpy(text, input); // buffer overflow

    // For debugging
    // printf("Command: 0x%x\n", command);
    // printf("Text   : 0x%x\n", text);

    // Write to DOM to let user know process is done
    emscripten_run_script(command);

}



int main(){
    
    return 0;
}