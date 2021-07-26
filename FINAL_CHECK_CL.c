/***************************************************************************************************/
/*          CHECK COMMAND LINE INPUT, GET PROPER DICTIONARY, CONVERT INPUT NUMBER TO INT           */
/***************************************************************************************************/
#include <BIGHEADBOY.h>

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