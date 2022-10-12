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
    char* temp;
    char* temp2;
    char* temp3;
    int length;

    temp = src;
    temp2 = src;
    length = 0;

    // Find the length of source (src) string
    // Use pointers and pointer arithmetic.
    // Do not treat src.
    while (*temp != '\0')
    {
        length++;
        temp++;
    }

    // allocate memory for destination (*dst) string
    *dst = (char*)malloc(sizeof(char) * 95); //95 characters long is max
    
    // if memory allocation fails print appropriate error message using perror()
    // and return
    if (!*dst)
    {
        perror("Cannot allocate memory");
        return EXIT_FAILURE;
    }

    // copy src to *dst.
    // Use pointers and pointer arithmetic.
    // Do not treat src and *dst as arrays.
    temp3 = *dst;
    while (*temp2 != '\0')
    {
        *temp3 = *temp2;
        temp2++;
        temp3++;
    }
    *temp3 = '\0';

#if DEBUG
    printf("src length: %d \n", length);
    printf("str: %s \n", src);
    printf("str: %s \n", *dst);
#endif
    return;
}
