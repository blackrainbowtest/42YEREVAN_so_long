#include "../solong.h"

void	ft_exit_error(const char *msg)
{
	if (msg)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	exit(EXIT_FAILURE);
}

void	ft_exit_success(char *msg)
{
	ft_putstr_fd(msg, 1);
	ft_putchar_fd('\n', 1);
	exit(EXIT_SUCCESS);
}

void	ft_free_map(char **map, int lines)
{
	int	i = 0;
	while (i < lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	clean_exit(t_data *data, const char *msg, int code)
{
	int	y;

	// Освобождаем карту
	if (data->map.map)
	{
		y = 0;
		while (y < data->map.y)
		{
			free(data->map.map[y]);
			y++;
		}
		free(data->map.map);
	}

	// Уничтожаем изображения
	if (data->img.floor)
		mlx_destroy_image(data->mlx, data->img.floor);
	if (data->img.wall)
		mlx_destroy_image(data->mlx, data->img.wall);
	if (data->img.collect)
		mlx_destroy_image(data->mlx, data->img.collect);
	if (data->img.exit)
		mlx_destroy_image(data->mlx, data->img.exit);
	if (data->img.player)
		mlx_destroy_image(data->mlx, data->img.player);

	// Уничтожаем окно
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);

	#ifdef __linux__
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	#endif

	if (msg)
	{
		ft_putstr_fd("Exit: ", 1);
		ft_putstr_fd((char *)msg, 1);
		ft_putchar_fd('\n', 1);
	}
	exit(code);
}