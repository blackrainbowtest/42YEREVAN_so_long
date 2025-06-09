#include "../solong.h"

static void	load_image(void **img, t_data *data, char *path)
{
	int	w;
	int	h;

	*img = mlx_xpm_file_to_image(data->mlx, path, &w, &h);
	if (!*img)
		ft_exit_error("Failed to load image");
}

void	init_images(t_data *data)
{
	load_image(&data->img.floor, data, "assets/sand.xpm");
	load_image(&data->img.wall, data, "assets/wall.xpm");
	load_image(&data->img.player, data, "assets/player.xpm");
	load_image(&data->img.collect, data, "assets/gas.xpm");
	load_image(&data->img.exit, data, "assets/helicopter.xpm");
}