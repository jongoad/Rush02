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
int file_to_string(void);
char *remove_empty_lines(char *str);


int   is_valid_atoi(char *argv);
int arg_check(int argc,char **argv);
int confirm_valid_dict(void);


unsigned int    get_magnitude(unsigned int nbr);
void    convert_triplets(unsigned int  nbr, unsigned int   mag, int *triplets);
void    control_triplets(void);


int	is_key_valid(char *str);
int	is_string_valid(char *str);
int	is_line_valid(char *str);
int	check_dict(char *str);


int	is_line_empty(char *str);
char *trim_lines(char *str);
char	*trim_spaces(char *str);
int	get_key(char **str);
char	*get_string(char **str);

void	fill_keys(void);
void	fill_number(int nb, char *str);
void	parse_entries(char *str);

void	pull_string(int key);
void	write_triplets(int nb);
void    control_print(void);



#endif