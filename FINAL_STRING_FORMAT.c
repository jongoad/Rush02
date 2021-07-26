/***************************************************************************************************/
/*                                   FORMAT STRING BEFORE SPLITTING                                */
/***************************************************************************************************/

int	is_line_empty(char *str)
{
	int	i;
	int	is_empty;

	i = 0;
	is_empty = 1;
	while (str[i] != 10)
	{
		if (str[i] != 32)
			is_empty = 0;
		i++;
	}
	if (i == 0)
		return (1);
	if (is_empty == 1)
		return (i + 1);
	else
		return (0);
}

char *trim_lines(char *str)
{
	int		i;
	int		spaces;
	char	*no_empty;

	i = -1;
	spaces = 0;
	while (str[++i])
	{
		while (str[i] == 10 && is_line_empty(&str[i + 1]))
		{	
			spaces += is_line_empty(&str[i + 1]);
			i++;
		}
	}
	no_empty = (char *)malloc((ft_strlen(str) - spaces + 1) * sizeof(char));
	i = -1;
	spaces = 0;
	while (str[++i + spaces])
	{
		while (str[i] == 10 && is_line_empty(&str[i + spaces + 1]))
			spaces += is_line_empty(&str[i + spaces + 1]);
		no_empty[i] = str[i + spaces];
	}
	return (no_empty);
}

char	*trim_spaces(char *str)
{
	int		i;
	int		j;
	int		spaces;
	char	*no_spaces;

	i = -1;
	spaces = 0;
	while (str[++i] && str[i] != 10)
		while (str[++i] == 32 && str[i + 1] == 32)
			spaces++;
	no_spaces = (char *)malloc(is_string_valid(str) - spaces + 1);
	i = 0;
	j = 0;
	while (str[i] && str[i] != 10)
	{
		while (str[i] == 32 && str[i + 1] == 32)
			i++;
		no_spaces[j] = str[i];
		i++;
		j++;
	}
	no_spaces[j] = 0;
	return (no_spaces);
}

int	get_key(char **str)
{
	int	i;
	int	value;
	int	sign;

	sign = 1;
	i = 0;
	value = 0;
	while (**str == 32)
		*str += 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		*str += 1;
	}
	while (**str >= '0' && **str <= '9')
	{
		value = value * 10 + **str - '0';
		*str += 1;
	}
	while (**str == 32)
		*str += 1;
	*str += 1;
	return (value);
}

char	*get_string(char **str)
{
	int		size;
	char	*cpy;

	size = 0;
	while ((**str) == 32)
		*str += 1;
	cpy = trim_spaces(*str);
	while (**str != 10)
		*str += 1;
	*str += 1;
	return (cpy);
}
