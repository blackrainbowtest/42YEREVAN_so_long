/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 00:53:51 by root              #+#    #+#             */
/*   Updated: 2025/06/14 14:50:02 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/**
* @file exit.c
*
* @brief Prints an error message and exits the program
* @param msg Message to display on error
* @param code Exit code to return
* @returns void
*/
void	ft_print_exit(const char *msg, int code)
{
	if (code)
		ft_putstr_fd("Error\n", 1);
	if (msg)
	{
		ft_putstr_fd((char *)msg, 1);
		ft_putchar_fd('\n', 1);
	}
}

/**
* @file exit.c
*
* @brief Handles successful exit for the game
* @param msg Message to display on successful exit
* @returns void
*/
void	ft_exit_success(char *msg, t_data *data)
{
	clean_exit(data, msg, EXIT_SUCCESS);
}

/**
* @file exit.c
*
* @brief Frees the allocated memory for the map
* @param map The map to be freed
* @param lines The number of lines in the map
* @returns void
*/
void	ft_free_map(char **map, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/**
* @file exit.c
*
* @brief Destroys all images and the window created by MiniLibX
* @param data Pointer to the game data structure
* @returns void
*/
static void	mlx_destroy_all(t_data *data)
{
	if (data->img.floor)
		mlx_destroy_image(data->mlx, data->img.floor);
	if (data->img.wall)
		mlx_destroy_image(data->mlx, data->img.wall);
	if (data->img.collect)
		mlx_destroy_image(data->mlx, data->img.collect);
	if (data->img.exit)
		mlx_destroy_image(data->mlx, data->img.exit);
	if (data->img.player)
		mlx_destroy_image(data->mlx, data->img.player);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
}

/**
* @file exit.c
*
* @brief Cleans up resources and exits the game
* @param data Pointer to the game data structure
* @param msg Message to display on exit
* @param code Exit code to return
* @returns exit code
*/
int	clean_exit(t_data *data, const char *msg, int code)
{
	int	y;

	if (data && data->map.map)
	{
		y = 0;
		while (y < data->map.y)
		{
			free(data->map.map[y]);
			y++;
		}
		free(data->map.map);
	}
	if (data)
		mlx_destroy_all(data);
	if (ISLINUX && data && data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	ft_print_exit(msg, code);
	exit(code);
}
