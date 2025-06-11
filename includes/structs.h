#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_map
{
	char	**map;
	int		x; // width
	int		y; // height
}				t_map;

typedef struct	s_img
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*collect;
	void	*exit;
}				t_img;

typedef struct	s_data
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
#endif
