//THIS FILE IS FOR TESTING STUFF

//HEADERS AND PROTOTYPES HERE
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

//TEMP UNTIL HEADER IS MADE
#include "FT_BASIC.c"
int	check_dict(char *str);

//STRUCTS
struct data {

    char file_path[4096];
    unsigned int    nbr;
    int triplets[4];
    unsigned int mag;
    char *dict_input;
} info;

struct	s_entries
{
	int		size;
	int 	keys[32];
	char	*strs[32];
} dict;


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


/***************************************************************************************************/
/*          CHECK COMMAND LINE INPUT, GET PROPER DICTIONARY, CONVERT INPUT NUMBER TO INT           */
/***************************************************************************************************/

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

    //If 2 arguments are passed we need to check number and dict
    //The path for the new dict is passed into the info struct
    if (argc == 3)
    {
        nbr_check = is_valid_atoi(argv[2]);
        ft_strcpy(info.file_path, argv[1]);
    }
    //If only one argument is passed we simply check the number and the original dict
    else if (argc == 2)
    {
        nbr_check = is_valid_atoi(argv[1]);
        ft_strcpy(info.file_path, "numbers.dict");
    }
    //If there is no number or dict passed we return an error
    else if (argc == 1)
        return (-1);
    return (nbr_check);
}

//This function checks that the current dictionary is valid
int confirm_valid_dict(void)
{
    int dict_check;

    dict_check = check_dict(info.dict_input);
    return (dict_check);
}

/***************************************************************************************************/
/*                GET ORDER OF MAGNITUDE AND CONVERT NUMBER TO AN ARRAY OF TRIPLETS                */
/***************************************************************************************************/

//Function to get magnitude total of number
unsigned int    get_magnitude(unsigned int nbr)
{
    unsigned int    mag;

    mag = 1;
    if (nbr < 1000)
    {
        mag = 1;
        return (mag);
    }
    while (nbr > 999)
    {
        mag = mag * 1000;
        nbr = nbr / 1000;
    }
    return (mag);
}

//Function to convert the number into triplets and write to an array
void    convert_triplets(unsigned int  nbr, unsigned int   mag, int *triplets)
{
    int i;
    unsigned int    nbr_store;

    nbr_store = nbr;
    i = 0;
    while (mag >= 1)
    {
        if (nbr_store < 1000)
            {
                triplets[i] =  (nbr / mag);
                return;
            }
        else 
            triplets[i] = (nbr / mag);
        nbr = (nbr % mag);
        mag = mag / 1000;
        triplets++;
    }
}

//Driver function for triplets and magnitude
void    control_triplets(void)
{
    int i;

    i = 0;

    info.mag = get_magnitude(info.nbr);
    convert_triplets(info.nbr, info.mag, info.triplets);

    //FOR TESTING -- TO BE REMOVED
    printf("mag is %u\n", info.mag);
    
    while (i < 4)
    {
         printf("Value of triplet %d is: %d\n", i + 1, info.triplets[i]);
         i++;
    }
    return;
}


/***************************************************************************************************/
/*                                CHECK IF DICTIONARY IS VALID                                     */
/***************************************************************************************************/

int	is_key_valid(char *str)
{
	int	i;
	int	has_number;

	i = 0;
	has_number = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		has_number = 1;
		i++;
	}
	while (str[i] == 32)
		i++;
	if (str[i] != ':' || has_number == 0)
		return (0);
	return (i);
}

int	is_string_valid(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != 10 && str[i])
		if (str[i] < 32)
			return (0);
	if (str[i] == 10)
		return (i);
	else
		return (0);
}

int	is_line_valid(char *str)
{
	int	i;

	i = -1;
	while (str[++i] == 32 || str[i] == 10)
		if (str[i] == 10)
			return (i + 1);
	if (is_key_valid(&str[i]) == 0)
		return (0);
	else
		i += is_key_valid(str);
	if (is_string_valid(&str[i]) == 0)
		return (0);
	else
		i += is_string_valid(&str[i]);
	if (i > 0)
		return (i + 1);
	return (0);
}

int	check_dict(char *str)
{
	int	i;
	int	line_count;
	int	line_len;

	i = 0;
	line_count = 0;
	line_len = 0;
	while (str[i])
	{
		line_len = is_line_valid(&str[i]);
		if (line_len == 0)
			return (0);
		if (line_len > 2)
			line_count++;
		i += line_len;
	}
	return (line_count);
}


/***************************************************************************************************/
/*                                   FORMAT STRING BEFORE SPLITTING                                */
/***************************************************************************************************/

int	is_line_empty(char *str)
{
	int	i;
	int	is_empty;

	i = 0;
	is_empty = 1;
	while (str[i] != 10)
	{
		if (str[i] != 32)
			is_empty = 0;
		i++;
	}
	if (i == 0)
		return (1);
	if (is_empty == 1)
		return (i + 1);
	else
		return (0);
}

char *trim_lines(char *str)
{
	int		i;
	int		spaces;
	char	*no_empty;

	i = -1;
	spaces = 0;
	while (str[++i])
	{
		while (str[i] == 10 && is_line_empty(&str[i + 1]))
		{	
			spaces += is_line_empty(&str[i + 1]);
			i++;
		}
	}
	no_empty = (char *)malloc((ft_strlen(str) - spaces + 1) * sizeof(char));
	i = -1;
	spaces = 0;
	while (str[++i + spaces])
	{
		while (str[i] == 10 && is_line_empty(&str[i + spaces + 1]))
			spaces += is_line_empty(&str[i + spaces + 1]);
		no_empty[i] = str[i + spaces];
	}
	return (no_empty);
}

