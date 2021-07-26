/***************************************************************************************************/
/*                                  GRAB STRINGS VIA KEYS AND STORE                                */
/***************************************************************************************************/

void	fill_keys(void)
{
	int i = 0;
	while (i < 20)
	{
		dict.keys[i] = i;
		i++;
	}
	while (i < 29)
	{
		dict.keys[i] = (i - 18) * 10;
		i++;
	}
	dict.keys[29] = 1000;
	dict.keys[30] = 1000000;
	dict.keys[31] = 1000000000;
//	for (int i = 0; i < 32; i++)
	//	printf("entry #%d: '%d'\n", i, dict.keys[i]);
}

void	fill_number(int nb, char *str)
{
	int	i;
	
	i = 0;
	while (i < 32)
	{
		if (nb == 0)
		{
	//		dict.strs[i] = (char *)malloc(5 * sizeof(char));
	//		ft_strcpy (dict.strs[i], "zero");
			dict.strs[i] = (char *)malloc((ft_strlen(str + 1)) * sizeof(char));
			ft_strcpy (dict.strs[i], str);
			return ;
		}
		if (nb == dict.keys[i])
		{
			dict.strs[i] = (char *)malloc((ft_strlen(str + 1)) * sizeof(char));
			ft_strcpy (dict.strs[i], str);
			return ;
		}
		i++;
	}
}

void	parse_entries(char *str)
{
	int 	key;
	int		str_size;
	char	*entry;
	
	while (str)
	{
		key = get_key(&str);
	//		printf("The number of the entry is: '%d'\n", key);
		str_size = is_string_valid(str);
		entry = (char *)malloc((str_size + 1) * sizeof(char));
		entry = get_string(&str);
		entry[str_size] = 0;
	//		printf("The string associated is: '%s'\n\n",entry);
		if (key == 0)
			printf("entry for zero = %s\n", entry);
		fill_number(key, entry);
		if (*(str + 3) == 0)
			return ;
	}
}

