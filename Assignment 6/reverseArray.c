#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

void reverseArray(uint32_t src[], int32_t size);


void reverseArray(uint32_t src[], int32_t size)
{
    int i = 0;
    while (i < size-1-i)
    {
    	src[i] ^= src[size-1-i];
		src[size-1-i] ^= src[i];
		src[i] ^= src[size-1-i];
		++i;
	}
	
}
