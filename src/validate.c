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
			clean_exit(data, "Map is not rectangular", EXIT_FAILURE);
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
		clean_exit(data, "Map contains invalid character", 1);
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
		clean_exit(data, "Map must contain exactly one player (P)", 1);
	if (counts.e != 1)
		clean_exit(data, "Map must contain exactly one exit (E)", 1);
	if (counts.c < 1)
		clean_exit(data, "Map must contain at least one collectible (C)", 1);
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
			ft_exit_error("Top or bottom border is not closed");
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (data->map.map[i][0] != WALL || data->map.map[i][width - 1] != WALL)
			ft_exit_error("Left or right border is not closed");
		i++;
	}
}

static void	fill(char **map, int x, int y)
{
	if (map[y][x] == WALL || map[y][x] == 'F')
		return;
	map[y][x] = 'F';

	fill(map, x + 1, y);
	fill(map, x - 1, y);
	fill(map, x, y + 1);
	fill(map, x, y - 1);
}

void	validate_path(t_data *data)
{
	char	**copy;
	int		y;
	int		x;
	int		reachable_c = 0;
	int		reachable_e = 0;

	// Копируем карту
	copy = malloc(sizeof(char *) * (data->map.y + 1));
	if (!copy)
		ft_exit_error("Malloc failed in validate_path");

	y = 0;
	while (y < data->map.y)
	{
		copy[y] = ft_strdup(data->map.map[y]);
		if (!copy[y])
			ft_exit_error("ft_strdup failed in validate_path");
		y++;
	}
	copy[y] = NULL;

	// Flood fill от позиции игрока
	fill(copy, data->player_x, data->player_y);

	// Подсчёт достижимых C и E
	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			if (data->map.map[y][x] == COLLECT && copy[y][x] == 'F')
				reachable_c++;
			if (data->map.map[y][x] == EXIT && copy[y][x] == 'F')
				reachable_e++;
			x++;
		}
		y++;
	}

	ft_free_map(copy, data->map.y);

	if (reachable_c != data->collectibles)
		ft_exit_error("Not all collectibles are reachable");
	if (reachable_e != 1)
		ft_exit_error("Exit is not reachable");
}
