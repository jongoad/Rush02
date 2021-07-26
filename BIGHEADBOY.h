#ifndef BIGHEADBOY_H
# define BIGHEADBOY_H


# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/errno.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>


//CHECK THESE
# define DICT_REF "resources/numbersEN.dict"
# define ERROR "Error\n"
# define DICT_ERROR "Dict Error\n"

//STRUCTS HERE



void    ft_putchar(char c);
void    ft_putstr(char *str);
void    ft_strcpy(char *dest, char *src);
int ft_strlen(char *str);

int get_file_size(void);
char *file_to_string(void);

int   is_valid_atoi(char *argv);
int arg_check(int argc,char **argv);
char *remove_empty_lines(char *str);

unsigned int    get_magnitude(unsigned int nbr);
void    convert_triplets(unsigned int  nbr, unsigned int   mag, int *triplets);
void    control_triplets(void);






#endif