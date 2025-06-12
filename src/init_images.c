/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:42:21 by root              #+#    #+#             */
/*   Updated: 2025/06/12 23:45:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/**
* @file init_images.c
*
* @brief Initializes the images used in the game by loading them from files
* @param img Pointer to the image structure to be initialized
* @param data Pointer to the game data structure
* @param path Path to the image file
* @returns void
*/
static void	load_image(void **img, t_data *data, char *path)
{
	int	w;
	int	h;

	*img = mlx_xpm_file_to_image(data->mlx, path, &w, &h);
	if (!*img)
		clean_exit(data, "Failed to load image", 1);
}

/**
* @file init_images.c
*
* @brief Initializes the images used in the game by loading them from files
* @param data Pointer to the game data structure
* @returns void
*/
void	init_images(t_data *data)
{
	load_image(&data->img.floor, data, "assets/sand.xpm");
	load_image(&data->img.wall, data, "assets/wall.xpm");
	load_image(&data->img.player, data, "assets/player.xpm");
	load_image(&data->img.collect, data, "assets/gas.xpm");
	load_image(&data->img.exit, data, "assets/helicopter.xpm");
}
