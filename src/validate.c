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
 * @brief Checks if the map contains valid characters and counts them
 * @param data Pointer to the game data structure
 * @param ch The character to check
 * @param counts Pointer to the counts structure to update
 * @return void
 */
static void	check_char(t_data *data, char ch, t_counts *counts)
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
 * @brief Flood fill algorithm to mark reachable tiles from the player's position
 * @param map The map to fill
 * @param x The x-coordinate of the current tile
 * @param y The y-coordinate of the current tile
 * @return void
 */
static void	fill(char **map, int x, int y)
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
 * @file validate.c
 * 
 * @brief Creates a copy of the map for path validation
 * @param data Pointer to the game data structure
 * @return A dynamically allocated copy of the map
 */
static char	**copy_map(t_data *data)
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
 * @file validate.c
 * 
 * @brief Counts the reachable collectibles and exit tiles in the map
 * @param data Pointer to the game data structure
 * @param copy The map copy to check
 * @param reachable_c Pointer to the count of reachable collectibles
 * @param reachable_e Pointer to the count of reachable exit tiles
 * @return void
 */
static void	count_reachable(t_data *data, char **copy,
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
