#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
void	fill_number(int nb, char *str);
void	fill_keys(void);
void	parse_entries(char *str);
int		is_string_valid(char *str);
int 	get_key(char **str);
char	*get_string(char **str);


struct	s_entries
{
	int		size;
	int 	keys[32];
	char	*strs[32];
} dict;

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

int	main(void)
{
	fill_keys();
//	printf("%s\n", dict.strs[4]);
	char *dictionary = "0: zero\n 1: one\n2: two\n3: three\n4: four\n5: five\n6: six\n7: seven TEST TEST \n8: eight\n9: nine\n10: ten\n11: eleven\n12: twelve\n13: thirteen\n14: fourteen\n15: fifteen\n16: sixteen\n17: seventeen\n18: eighteen\n19: nineteen\n20: twenty\n30: thirty\n40: forty\n50: fifty\n60: sixty\n70: seventy\n80: eighty\n90: ninety\n100: hundred\n1000: thousand\n1000000: million\n1000000000: billion\n";


	parse_entries(dictionary);
	for (int i = 0; i < 32; i++)
		printf("dict.entry #%d = '%s'\n", i, dict.strs[i]);
}

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
