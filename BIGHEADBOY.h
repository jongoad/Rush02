#ifndef BIGHEADBOY_H
# define BIGHEADBOY_H

# include <unistd.h>
# include <stdlib.h>

struct s_data {
	char			file_path[4096];
	unsigned int	nbr;
	int				triplets[4];
	unsigned int	mag;
	char			*dict_input;
} info;

struct	s_entries
{
	int		size;
	int		keys[32];
	char	*strs[32];
} dict;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_strcpy(char *dest, char *src);
int		ft_strlen(char *str);
int		get_file_size(void);
int		file_to_string(void);
char	*remove_empty_lines(char *str);
int		is_valid_atoi(char *argv);
int		arg_check(int argc, char **argv);
int		confirm_valid_dict(void);
void	convert_triplets(unsigned int nbr, unsigned int mag, int *triplets);
void	control_triplets(void);
int		is_key_valid(char *str);
int		is_string_valid(char *str);
int		is_line_valid(char *str);
int		check_dict(char *str);
int		is_line_empty(char *str);
char	*trim_lines(char *str);
char	*trim_spaces(char *str);
int		get_key(char **str);
char	*get_string(char **str);
void	fill_keys(void);
void	fill_number(int nb, char *str);
void	parse_entries(char *str);
void	pull_string(int key);
int		write_triplets(int nb);
void	control_print(void);
int		get_magnitude(unsigned int nbr);
#endif
