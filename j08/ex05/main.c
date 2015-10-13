#include "ft_stock_par.h"

int	main(int argc, char **argv)
{
	t_stock_par *a;

	a = ft_param_to_tab(argc, argv);
	ft_show_tab(a);
	return (0);
}
