#include <stdio.h>

struct data {

    char file_path[4096];
    unsigned int    nbr;
} info;

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




int main(void)
{
    unsigned int    nbr;
    int triplets[4];
    int i;
    unsigned int    mag;


    i = 0;
    nbr = 1000100000;
    mag = get_magnitude(nbr);
    printf("mag is %u\n", mag);
    convert_triplets(nbr, get_magnitude(nbr), triplets);

    while (i < 4)
    {
         printf("Value of triplet %d is: %d\n", i + 1, triplets[i]);
         i++;
    }
   
    return (0);
}

