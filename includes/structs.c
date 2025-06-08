#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map
{
	char	**map;
	int		x; // ширина
	int		y; // высота
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_map	map;
}	t_data;

#endif
