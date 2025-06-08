#include "solong.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_exit_error("Usage: ./so_long <map_file>");
	ft_bzero(&data, sizeof(t_data));
	parse_map(&data, argv[1]);
	init_window(&data);
	render_map(&data);
	mlx_loop(data.mlx);
	return (0);
}