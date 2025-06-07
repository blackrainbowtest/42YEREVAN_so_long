/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:30:27 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/07 15:13:08 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./solong.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;
	
	if (argc != 2)
		ft_exit_error(ERR_USAGE);
	ft_check_extension(argv[1], BER);
	
	data.mlx = mlx_init();
	if (!data.mlx)
		ft_exit_error(ERR_INIT);
	data.win = mlx_new_window(data.mlx, data.width, data.height, WIN_NAME);
	//
	mlx_loop(data.mlx);
	ft_exit_error(ERR_LOOP);
}
