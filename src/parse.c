/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:22:22 by root              #+#    #+#             */
/*   Updated: 2025/06/12 23:30:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static char	*read_map_file(char *filename)
{
	int		fd;
	char	*line;
	char	*full;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Failed to open map file");
	full = ft_strdup("");
	if (!full)
		ft_exit_error("Malloc failed");
	line = get_next_line(fd);
	while (line)
	{
		tmp = full;
		full = ft_strjoin(full, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (full);
}

void	parse_map(t_data *data, char *filename)
{
	char	*full;

	if (ft_strlen(filename) < 5
		|| ft_strncmp(filename + ft_strlen(filename) - 4, ".ber", 4))
		ft_exit_error("Invalid file extension");
	full = read_map_file(filename);
	if (!full || !*full)
		ft_exit_error("Empty map file");
	data->map.map = ft_split(full, '\n');
	free(full);
	data->map.y = 0;
	while (data->map.map[data->map.y])
		data->map.y++;
	data->map.x = ft_strlen(data->map.map[0]);
	data->collectibles = 0;
}

/**
* @file parse.c
*
* @brief This function searches through the map to find the player's position
* @param data Pointer to the game data structure
* @returns void
*/
void	find_player_position(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
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
