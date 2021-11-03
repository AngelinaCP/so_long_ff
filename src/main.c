
#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_error("not enought arguments");
	if (argc > 2)
		ft_error("a lot of argumnets");
	if (ft_strrchr(argv[1], '.'))
	{
		if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
			ft_error("inncorrect arguments");
	}
	else
		ft_error("not arguments");
	so_long(argv[1]);
	return (0);
}
