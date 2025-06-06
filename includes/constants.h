/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:00:17 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/07 15:16:59 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Define the size of the window
# define IMG_W 64
# define IMG_H 64

// Define buttons
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UARROW 65362
# define LARROW 65361
# define DARROW 65364
# define RARROW 65363

// Define constants
# define WALL '1'
# define FLOOR '0'
# define COLL 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

// Define shortcuts
# define BER ".ber"
# define WIN_NAME "So Long"

// Define error messages
# define ERR_USAGE "Error\nUsage: ./solong <map_file>\n"
# define ERR_INIT "Error\nFailed to initialize mlx.\n"
# define ERR_LOOP "Error\nFailed to loop game.\n"