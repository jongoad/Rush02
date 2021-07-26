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
