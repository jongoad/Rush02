
//First we need to malloc an array big enough to hold any strings they could thow at us
//20 x 1024 should be fine

//Need a struct to start passing information around
struct data {
    char file_path[4096];
    unsigned int    nbr;
} info;





//Function to find keys and return strings
char *pull_string(unsigned int key)
{

}

void    write_output(char **output, unsigned int key)
{
    int i;
    char *str_temp;

    str_temp = pull_string();
    i = 0;
    while (string[i] != '0')
    {
        *(output + 1) = pull_string[i];
        output++;
        i++;
    }
    *(output) = ' ';
}



//Function to write triplets
<<<<<<< HEAD
unsigned int    write_triplets(int triplet_value);
=======
void	write_triplets(int nb)
>>>>>>> 8e0cf6b87416700d1562445015507a0eb2b32c24
{
    // Need to pass in the digits from out triplet one at time
    //First one is triplet_value div 100
    //Second one is result of first div 10
    //Third is result of second mod 10
<<<<<<< HEAD


    return (mag);
=======
	int	hundreds;
	int	tens;
	int	units;
	
	hundreds = nb / 100;
	tens = (nb % 100) / 10;
	units = nb % 10;
	if (hundreds)
	{
		pull_string(nb/100);
		pull_string(100);
	}
	if (tens < 21 && nb % 100 != 0)
	{
		pull_string(nb % 100);
		return ;
	}
	else if (tens)
		pull_string(tens);
	if (units)
		pull_string(units);
>>>>>>> 8e0cf6b87416700d1562445015507a0eb2b32c24
}

//Function to iterate through triplet array and call for prints based on order of magnitude
char   *control_triplets(int *triplets, unsigned int mag)
{
    int i;
    int triplet_value;

    i = 0;
    while (i < 4 && mag != 0)
    {
        triplet_value = triplets[i];
        write_triplets(triplet_value);
        if (mag != 1)
            {
                ft_putstr(pull_string(mag));
                ft_putchar(' ');
                mag = (mag / 1000);
            }
        else if (mag == 1)
            break;
        i++;
    }
    return (p_output);
}