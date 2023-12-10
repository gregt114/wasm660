
#include <stdio.h>
#include <stdlib.h>


char* vuln(char* msg) {

	char array1[] = "AAAAAAAA";
	char array2[] = "BBBBBBBB";

	char* resp = (char *) malloc(256);
	
	sprintf(resp, msg);

	return resp;
}

int main() {

	char* str = vuln("%100$x");

	printf("{\"response\": \"%s\"}\n", str);

}
