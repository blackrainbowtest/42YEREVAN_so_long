/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:48:48 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/13 18:48:51 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_exit_error("Usage: ./so_long <map_file>");
	ft_bzero(&data, sizeof(t_data));
	parse_map(&data, argv[1]);
	find_player_position(&data);
	validate_rectangle(&data);
	validate_symbols_and_counts(&data);
	validate_walls(&data);
	validate_path(&data);
	init_window(&data);
	init_images(&data);
	mlx_key_hook(data.win, handle_keys, &data);
	mlx_hook(data.win, 17, 0, handle_exit, &data);
	render_map(&data);
	printf("Game loop exited.\n");
	mlx_loop(data.mlx);
	return (0);
}
