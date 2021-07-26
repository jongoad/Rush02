#include <BIGHEADBOY.h>

void	pull_string(int key)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (key == dict.keys[i])
		{
			ft_putstr(dict.strs[i]);
			return ;
		}
		i++;	
	}
}

int	write_triplets(int nb)
{
	if (nb / 100)
	{
		pull_string(nb/100);
		ft_putchar(' ');
		pull_string(100);
	}
	if (nb % 100 < 21 && nb % 100 > 0)
	{
		ft_putchar(' ');
		pull_string(nb % 100);
		return (nb);
	}
	else if (nb % 100 > 0)
	{
		ft_putchar(' ');
		pull_string(nb % 100 - nb % 10);
	}
	if (nb % 10)
	{
		ft_putchar(' ');
		pull_string(nb % 10);
	}
	return (nb);
}

void    control_print(void)
{
	int i;
	int triplet_value;
	unsigned int local_mag;
	int no_print;

	i = 0;
	local_mag = info.mag;
	while (i < 4 && info.mag != 0)
	{
		triplet_value = info.triplets[i];
		no_print = write_triplets(triplet_value);
		if (local_mag != 1 && no_print != 0)
			{
				ft_putchar(' ');
				pull_string(local_mag);
				ft_putchar(' ');
			}
		else if (local_mag == 1)
			break;
		local_mag = (local_mag / 1000);
		i++;
	}
	ft_putchar(10);
	return;
}

void    free_memory(void)
{
	free(info.dict_input);
	free(info.no_spaces);
}