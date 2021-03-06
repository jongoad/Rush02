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
//extern int errno;


// Function to find the size of the file so we can malloc the correct size memory block.
int get_file_size(fd)
{
    int count; //File size counter
    int fd; //File descriptor
    int status; //Loop control using return value from read, also failure status of whole function
    char    c; //Temporary buffer to hold read bytes in local memory

    count = 0;
    status = 1;

    //Create the memory location for buffer
    c = (char)malloc(sizeof(char));

    //Open the file
    fd = open("numbers.dict", O_RDONLY);
    //Read one byte at a time till we hit the EOF char or return an error
    while (status > 0 && fd != -1)
    {
        status = read(fd, c, 1);
        if (status > 0)
            count++;
    }
    //Free the allocated memory
    free(c);

    //Close the file
    status = close(fd);

    //Return error or size of file
    if (status == -1 || fd == -1)
        return (-1);
    else
        return (count);
}

//Function to read the file and store it in a malloc-ed char array
char *file_to_string(void)
{
   //Create an int that will hold the file descriptor
    int fd;
    int status;
    char *str;

    status = 1;

    //Allocate a memory block large enough to hold read output, including an extra byte for null terminator.
    str = (char *)malloc(sizeof(char) * (get_file_size() + 1));
    //Open the file
    fd = open("numbers.dict", O_RDONLY);

    //Start reading the file 1 byte at a time until the return from read() is 0 (end of file) or an error is returned (-1)
    //Returns above 0 are the number of bytes read
    while (status > 0 && fd != -1)
    {
        status = read(fd, str, 1);
        str++;
    }

    //Close the file
    status = close(fd);

    //Need to handle error reporting. We can return a null string on error. Might need to split open and close into seperate functions that return fd
    if (status == -1 || fd == -1)
        return (NULL);
    else
        return (str);
}

int parse_main()
{

}