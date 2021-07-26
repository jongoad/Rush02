#include <BIGHEADBOY.h>

int get_file_size(void)
{
	int count;
	int fd; 
	int status; 
	char    *c; 

	count = 0;
	status = 1;
	c = (char *)malloc(sizeof(char) + 1);
	fd = open(info.file_path, O_RDONLY);
	while (status > 0 && fd != -1)
	{
		status = read(fd, c, 1);
		if (status > 0)
			count++;
	}
	free(c);
	status = close(fd);
	if (status == -1 || fd == -1)
		return (-1);
	else
		return (count);
}

int file_to_string(void)
{
	int fd;
	int status;
	int size;

	status = 1;
	size = get_file_size();
	info.dict_input = (char *)malloc(sizeof(char) * (size + 1));
	fd = open(info.file_path, O_RDONLY);
	status = read(fd, info.dict_input, size);
	info.dict_input[size] = '\0';
	status = close(fd);
	if (status == -1 || fd == -1)
	   return (-1);
   else
		return (1);
}

char *remove_empty_lines(char *str)
{
	int i;
	int j;
	int size;
	int found_line;

	size = get_file_size();
	info.temp_str = (char *)malloc(sizeof(char) * (size + 1));
	found_line = 0;
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		info.temp_str[i] = str[i + found_line];
		while(str[i + j + found_line] == ' ')
		{
			j++;
		}
		if (str[i + j + found_line] == '\n')
		{
			if (str[i + j + found_line + 1] == '\n')
				str[i + j + found_line + 1] = ' ';
			found_line = j + found_line;
		}
		i++;
	}
	return (info.temp_str);
}