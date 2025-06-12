/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:39:51 by root              #+#    #+#             */
/*   Updated: 2025/06/12 23:44:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/**
* @file init.c
*
* @brief Initializes the game window using MiniLibX
* @param data Pointer to the game data structure
* @returns void
*/
void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		clean_exit(data, "Failed initializing mlx", 1);
	data->width = data->map.x * IMG_W;
	data->height = data->map.y * IMG_H;
	data->win = mlx_new_window(data->mlx, data->width, data->height, WIN_NAME);
	if (!data->win)
		clean_exit(data, "mlx_new_window failed", 1);
}
