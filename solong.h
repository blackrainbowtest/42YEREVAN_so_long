/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:49:04 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/13 18:57:50 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "libft/libft.h"
# include "get_next_line/get_next_line_bonus.h"
# include "minilibx-linux/mlx.h"
# include "includes/constants.h"
# include "includes/structs.h"

//		controls.c
int		handle_keys(int keycode, t_data *data);
void	move_player(int dx, int dy, t_data *data);
int		handle_exit(t_data *data);

//		init_images.c
void	init_images(t_data *data);

//		init.c
void	init_window(t_data *data);

//		parse.c
void	parse_map(t_data *data, char *filename);
void	find_player_position(t_data *data);

//		render.c
void	render_map(t_data *data);

//		render_utils.c
void	validate_rectangle(t_data *data);
void	validate_symbols_and_counts(t_data *data);
void	validate_walls(t_data *data);
void	validate_path(t_data *data);

void	ft_exit_error(const char *msg);
void	ft_exit_success(char *msg);
void	ft_free_map(char **map, int lines);
int		clean_exit(t_data *data, const char *msg, int code);

//		utils/validate_utils.c
void	fill(char **map, int x, int y);
char	**copy_map(t_data *data);
void	count_reachable(t_data *data, char **copy,
    int *reachable_c, int *reachable_e);
void	check_char(t_data *data, char ch, t_counts *counts);

#endif