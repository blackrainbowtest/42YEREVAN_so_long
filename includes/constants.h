#ifndef CONSTANTS_H
# define CONSTANTS_H

# define IMG_W 64
# define IMG_H 64

# define WIN_NAME "so_long"

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECT 'C'

# define ERR_USAGE "Usage: ./so_long <map_file>"
# define ERR_MLX_INIT "mlx_init failed"
# define ERR_WIN_INIT "mlx_new_window failed"
# define ERR_FILE "Failed to open map file"
# define ERR_EXT "Invalid file extension"
# define ERR_EMPTY "Empty map file"

# define ISLINUX 0
# ifdef __linux__
#  define ISLINUX 1
# endif
#endif