#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
//Returns 1 if valid, 0 otherwise
int	check_dict(char *str)
{
	int	i;
	int	char_type;

	i = 0;
	char_type = 1;
	while (str[i])
	{
		if (char_type == 1)
			ft_atoi(&str[i])
	}
}
*/
int	is_key_valid(char *str)
{
	int	i;
	int	value;
	int	has_number;

	i = 0;
	value = 0;
	has_number = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		has_number = 1;
		value = value * 10 + str[i] - '0';
		i++;
	}
	while (str[i] == 32)
		i++;
	if (str[i] != ':' || has_number == 0)
		return (0);
	return (1);
}

int	ft_get_key(char **str)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
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
char	*ft_get_string(char **str)
{
	int		i;
	int		size;
	char	*cpy;

	size = 0;
	while ((**str) == 32)
		*str += 1;
	while ((*str)[size] != 10)
		size++;
	cpy = (char *)malloc((size + 1) * sizeof(char)); //NEED TO BE FREED
	i = 0;
	while (i < size)
	{
		cpy[i] = (*str)[0];
		*str += 1;
		i++;
	}
	cpy[i] = 0;
	*str += 1;
	return (cpy);
}

int	main()
{
	char	*str1 = "54  : ";
	char	*str2 = "-54  : ";
	char	*str3 = "+54  : ";
	char	*str4 = "+5 4   :";
	char	*str5 = "-54 /:";
	char	*str6 = "1:  TEST1\n2:    TEST2\n245      :       str!#$@%*@#$%ingtest\n";
	int		*value_ptr = 0;
	int i = 0;
	//int	numbers[10] = 0;


	while (*str6 && ++i)
	{
		if (i % 2)
			printf("The number of the entry is: '%d'\n", ft_get_key(&str6));
		else
			printf("The string associated is: '%s'\n\n", ft_get_string(&str6));
	}	
	/*
	printf("Initial string: '%s'\n", str6);
	printf("string gotten: '%s'\n", ft_get_string(&str6));
	printf("New value of string: '%s'", str6);
	printf("Initial string: '%s'\n", str6);
	printf("string gotten: '%s'\n", ft_get_string(&str6));
	printf("New value of string: '%s'", str6);
*/
/*
	value_ptr = ft_get_key(str1);
	if (value_ptr == NULL)
		printf("ERROR\n");
	else
		printf("str1 = '%s'\natoi = '%d'\nmy fct = '%d'\n\n", str1, atoi(str1), *ft_get_key(str1));
	value_ptr = ft_get_key(str2);
	if (value_ptr == NULL)
		printf("ERROR\n");
	else
		printf("str2 = '%s'\natoi = '%d'\nmy fct = '%d'\n\n", str2, atoi(str2), *ft_get_key(str2));
	value_ptr = ft_get_key(str3);
	if (value_ptr == NULL)
		printf("ERROR\n");
	else
		printf("str3 = '%s'\natoi = '%d'\nmy fct = '%d'\n\n", str3, atoi(str3), *ft_get_key(str3));
	value_ptr = ft_get_key(str4);
	if (value_ptr == NULL)
		printf("ERROR\n");
	else
		printf("str4 = '%s'\natoi = '%d'\nmy fct = '%d'\n\n", str4, atoi(str4), *ft_get_key(str4));
	value_ptr = ft_get_key(str5);
	if (value_ptr == NULL)
		printf("ERROR\n");
	else
		printf("str5 = '%s'\natoi = '%d'\nmy fct = '%d'\n\n", str5, atoi(str5), *ft_get_key(str5));
	*/
}
