/***************************************************************************************************/
/*         READ THE PROPER DICTIONARY AND CONVERT IT TO A CHAR STRING WITHOUT EXTRA LINES          */
/***************************************************************************************************/

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
int file_to_string(void)
{
   //Create an int that will hold the file descriptor
    int fd;
    int status;
    //char *str;
    int size;

    status = 1;

    //Allocate a memory block large enough to hold read output, including an extra byte for null terminator.
    size = get_file_size();
    info.dict_input = (char *)malloc(sizeof(char) * (size + 1));

    //Open the file
    fd = open(info.file_path, O_RDONLY);

    //Read size bytes from the file to our string.
    //Returns above 0 are the number of bytes read
    status = read(fd, info.dict_input, size);
   
    //Null terminate the string at last byte
    info.dict_input[size] = '\0';

    //Close the file
    status = close(fd);
    //Need to handle error reporting. We can return a null string on error. Might need to split open and close into seperate functions that return fd
    if (status == -1 || fd == -1)
       return (-1);
   else
        return (1);
}

//This function is to strip away any entire empty lines
char *remove_empty_lines(char *str)
{
    int i;
    int j;
    char *temp_str;
    int size;
    int found_line;

    size = get_file_size();
    temp_str = (char *)malloc(sizeof(char) * (size + 1));
    found_line = 0;
    i = 0;
    while (str[i] != '\0')
    {
        j = 0;
        temp_str[i] = str[i + found_line];
        //While consecutive white space, if we hit the newline char we need to start copying again from new location
        while(str[i + j + found_line] == ' ')
        {
            j++;
        }
        if (str[i + j + found_line] == '\n')
        {
            if (str[i + j + found_line + 1] == '\n')
                str[i + j + found_line + 1] = ' ';
            found_line = j + found_line;
        }
        i++;
    }
    return (temp_str);
}