#ifndef SOLING_H
# define SOLING_H

#include "libft/libft.h"
#include "get_next_line/get_next_line_bonus.h"
#include "minilibx-linux/mlx.h"
#include "includes/constants.h"
#include "includes/structs.h"

void	ft_exit_error(const char *msg);
void	parse_map(t_data *data, char *filename);
void	init_window(t_data *data);
void	render_map(t_data *data);
void	init_images(t_data *data);
int		handle_keys(int keycode, t_data *data);
void	ft_exit_success(char *msg);
void	find_player_position(t_data *data);
void	move_player(int dx, int dy, t_data *data);
void	validate_rectangle(t_data *data);

#endif