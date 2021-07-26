
//First we need to malloc an array big enough to hold any strings they could thow at us
//20 x 1024 should be fine

//Need a struct to start passing information around
struct data {
    char file_path[4096];
    unsigned int    nbr;
} info;





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
int	write_triplets(int nb)
{
	if (nb / 100)
	{
		pull_string(nb/100);
		ft_putchar(' ');
		pull_string(100);
	}
	if (nb % 100 < 21 && nb % 100 > 0)
	{
		ft_putchar(' ');
		pull_string(nb % 100);
		return (nb);
	}
	else if (nb % 100 > 0)
	{
		ft_putchar(' ');
		pull_string(nb % 100 - nb % 10);
	}
	if (nb % 10)
	{
		ft_putchar(' ');
		pull_string(nb % 10);
	}
	return (nb);
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
