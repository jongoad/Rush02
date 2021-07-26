//THIS FILE IS FOR TESTING STUFF

//HEADERS AND PROTOTYPES HERE
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

//Need a struct to start passing information around
struct data {

    char file_path[4096];
    unsigned int    nbr;
} info;



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
    fd = open(info.file_path, O_RDONLY);
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
    fd = open(info.file_path, O_RDONLY);

    //Read size bytes from the file to our string.
    //Returns above 0 are the number of bytes read
    status = read(fd, str, size);
   
    //Null terminate the string at last byte
    str[size] = '\0';

    //Close the file
    status = close(fd);

    //Need to handle error reporting. We can return a null string on error. Might need to split open and close into seperate functions that return fd
    if (status == -1 || fd == -1)
        return (NULL);
    else
        return (str);
}

//This should be moved into FT_BASIC
void    ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

//This function converts the string passed to an integer.
int   is_valid_atoi(char *argv)
{
    unsigned long   nbr;
    int i;

    i = 0;
    nbr = 0;
    while (argv[i] >= '0' && argv[i] <= '9')
    {
        nbr = (nbr * 10) + (argv[i] - '0');
        i++;
        //If number is larger then maximum size of unsigned int return error
        if (nbr > 4294967295)
            return (-1);
    }
    //If first char of the number array is not a number, or the last char checked is not the null char we can return an error
    if (argv[0] < '0' || argv[0] > '9' || argv[i] != '\0')
        return (-1);
    //If number is valid set info.nbr and return 1
    else
    {
        info.nbr = nbr;
        return (1);
    }
}

//This function checks the command line input, and checks for a new dictionary being passed
int arg_check(int argc,char **argv)
{
    int nbr_check;
    int dict_check;


    //If 2 arguments are passed we need to check number and dict
    //The path for the new dict is passed into the info struct
    if (argc == 3)
    {
        nbr_check = is_valid_atoi(argv[2]);
        ft_strcpy(info.file_path, argv[1]);
        dict_check = 1;
    }
    //If only one argument is passed we simply check the number and the original dict
    else if (argc == 2)
    {
        nbr_check = is_valid_atoi(argv[1]);
        ft_strcpy(info.file_path, "numbers.dict");
        dict_check = 1;
    }
    //If there is no number or dict passed we return an error
    else if (argc == 1)
        return (-1);
    
    //Return -1 for number error
    if (nbr_check == -1)
        return (-1);
    //Return -2 for dict error
    else if (dict_check == -1)
        return (-2);
    //Return 1 if there is a valid reference dictionary and number
    else if (dict_check == 1 && argc == 3)
        return (1);
    //Return 0 if there is only a number and original dictionary is valid
    else if (dict_check == 1 && argc == 2)
        return (0);
    else
        return (-1);
}

//If there is an error, arg_check will return -1
//If the number is valid and there is only one argument, it will return 0
//If the number is valid and there are 2 arguments, it will return 1
int main(int argc, char **argv)
{
    int arg_status;
    char *str;

    //Call a function to check the validity of arguments, as well as telling us if we need to check a command line dictionary
    arg_status = arg_check(argc, argv);
    str = file_to_string();
    if (arg_status == -2)
        printf("Dict Error\n");
    else if (arg_status == -1)
        printf("Error\n");
    else if (arg_status == 0)
        printf("Valid number: %u\n", info.nbr);
    else if(arg_status == 1)
        printf("Valid number: %u\nReference dictionary path is now: %s\n", info.nbr, info.file_path);
    printf("Here is the current dictionary:\n %s", str);
    return (0);    
}