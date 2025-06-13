/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:48:38 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/13 17:48:38 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/**
 * @file validate.c
 * 
 * @brief Validates the map structure and contents
 * @param data Pointer to the game data structure
 * @return void
 */
void	validate_rectangle(t_data *data)
{
	int	y;
	int	line_len;

	y = 0;
	line_len = ft_strlen(data->map.map[0]);
	while (data->map.map[y])
	{
		if ((int)ft_strlen(data->map.map[y]) != line_len)
			clean_exit(data, ERR_MAP_RECTANGULAR, EXIT_FAILURE);
		y++;
	}
}

/**
 * @file validate.c
 * 
 * @brief Validates the symbols and counts their occurrences in the map
 * @param data Pointer to the game data structure
 * @return void
 */
void	validate_symbols_and_counts(t_data *data)
{
	int			x;
	int			y;
	t_counts	counts;

	counts.p = 0;
	counts.e = 0;
	counts.c = 0;
	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			check_char(data, data->map.map[y][x], &counts);
			x++;
		}
		y++;
	}
	if (counts.p != 1)
		clean_exit(data, ERR_MAP_CONTAIN_P, 1);
	if (counts.e != 1)
		clean_exit(data, ERR_MAP_CONTAIN_E, 1);
	if (counts.c < 1)
		clean_exit(data, ERR_MAP_CONTAIN_C, 1);
	data->collectibles = counts.c;
}

/**
* @file validate.c
 * 
 * @brief Validates that the map is surrounded by walls
 * @param data Pointer to the game data structure
 * @return void
 */
void	validate_walls(t_data *data)
{
	int	i;
	int	width;
	int	height;

	width = data->map.x;
	height = data->map.y;
	i = 0;
	while (i < width)
	{
		if (data->map.map[0][i] != WALL || data->map.map[height - 1][i] != WALL)
			clean_exit(data, ERR_BORDER_TB, EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (data->map.map[i][0] != WALL || data->map.map[i][width - 1] != WALL)
			clean_exit(data, ERR_BORDER_LR, EXIT_FAILURE);
		i++;
	}
}

/**
 * @file validate.c
 * 
 * @brief Validates the path from the player's position to 
 * all collectibles and the exit
 * @param data Pointer to the game data structure
 * @return void
 */
void	validate_path(t_data *data)
{
	char	**copy;
	int		reachable_c;
	int		reachable_e;

	reachable_c = 0;
	reachable_e = 0;
	copy = copy_map(data);
	fill(copy, data->player_x, data->player_y);
	count_reachable(data, copy, &reachable_c, &reachable_e);
	ft_free_map(copy, data->map.y);
	if (reachable_c != data->collectibles)
		clean_exit(data, "Not all collectibles are reachable", 1);
	if (reachable_e != 1)
		clean_exit(data, "Exit is not reachable", 1);
}
