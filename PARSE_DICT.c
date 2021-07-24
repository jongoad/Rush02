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

/****************************************************************************************************************************/

//Not sure if we need/want to use this? I think it stores the current error code to be returned
extern int errno;

int parse_main()
{
 
}

// Function to find the size of the file so we can malloc the correct size memory block.
int get_file_size(int fd)
{
    int count; //File size counter
    int fd; //File descriptor
    int read_status; //Loop control usinf return value from read
    char    c; //Temporary buffer to hold read bytes in local memory

    count = 0;
    read_status = 1;

    //Create the memory location for buffer
    c = (char)malloc(sizeof(char));

    //Open the file
    fd = open("numbers.dict", O_RDONLY);

    //Read one byte at a time till we hit the EOF char or return an error
    while (read_status > 0)
    {
        read_status = read(fd, c, 1);
        if (read_status > 0)
            count++;
    }
    //Free the allocated memory
    free(c);

    //Return error or size of file
    if (read_status == -1)
        return (-1);
    else
        return (count);
}

//Function to read the file and store it in a malloc-ed char array
char *file_to_string(void)
{
   //Create an int that will hold the file descriptor
    int fd;
    int read_status;
    char *str;

    read_status = 1;

    //Allocate a memory block large enough to hold read output, including an extra byte for null terminator.
    str = (char *)malloc(sizeof(char) * (get_file_size() + 1));
    //Open the file
    fd = open("numbers.dict", O_RDONLY);

    //Start reading the file 1 byte at a time until the return from read() is 0 (end of file) or an error is returned (-1)
    //Returns above 0 are the number of bytes read
    while (read_status > 0)
    {
        read_status = read(fd, str, 1);
    }
    //Free the allocated memory
    free(str);
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