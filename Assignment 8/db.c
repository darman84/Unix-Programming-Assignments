#include <stdio.h>     // for sscanf, fprintf, perror
#include <stdint.h>    // for int32_t
#include <inttypes.h>  // for SCNd32, PRId32
#include <assert.h>    // for assert
#include <string.h>    // for strlen, strcpy
#include <sys/types.h> // for lseek
#include <unistd.h>    // for lseek
#include "sr.h"

/// include files are not complete. include the appropriate files
#define BUFFSIZE 30

// Get all the fields of student record sr from stdin
// Put the record in the appropriate offset of the file described by fd
void
put(int32_t fd)
{
	sr s;
  char buff[BUFFSIZE];  // buffer used to store the c-string in sr.h
  int buff2;            // buffer used to store the id and index in sr.h
  int seekLocation;     // DEBUG: used to see where lseek has just seeked to
  int bytesWritten;     // DEBUG: used to see how many bytes were just written to the file

	printf("Enter the student name: ");	
	
	// WRITE THE CODE to read the name from stdin
	// store it in s.name
	// use fgets()
	// fgets doesnt remove newline. replace '\n' with '\0' in s.name. strlen() will be useful
   fgets(buff, BUFFSIZE, stdin);      // store user input from stdin in buff
   if(buff[strlen(buff) - 1] == '\n')
   {
     buff[strlen(buff) - 1] = '\0';  // replace \n with \0 if \n exists at the end of the string
     strcpy(s.name, buff);
   }
   else
   {
     strcpy(s.name, buff);           // simply copy the string to the struct if there is no \n
   }


	printf("Enter the student id: ");
	//
	// WRITE THE CODE to read student id from stdin
	// store it in s.id
  // STOI
  scanf("%d", &buff2);
  s.sid = buff2;
  
 

	printf("Enter the record index: ");
	//
	// WRITE THE CODE to read record index from stdin
	// store it in s.index
  scanf("%d", &buff2);
  s.index = buff2;
  
	// WRITE THE CODE to seek to the appropriate offset in fd (lseek(), sizeof() will be useful)
  seekLocation = lseek(fd, sizeof(s)*buff2, SEEK_SET);
  // DEBUG BELOW: see where in the file is being seeked to
  // printf("lseek result =%d\n", seekLocation);


	// WRITE THE CODE to write record s to fd
  bytesWritten = write(fd, &s, sizeof(s));
  // DEBUG BELOW: see how many bytes were written
  // printf("bytesWritten=%d\n", bytesWritten); 

}

// read the student record stored at position index in fd
void
get(int32_t fd)
{
	sr s;
	int32_t index;
  int readSr;    // used to store the number of bytes read from sr

	printf("Enter the record index: ");
	//
	// WRITE THE CODE to get record index from stdin and store in it index
	scanf("%d", &index);
    // WRITE THE CODE to seek to the appropriate offset in fd
  lseek(fd, sizeof(s)*index, SEEK_SET);

    // WRITE THE CODE to read record s from fd
  readSr = read(fd, &s, sizeof(s));       // store the number of bytes read

  // printf("Bytes read: %d\n", readSr);  // debug, checking how many bytes were read
	printf("Student name: %s \n", s.name);	
	printf("Student id: %d \n", s.sid);
	printf("Record index: %d \n", s.index);
  // printf("local index: %d \n", index); // debug, checking local index

	assert(index == s.index);
}

