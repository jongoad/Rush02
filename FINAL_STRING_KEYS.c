#include <BIGHEADBOY.h>


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
}

void	fill_number(int nb, char *str)
{
	int	i;
	
	i = 0;
	while (i < 32)
	{
		if (nb == 0)
		{
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
	
	while (str)
	{
		key = get_key(&str);
		str_size = is_string_valid(str);
		info.entry = (char *)malloc((str_size + 1) * sizeof(char));
		info.entry = get_string(&str);
		info.entry[str_size] = 0;
		if (key == 0)
		fill_number(key, info.entry);
		if (*(str + 3) == 0)
			return ;
	}
}