/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:30:27 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/07 10:09:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./solong.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;
	
	if (argc != 2)
		ft_exit_error("Error\nUsage: ./solong <map_file>\n");
	ft_check_extension(argv[1], ".ber");
	argv[1] = "maps/42.ber";
	ft_exit_ok();
	return (0);
}
