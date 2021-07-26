
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
unsigned int    write_triplets(int triplet_value);
{
    // Need to pass in the digits from out triplet one at time
    //First one is triplet_value div 100
    //Second one is result of first div 10
    //Third is result of second mod 10


    return (mag);
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