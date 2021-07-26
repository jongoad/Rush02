#include <BIGHEADBOY.h>

int	is_valid_atoi(char *argv)
{
	unsigned long	nbr;
	int				i;

	i = 0;
	nbr = 0;
	while (argv[i] >= '0' && argv[i] <= '9')
	{
		nbr = (nbr * 10) + (argv[i] - '0');
		i++;
		if (nbr > 4294967295)
			return (-1);
	}
	if (argv[0] < '0' || argv[0] > '9' || argv[i] != '\0')
		return (-1);
	else
	{
		info.nbr = nbr;
		return (1);
	}
}

int	arg_check(int argc, char **argv)
{
	int	nbr_check;

	if (argc == 3)
	{
		nbr_check = is_valid_atoi(argv[2]);
		ft_strcpy(info.file_path, argv[1]);
	}
	else if (argc == 2)
	{
		nbr_check = is_valid_atoi(argv[1]);
		ft_strcpy(info.file_path, "numbers.dict");
	}
	else if (argc == 1)
		return (-1);
	return (nbr_check);
}

int	confirm_valid_dict(void)
{
	int	dict_check;

	dict_check = check_dict(info.dict_input);
	return (dict_check);
}
