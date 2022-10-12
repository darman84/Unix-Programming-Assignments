#include <stdio.h>     // for sscanf, fprintf, perror
#include <stdint.h>    // for int32_t
#include <inttypes.h>  // for SCNd32, PRId32
#include <assert.h>    // for assert
#include "sr.h"

/// include files are not complete. include the appropriate files


// Get all the fields of student record sr from stdin
// Put the record in the appropriate offset of the file described by fd
void
put(int32_t fd)
{
	sr s;

	printf("Enter the student name: ");	
	
	// WRITE THE CODE to read the name from stdin
	// store it in s.name
	// use fgets()
	// fgets doesnt remove newline. replace '\n' with '\0' in s.name. strlen() will be useful
	

	printf("Enter the student id: ");
	//
	// WRITE THE CODE to read student id from stdin
	// store it in s.id
	

	printf("Enter the record index: ");
	//
	// WRITE THE CODE to read record index from stdin
	// store it in s.index

	// WRITE THE CODE to seek to the appropriate offset in fd (lseek(), sizeof() will be useful)
	

	// WRITE THE CODE to write record s to fd
	
}

// read the student record stored at position index in fd
void
get(int32_t fd)
{
	sr s;
	int32_t index;

	printf("Enter the record index: ");
	//
	// WRITE THE CODE to get record index from stdin and store in it index
	
    // WRITE THE CODE to seek to the appropriate offset in fd
    

    // WRITE THE CODE to read record s from fd


	printf("Student name %s \n", s.name);	
	printf("Student id: %d \n", s.sid);
	printf("Record index: %d \n", s.index);

	assert(index == s.index);
}

