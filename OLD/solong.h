/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:23:43 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/07 15:20:45 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line_bonus.h"
# include "minilibx-linux/mlx.h"
# include "./includes/structs.h"
# include "./includes/constants.h"


// src/map_getter.c
void	ft_check_extension(char *file_name, char *dup);

// src/utils_exit.c
void	ft_exit_success(char *msg);
void	ft_exit_error(char *msg);


#endif