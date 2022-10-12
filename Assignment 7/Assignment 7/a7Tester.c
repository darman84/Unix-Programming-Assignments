#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

#define SIZE 20
#define DEBUG 0

extern void strCopy(char*, char**);

int main(int argc, char **argv) 
{
  char* dest = NULL;

	if (argc < 2){
		printf("Usage: a6Tester <string> \n");
		return EXIT_FAILURE;
	}

#if DEBUG
  printf("str: %s \n", argv[1]);
#endif
	
	strCopy(argv[1], &dest);
	
	if (!dest)
	{
		printf("balls");
		return EXIT_FAILURE;
	}
	
	if (strcmp(argv[1], dest))
		printf("strCopy FAILED \n");
	else
		printf("strCopy Successful \n");
  return EXIT_SUCCESS;
}

