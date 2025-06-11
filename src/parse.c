#include "../solong.h"

void	parse_map(t_data *data, char *filename)
{
	int		fd;
	char	*line;
	char	*full;
	char	*tmp;

	if (ft_strlen(filename) < 5 || ft_strncmp(filename + ft_strlen(filename) - 4, ".ber", 4))
		ft_exit_error("Invalid file extension");
	fd = open(filename, 0, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Failed to open map file");
	full = ft_strdup("");
	while ((line = get_next_line(fd)) != NULL)
	{
		tmp = full;
		full = ft_strjoin(full, line);
		free(tmp);
		free(line);
	}
	close(fd);
	if (!full || !*full)
		ft_exit_error("Empty map file");
	data->map.map = ft_split(full, '\n');
	free(full);

	data->map.y = 0;
	while (data->map.map[data->map.y])
		data->map.y++;
	data->map.x = ft_strlen(data->map.map[0]);
	data->collectibles = 0;

	int y = 0;
	while (y < data->map.y)
	{
		int x = 0;
		while (x < data->map.x)
		{
			if (data->map.map[y][x] == COLLECT)
				data->collectibles++;
			x++;
		}
		y++;
	}
}

void	find_player_position(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		printf("Checking row %d\n", y);
		while (x < data->map.x)
		{
			printf("Checking column %d\n", x);
			if (data->map.map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	ft_exit_error("Player position not found");
}