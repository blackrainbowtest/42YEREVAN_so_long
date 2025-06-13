/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:26:44 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/13 18:31:03 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define IMG_W 90
# define IMG_H 90

# define WIN_NAME "so_long"

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECT 'C'
# define FILL 'F'

# define ERR_USAGE "Usage: ./so_long <map_file>"
# define ERR_MLX_INIT "mlx_init failed"
# define ERR_WIN_INIT "mlx_new_window failed"
# define ERR_FILE "Failed to open map file"
# define ERR_EXT "Invalid file extension"
# define ERR_EMPTY "Empty map file"

# define ERR_BORDER_TB "Top or bottom border is not closed"
# define ERR_BORDER_LR "Left or right border is not closed"

# define ERR_MAP_CONTAIN_P "Map must contain exactly one player (P)"
# define ERR_MAP_CONTAIN_E "Map must contain exactly one exit (E)"
# define ERR_MAP_CONTAIN_C "Map must contain at least one collectible (C)"
# define ERR_MAP_CONTAIN_INVALID "Map contains invalid character"
# define ERR_MAP_RECTANGULAR "Map must be rectangular"

# define ERR_MALLOC_VAL "Malloc failed"

# ifdef __linux__
#  define ISLINUX 1
# else
#  define ISLINUX 0
# endif
#endif