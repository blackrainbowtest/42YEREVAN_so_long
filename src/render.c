#include "../solong.h"

void	render_map(t_data *data)
{
	int	x;
	int	y;
	char	tile;

	y = -1;
	while (++y < data->map.y)
	{
		x = -1;
		while (++x < data->map.x)
		{
			tile = data->map.map[y][x];
			if (tile == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img.wall, x * IMG_W, y * IMG_H);
			else if (tile == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->img.floor, x * IMG_W, y * IMG_H);
			else if (tile == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->img.player, x * IMG_W, y * IMG_H);
			else if (tile == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->img.collect, x * IMG_W, y * IMG_H);
			else if (tile == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->img.exit, x * IMG_W, y * IMG_H);
		}
	}
}
