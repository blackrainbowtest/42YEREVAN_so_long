/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:22:22 by root              #+#    #+#             */
/*   Updated: 2025/06/14 14:53:18 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/**
 * @file parse.c
 *
 * @brief This function reads the map file and returns its content as a string
 * @param filename Name of the map file to read
 * @returns A string containing the content of the map file
 */
static char	*read_map_file(char *filename, t_data *data)
{
	int		fd;
	char	*line;
	char	*full;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		clean_exit(data, "Failed to open map file", EXIT_FAILURE);
	full = ft_strdup("");
	if (!full)
		clean_exit(data, "Malloc failed", EXIT_FAILURE);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(-42);
			free(full);
			clean_exit(data, "Map contains empty lines!", EXIT_FAILURE);
		}
		tmp = full;
		full = ft_strjoin(full, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (full);
}

/**
 * @file parse.c
 *
 * @brief This function reads the map file and splits it into lines
 * @param data Pointer to the game data structure
 * @param filename Name of the map file to read
 * @returns void
 */
void	parse_map(t_data *data, char *filename)
{
	char	*full;

	if (ft_strlen(filename) < 5
		|| ft_strncmp(filename + ft_strlen(filename) - 4, ".ber", 4))
		clean_exit(data, "Invalid file extension", EXIT_FAILURE);
	full = read_map_file(filename, data);
	if (!full || !*full)
		clean_exit(data, "Empty map file", EXIT_FAILURE);
	data->map.map = ft_split(full, '\n');
	free(full);
	if (!data->map.map)
		clean_exit(data, "ft_split failed", EXIT_FAILURE);
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
	clean_exit(data, "Player position not found", EXIT_FAILURE);
}
