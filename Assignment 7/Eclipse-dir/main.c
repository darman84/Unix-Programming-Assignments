#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define DEBUG 0

/*
 * This function copies src string to *dst
 * memory for *dst should be allocated
*/
void strCopy(char* src, char** dst)
{
        // define required variables

        // Find the length of source (src) string
        // Use pointers and pointer arithmetic.
        // Do not treat src.

        // allocate memory for destination (*dst) string

        // if memory allocation fails print appropriate error message using perror()
        // and return

        // copy src to *dst.
        // Use pointers and pointer arithmetic.
        // Do not treat src and *dst as arrays.

#if DEBUG
        printf("str: %s \n", str);
        printf("str: %s \n", *dst);
#endif

        return;
}

int main()
{
	char* str1 = "Europe";
	char* str2 = "Asia";


	return 0;
}
