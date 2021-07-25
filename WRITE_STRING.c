



//First we need to malloc an array big enough to hold any strings they could thow at us
//20 x 1024 should be fine


//Function to find keys and return strings
char *get_string(unsigned int key, )
{

}

void    write_output(char **output, char *string, unsigned int key)
{
    int i;
    char *str_temp;

    str_temp = get_string();
    i = 0;
    while (string[i] != '0')
    {
        *(output + 1) = get_stringstring[i];
        output++;
        i++;
    }
    *(output) = ' ';
}

//Function to write triplets
unsigned int    write_triplets(char **output, int triplet_value, unsigned int mag)
{
    // Need to pass in the digits from out triplet one at time
    //First one is triplet_value div 100
    //Second one is result of first div 10
    //Third is result of second mod 10

    mag = mag / 1000;
    return (mag);
}







//Function to iterate through triplet array and call for prints based on order of magnitude
char   *control_triplets(int *triplets, unsigned int mag)
{
    int i;
    char *output;
    int triplet_value;

    output = (char *)malloc(sizeof(char) * ((20) * (1024) + 1));
    i = 0;
    while (i < 4 && mag != 0)
    {
        triplet_value = triplets[i];
        mag = write_triplets(&output, triplet_value, mag);
        if (mag == 1)
        //This needs to stop more writing, so write then set magvalue = 0
        i++;
    }
    return (output);
}
