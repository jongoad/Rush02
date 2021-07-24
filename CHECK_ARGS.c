//This file contains the required functions to check if the command line input is valid



int dict_check

//This function converts the string passed to an integer.
//If the number is negative we can return a value outside of unsigned int range
unsigned long   unsign_atoi(char *argv)
{
    int nbr;
    int i;

    i = 0;
    while (argv[i] >= '0' && argv[i] <= '9')
    {
        nbr = (nbr * 10) + (argv[i] - '0');
        i++;
    }
    if (argv[i] < '0' || argv[i] > '9' || nbr > 4294967295)
        return (5000000000);
    else 
        return (nbr);
}

//If the number is valid return is 1
//If the number is not valid, return is -1
int is_arg_nbr_valid(char *argv)
{
    unsigned long   nbr;

    nbr = unsign_atoi(argv);
    if (nbr > 4294967295)
        return (-1);
    else 
        return (1);
}

//Return -2 if there is a dict error
//Return -1 if there is an number error, 
//Return 0 if nbr is valid and there is no reference dict passed
//Return 1 if nbr is valid and there is a reference dict passed
int arg_check(int argc,char **argv)
{
    int nbr_check;
    int dict_check;

    //Double check return values for check_dict

    //If 2 arguments are passed we need to check number and dict
    //Also the position of number is shifted by 1 address
    if (argc == 3)
    {
        nbr_check = is_arg_nbr_valid(argv[2]);
        dict_check = check_dict(argv[1]);
    }
    //If only one argument is passed we simply check the number
    else if (argc == 2)
    {
        nbr_check = is_arg_nbr_valid(argv[1]);
        dict_check = 0;
    }
    else if (argc == 1)
        return (-1);

    //Return -1 for number error
    if (nbr_check == -1)
        return (-1);
    //Return -2 for dict error
    else if (dict_check == -1)
        return (-2);
    //Return 1 if there is a valid reference dictionary and number
    else if (dict_check == 1)
        return (1);
    //Return 0 if there is only a number
    else
        return (0);
}



//If there is an error, arg_check will return -1
//If the number is valid and there is only one argument, it will return 0
//If the number is valid and there are 2 arguments, it will return 1











int main(int argc, char **argv)
{
    int arg_status;
    //Call a function to check the validity of arguments, as well as telling us if we need to check a command line dictionary
    arg_status = arg_check(argc, argv);
    if (arg_status == -2)
        printf("Dict Error\n");
    else if (arg_status == -1)
        printf("Error\n");
    else if (arg_status == 0)
        printf("Valid number, no reference dict\n");
    else if(arg_status == 1)
        printf("Valid number, reference dict is: %s\n", argv[1]);

    return (0);    
}