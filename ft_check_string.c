#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int	is_string_valid(char *str);

typedef struct s_entry
{
	int 	key;
	char	*str;
} t_entry;

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
/*
char	*trim_lines(char *str)
{
	int		i;
	int		j;
	int		spaces;
	char	*no_empty;

	i = -1;
	spaces = 0;
	while (str[i])
	{
		j = -1;
		if (str[i] == 10 && (str[i + 1] == 10 || str[i + 1] == 32))
			while (str[i + ++j] == 32 || str[i + j] == 10)
				if (str[i + j] == 10)
					spaces += j;
	}
	no_empty = (char*)malloc((ft_strlen(str) - spaces + 1) * sizeof(char));
	i = -1;
	spaces = 0;
	while (str[++i + spaces])
	{
		j = -1;
		if (str[i] == 10 && (str[i + 1] == 10 || str[i + 1] == 32))
			while (str[i + ++j] == 32 || str[i + j] == 10)
				if (str[i + j] == 10)
					spaces += j;
		no_empty[i] = str[i + spaces];
	}
	no_empty[i] = 0;
	return (no_empty);
}
*/
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
//Gets the string until it reaches a new line.
//Modifies the pointer passed to point to the beginning of next line.
//
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

char	*get_string(char **str)
{
	int	size;
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
	{
		printf("%c \n", str[i]);
		if (str[i] < 32)
			return (0);
	}
	if (str[i] == 10)
		return (i);
	else
		return (0);
}

int	is_line_valid(char *str)
{
	int	i;

	i = -1;
	while (str[++i] == 32 || str[i] == 10)
		if(str[i] == 10)
			return (i + 1);
	if (is_key_valid(&str[i]) == 0)
		return (0);
	else
		i += is_key_valid(str);
	printf("Current string : '%s'\n", &str[i]);
	if (is_string_valid(&str[i]) == 0)
		return (0);
	else
		i += is_string_valid(&str[i]);
	printf("Current string : '%s'\n", &str[i]);
	if (i > 0)
		return (i + 1);
	return (0);
}

//Returns amount of lines if valid, 0 otherwise
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
		for (int j = 0; str[i+j] != 10; j++)
			write(1, &str[i + j], 1);
		write(1, "\n", 1);
		if (line_len == 0)
			return (0);
		if (line_len > 2)
			line_count++;
		i += line_len;
	}
	return (line_count);
}

int	main()
{
//	char	*str1 = "54  : ";
//	char	*str2 = "-54  : ";
//	char	*str3 = "+54  : ";
//	char	*str4 = "+5 4   :";
//	char	*str5 = "tes    t!@*\n";
	char	*str6 = "1:   TEST     1\n\n\n 222  :  TEST2\n245:str!#$@ % * @    #$%ingtesti\n32:test\n";
//	int		*value_ptr = 0;
//	int i = 0;
//	int	numbers[10] = 0;

	printf("The str is '%s'\nAfter trimming:'%s'\n", str6, trim_lines(str6));
/*	
	while (*str6 && ++i)
	{
		if (i % 2)
			printf("The number of the entry is: '%d'\n", get_key(&str6));
		else
			printf("The string associated is: '%s'\n\n", get_string(&str6));
	}	
	
	printf("Initial string: '%s'\n", str6);
	printf("string gotten: '%s'\n", get_string(&str6));
	printf("New value of string: '%s'", str6);
	printf("Initial string: '%s'\n", str6);
	printf("string gotten: '%s'\n", get_string(&str6));
	printf("New value of string: '%s'", str6);
*/
/*
	value_ptr = get_key(str1);
	if (value_ptr == NULL)
		printf("ERROR\n");
	else
		printf("str1 = '%s'\natoi = '%d'\nmy fct = '%d'\n\n", str1, atoi(str1), *get_key(str1));
	value_ptr = get_key(str2);
	if (value_ptr == NULL)
		printf("ERROR\n");
	else
		printf("str2 = '%s'\natoi = '%d'\nmy fct = '%d'\n\n", str2, atoi(str2), *get_key(str2));
	value_ptr = get_key(str3);
	if (value_ptr == NULL)
		printf("ERROR\n");
	else
		printf("str3 = '%s'\natoi = '%d'\nmy fct = '%d'\n\n", str3, atoi(str3), *get_key(str3));
	value_ptr = get_key(str4);
	if (value_ptr == NULL)
		printf("ERROR\n");
	else
		printf("str4 = '%s'\natoi = '%d'\nmy fct = '%d'\n\n", str4, atoi(str4), *get_key(str4));
	value_ptr = get_key(str5);
	if (value_ptr == NULL)
		printf("ERROR\n");
	else
		printf("str5 = '%s'\natoi = '%d'\nmy fct = '%d'\n\n", str5, atoi(str5), *get_key(str5));
	*/
}
