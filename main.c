#include <BIGHEADBOY.h>

int main(int argc, char **argv)
{
	int arg_status;
	int error_status;
	int dict_error;
  
	arg_status = arg_check(argc, argv);
	error_status = file_to_string();
	dict_error = confirm_valid_dict();
	info.dict_input = remove_empty_lines(info.dict_input);
	
	if (dict_error == 0)
	{
		printf("Dict Error\n");
		return (0);
	}
	else if (arg_status == -1)
	{
		printf("Error\n");
		return (0);
	}
	control_triplets();
	fill_keys();
	parse_entries(info.dict_input);
	control_print();
	free_memory();
	return (0);
}