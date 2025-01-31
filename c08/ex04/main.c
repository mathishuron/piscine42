#include "ft_stock_str.h"
#include <stdlib.h>

struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void ft_show_tab(struct s_stock_str *par);

int	main(int argc, char *argv[])
{
	int	i = 0;
	struct s_stock_str	*my_test;
	my_test = ft_strs_to_tab(argc, argv);
	ft_show_tab(my_test);
	while(my_test[i].str != (void *)0)
	{
		free(my_test[i].copy);
		i++;
	}
	free(my_test);
	return 0;
}
