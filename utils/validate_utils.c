/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:44:55 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/14 10:11:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/**
 * @file utils/validate_utils.c
 * 
 * @brief Flood fill algorithm to mark reachable tiles from the player's position
 * @param map The map to fill
 * @param x The x-coordinate of the current tile
 * @param y The y-coordinate of the current tile
 * @return void
 */
void	fill(char **map, int x, int y)
{
	if (map[y][x] == WALL || map[y][x] == FILL)
		return ;
	map[y][x] = FILL;
	fill(map, x + 1, y);
	fill(map, x - 1, y);
	fill(map, x, y + 1);
	fill(map, x, y - 1);
}

/**
 * @file utils/validate_utils.c
 * 
 * @brief Creates a copy of the map for path validation
 * @param data Pointer to the game data structure
 * @return A dynamically allocated copy of the map
 */
char	**copy_map(t_data *data)
{
	char	**copy;
	int		y;

	copy = malloc(sizeof(char *) * (data->map.y + 1));
	if (!copy)
		clean_exit(data, ERR_MALLOC_VAL, EXIT_FAILURE);
	y = 0;
	while (y < data->map.y)
	{
		copy[y] = ft_strdup(data->map.map[y]);
		if (!copy[y])
			clean_exit(data, ERR_MALLOC_VAL, EXIT_FAILURE);
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

/**
 * @file utils/validate_utils.c
 * 
 * @brief Counts the reachable collectibles and exit tiles in the map
 * @param data Pointer to the game data structure
 * @param copy The map copy to check
 * @param reachable_c Pointer to the count of reachable collectibles
 * @param reachable_e Pointer to the count of reachable exit tiles
 * @return void
 */
void	count_reachable(t_data *data, char **copy,
				int *reachable_c, int *reachable_e)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			if (data->map.map[y][x] == COLLECT && copy[y][x] == FILL)
				(*reachable_c)++;
			if (data->map.map[y][x] == EXIT && copy[y][x] == FILL)
				(*reachable_e)++;
			x++;
		}
		y++;
	}
}

/**
 * @file utils/validate_utils.c
 * 
 * @brief Checks if the map contains valid characters and counts them
 * @param data Pointer to the game data structure
 * @param ch The character to check
 * @param counts Pointer to the counts structure to update
 * @return void
 */
void	check_char(t_data *data, char ch, t_counts *counts)
{
	if (ch == PLAYER)
		counts->p++;
	else if (ch == EXIT)
		counts->e++;
	else if (ch == COLLECT)
		counts->c++;
	else if (ch != WALL && ch != FLOOR)
		clean_exit(data, ERR_MAP_CONTAIN_INVALID, EXIT_FAILURE);
}
