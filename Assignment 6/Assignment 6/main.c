#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

void reverseArray(uint32_t src[], int32_t size);
void reverseArrayNew(uint32_t src[], int32_t size);

int main()
{
    int32_t size = 5;
    uint32_t numbers [] = {9,5,2,14,68};
    reverseArrayNew(numbers, size);
    return 0;
}


void reverseArray(uint32_t src[], int32_t size)
{
    int32_t i;
    int32_t temp = 0;
    for (i=0; i<(size/2);i++)
    {
        temp = src[size-i-1];
        src[size-i-1]=src[i];
        src[i]=temp;
    }

    //test, delete later
    int j;
    for (j=0;j<size;j++)
    {
        printf("%d ", src[j]);
    }

}

void reverseArrayNew(uint32_t src[], int32_t size)
{
    int i = 0;
    while (i < size-1-i)
    {
        src[i] ^= src[size-1-i];
        src[size-1-i] ^= src[i];
        src[i] ^= src[size-1-i];
        ++i;
    }
        int j;
    for (j=0;j<size;j++)
    {
        printf("%d ", src[j]);
    }

}
