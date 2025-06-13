/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:28:39 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/13 17:43:55 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/**
 * @file render.c
 * 
 * @brief Renders a single tile in the game window based on the tile type
 * @param data Pointer to the game data structure
 * @param tile The character representing the tile type ('1', '0', 'P', 'C', 'E')
 * @param x The x-coordinate of the tile in the map
 * @param y The y-coordinate of the tile in the map
 * @return void
 */
static void	render_tile(t_data *data, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.wall, x * IMG_W, y * IMG_H);
	else if (tile == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.floor, x * IMG_W, y * IMG_H);
	else if (tile == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player, x * IMG_W, y * IMG_H);
	else if (tile == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.collect, x * IMG_W, y * IMG_H);
	else if (tile == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.exit, x * IMG_W, y * IMG_H);
}

/**
 * @file render.c
 * 
 * @brief Renders the entire map in the game window
 * @param data Pointer to the game data structure
 * @return void
 */
void	render_map(t_data *data)
{
	int		x;
	int		y;
	char	tile;

	y = -1;
	while (++y < data->map.y)
	{
		x = -1;
		while (++x < data->map.x)
			render_tile(data, data->map.map[y][x], x, y);
	}
}
