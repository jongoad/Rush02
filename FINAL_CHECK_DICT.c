#include <BIGHEADBOY.h>

int	is_key_valid(char *str)
{
	int	i;
	int	has_number;

	i = 0;
	has_number = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		has_number = 1;
		i++;
	}
	while (str[i] == 32)
		i++;
	if (str[i] != ':' || has_number == 0)
		return (0);
	return (i);
}

int	is_string_valid(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != 10 && str[i])
		if (str[i] < 32)
			return (0);
	if (str[i] == 10)
		return (i);
	else
		return (0);
}

int	is_line_valid(char *str)
{
	int	i;

	i = 0;
	if (is_key_valid(&str[i]) == 0)
		return (0);
	else
		i += is_key_valid(str);
	if (is_string_valid(&str[i]) == 0)
		return (0);
	else
		i += is_string_valid(&str[i]);
	if (i > 0)
		return (i + 1);
	return (0);
}

int	check_dict(char *str)
{
	int	i;
	int	line_count;
	int	line_len;

	i = 0;
	line_count = 0;
	line_len = 0;
	while (str[i])
	{
		line_len = is_line_valid(&str[i]);
		if (line_len == 0)
			return (0);
		if (line_len > 2)
			line_count++;
		i += line_len;
	}
	return (line_count);
}
