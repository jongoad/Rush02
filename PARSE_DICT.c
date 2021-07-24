//This file contains the required functions to parse our dictionary
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
//We need to go over the file line by line check rules with a atoi-like function
//When ever a new line character is reached, we need to reset the atoi-like function to its starting state

//If open() return -1 it is an error and errno to should be set to indicate error
//Open returns a file descriptor
/*
Syntax in C language 
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  
int open (const char* Path, int flags [, int mode ]);

File descriptor is the return value from open()

By default the return value is 3.

This is because 0, 1, and 2 are reserved.
- 0 is read
- 1 is write
- 2 is write to error
*/


//WHAT THE FUCK IS THIS ?
extern int errno;

int parse_main()
{
    //Create an int that will holdthe file descriptor
    //Declare FILE pointer ??
    int fd;

    fd = open("numbers.dict", O_RDONLY);


    close(fd);
}





// C program to illustrate close system Call
#include<stdio.h>
#include <fcntl.h>
int main()
{
    int fd1 = open("foo.txt", O_RDONLY);
    if (fd1 < 0)
    {
        perror("c1");
        exit(1);
    }
    printf("opened the fd = % d\n", fd1);
     
    // Using close system Call
    if (close(fd1) < 0)
    {
        perror("c1");
        exit(1);
    }
    printf("closed the fd.\n");
}

// C program to illustrate
// read system Call
#include<stdio.h>
#include <fcntl.h>
int main()
{
int fd, sz;
char *c = (char *) calloc(100, sizeof(char));
 
fd = open("foo.txt", O_RDONLY);
if (fd < 0) { perror("r1"); exit(1); }
 
sz = read(fd, c, 10);
printf("called read(% d, c, 10). returned that"
        " %d bytes were read.\n", fd, sz);
c[sz] = '\0';
printf("Those bytes are as follows: % s\n", c);
}

// C program to illustrate
// open system call
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;
int main()
{    
    // if file does not have in directory
    // then file foo.txt is created.
    int fd = open("foo.txt", O_RDONLY | O_CREATE);
     
    printf("fd = %d/n", fd);
     
    if (fd ==-1)
    {
        // print which type of error have in a code
        printf("Error Number % d\n", errno);
         
        // print program detail "Success or failure"
        perror("Program");                
    }
    return 0;
}