char	*trim_spaces(char *str)
{
	int		i;
	int		j;
	int		spaces;
	char	*no_spaces;

	i = -1;
	spaces = 0;
	while (str[++i] && str[i] != 10)
		while (str[++i] == 32 && str[i + 1] == 32)
			spaces++;
	no_spaces = (char *)malloc(is_string_valid(str) - spaces + 1);
	i = 0;
	j = 0;
	while (str[i] && str[i] != 10)
	{
		while (str[i] == 32 && str[i + 1] == 32)
			i++;
		no_spaces[j] = str[i];
		i++;
		j++;
	}
	no_spaces[j] = 0;
	return (no_spaces);
}

int	get_key(char **str)
{
	int	i;
	int	value;
	int	sign;

	sign = 1;
	i = 0;
	value = 0;
	while (**str == 32)
		*str += 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		*str += 1;
	}
	while (**str >= '0' && **str <= '9')
	{
		value = value * 10 + **str - '0';
		*str += 1;
	}
	while (**str == 32)
		*str += 1;
	*str += 1;
	return (value);
}

char	*get_string(char **str)
{
	int		size;
	char	*cpy;

	size = 0;
	while ((**str) == 32)
		*str += 1;
	cpy = trim_spaces(*str);
	while (**str != 10)
		*str += 1;
	*str += 1;
	return (cpy);
}

/***************************************************************************************************/
/*                                  GRAB STRINGS VIA KEYS AND STORE                                */
/***************************************************************************************************/

void	fill_keys(void)
{
	int i = 0;
	while (i < 20)
	{
		dict.keys[i] = i;
		i++;
	}
	while (i < 29)
	{
		dict.keys[i] = (i - 18) * 10;
		i++;
	}
	dict.keys[29] = 1000;
	dict.keys[30] = 1000000;
	dict.keys[31] = 1000000000;
//	for (int i = 0; i < 32; i++)
	//	printf("entry #%d: '%d'\n", i, dict.keys[i]);
}

void	fill_number(int nb, char *str)
{
	int	i;
	
	i = 0;
	while (i < 32)
	{
		if (nb == 0)
		{
	//		dict.strs[i] = (char *)malloc(5 * sizeof(char));
	//		ft_strcpy (dict.strs[i], "zero");
			dict.strs[i] = (char *)malloc((ft_strlen(str + 1)) * sizeof(char));
			ft_strcpy (dict.strs[i], str);
			return ;
		}
		if (nb == dict.keys[i])
		{
			dict.strs[i] = (char *)malloc((ft_strlen(str + 1)) * sizeof(char));
			ft_strcpy (dict.strs[i], str);
			return ;
		}
		i++;
	}
}

void	parse_entries(char *str)
{
	int 	key;
	int		str_size;
	char	*entry;
	
	while (str)
	{
		key = get_key(&str);
	//		printf("The number of the entry is: '%d'\n", key);
		str_size = is_string_valid(str);
		entry = (char *)malloc((str_size + 1) * sizeof(char));
		entry = get_string(&str);
		entry[str_size] = 0;
	//		printf("The string associated is: '%s'\n\n",entry);
		if (key == 0)
			printf("entry for zero = %s\n", entry);
		fill_number(key, entry);
		if (*(str + 3) == 0)
			return ;
	}
}


/***************************************************************************************************/
/*                                  GET STRING TO PRINT AND CALL PRINT                             */
/***************************************************************************************************/

//Function to find keys and return strings
void	pull_string(int key)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (key == dict.keys[i])
		{
			ft_putstr(dict.strs[i]);
			return ;
		}
		i++;	
	}
}

//Function to write triplets
void	write_triplets(int nb)
{
    // Need to pass in the digits from out triplet one at time
    //First one is triplet_value div 100
    //Second one is result of first div 10
    //Third is result of second mod 10
	int	tens;
	
	tens = (nb % 100) / 10;
	if (nb / 100)
	{
		pull_string(nb/100);
		ft_putchar(' ');
		pull_string(100);
	}
	if (tens < 21 && nb % 100 != 0)
	{
		ft_putchar(' ');
		pull_string(nb % 100);
		return ;
	}
	else if (tens)
	{
		ft_putchar(' ');
		pull_string(tens);
	}
	if (nb % 10)
	{
		ft_putchar(' ');
		pull_string(nb % 10);
	}
}

//Function to iterate through triplet array and call for prints based on order of magnitude
void    control_print(void)
{
    int i;
    int triplet_value;
    unsigned int local_mag;

    i = 0;
    local_mag = info.mag;
    while (i < 4 && info.mag != 0)
    {
        triplet_value = info.triplets[i];
        write_triplets(triplet_value);
        if (local_mag != 1)
            {
                ft_putchar(' ');
                pull_string(local_mag);
                ft_putchar(' ');
                local_mag = (local_mag / 1000);
            }
        else if (local_mag == 1)
            break;
        i++;
    }
    return;
}



/***************************************************************************************************/
/*                                  MAIN FUNCTION                                                  */
/***************************************************************************************************/



//If there is an error, arg_check will return -1
//If the number is valid and there is only one argument, it will return 0
//If the number is valid and there are 2 arguments, it will return 1
int main(int argc, char **argv)
{
    int arg_status;
    int error_status;
    int dict_error;
  
    /***************************************************************************************************/
    arg_status = arg_check(argc, argv);
    error_status = file_to_string();
    dict_error = confirm_valid_dict();
    info.dict_input = remove_empty_lines(info.dict_input);
    
    if (dict_error == 0)
        printf("Dict Error\n");
    else if (arg_status == -1)
        printf("Error\n");

   // printf("Here is the current dictionary:\n %s", info.dict_input);
    control_triplets();

    /***************************************************************************************************/

    fill_keys();
	
	parse_entries(info.dict_input);

    control_print();
    return (0);
}
