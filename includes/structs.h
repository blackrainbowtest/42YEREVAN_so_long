typedef struct	s_img
{
	void	bg;
	void	p_top;
	void	p_bottom;
	void	p_left;
	void	p_right;
}				t_img;

typedef struct	s_map
{
	int		x;
	int		y;
	int		coins;
	char	**map;
	void	*obj;
}				t_map;

typedef struct	s_data
{
	void	*mix;
	void	*win;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		player_dir;
	int		player_moves;
	int		collectibles;
	t_img	img;
	t_map	map;
}				t_data;