#include "../solong.h"

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_exit_error("Filed initializing mlx");
	data_windth = data->map.x * IMG_W;
	data->height = data->map.y * IMG_H;
	data->win = mlx_new_window(data->mlx, data->width, data->height, WIN_NAME);
	if (!data->win)
		ft_exit_error("mlx_new_window failed");
}