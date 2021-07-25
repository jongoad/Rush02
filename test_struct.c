#include <stdio.h>
#include <stdlib.h>
void	printkeys();

typedef struct	s_entries
{
	int		size;
	int 	keys[32];
	char	*strs[32];
} dict;


int	main(void)
{
	fill_g_keys();
}

void	fill_g_keys(void)
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
	for (int i = 0; i < 32; i++)
		printf("entry #%d: '%d'\n", i, g_keys[i]);
}

void	fill_array(int nb, char *str)
{
	int	i;

	while (i < 32)
	{
		if (nb == dict.keys[i])
			dict.strs[i] = (char *)malloc((ft_strlen(str + 1) * sizeof(char));
			dict
}
