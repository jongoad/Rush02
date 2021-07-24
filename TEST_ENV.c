//THIS FILE IS FOR TESTING STUFF

//HEADERS AND PROTOTYPES HERE
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

// Function to find the size of the file so we can malloc the correct size memory block.
int get_file_size(void)
{
    int count; //File size counter
    int fd; //File descriptor
    int status; //Loop control using return value from read, also failure status of whole function
    char    *c; //Temporary buffer to hold read bytes in local memory

    count = 0;
    status = 1;

    //Create the memory location for buffer
    c = (char *)malloc(sizeof(char) + 1);

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
    int size;

    status = 1;

    //Allocate a memory block large enough to hold read output, including an extra byte for null terminator.
    size = get_file_size();
    str = (char *)malloc(sizeof(char) * (size + 1));

    //Open the file
    fd = open("numbers.dict", O_RDONLY);

    //Start reading the file 1 byte at a time until the return from read() is 0 (end of file) or an error is returned (-1)
    //Returns above 0 are the number of bytes read
    status = read(fd, str, size);
   
    //Null terminate the string
    str[size] = '\0';

    //Close the file
    status = close(fd);

    //Need to handle error reporting. We can return a null string on error. Might need to split open and close into seperate functions that return fd
    if (status == -1 || fd == -1)
        return (NULL);
    else
        return (str);
}

int main(void)
{
    char *str;

    str = file_to_string();

    printf("%s", str);
    return (0);
}