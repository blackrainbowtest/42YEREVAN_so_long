/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:26:54 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/13 17:57:59 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
}				t_map;

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*collect;
	void	*exit;
}				t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		player_moves;
	int		collectibles;
	t_map	map;
	t_img	img;
}				t_data;

typedef struct s_counts
{
	int		p;
	int		e;
	int		c;
}				t_counts;
#endif
