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

void	validate_symbols_and_counts(t_data *data)
{
	int	y = 0;
	int	x;
	int	p_count = 0;
	int	e_count = 0;
	int	c_count = 0;

	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			char ch = data->map.map[y][x];
			if (ch == PLAYER)
				p_count++;
			else if (ch == EXIT)
				e_count++;
			else if (ch == COLLECT)
				c_count++;
			else if (ch != WALL && ch != FLOOR)
				ft_exit_error("Map contains invalid character");
			x++;
		}
		y++;
	}
	if (p_count != 1)
		ft_exit_error("Map must contain exactly one player (P)");
	if (e_count != 1)
		ft_exit_error("Map must contain exactly one exit (E)");
	if (c_count < 1)
		ft_exit_error("Map must contain at least one collectible (C)");

	data->collectibles = c_count;
}

void	validate_walls(t_data *data)
{
	int	i;
	int	width = data->map.x;
	int	height = data->map.y;

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
