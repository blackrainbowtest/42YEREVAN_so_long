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
}