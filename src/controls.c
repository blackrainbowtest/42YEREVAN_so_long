#include "../solong.h"

int	handle_keys(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_exit_success("Exit");

	if (keycode == 'W' || keycode == 119 || keycode == 65362)
		move_player(0, -1, data);
	else if (keycode == 'A' || keycode == 97 || keycode == 65361)
		move_player(-1, 0, data);
	else if (keycode == 'S' || keycode == 115 || keycode == 65364)
		move_player(0, 1, data);
	else if (keycode == 'D' || keycode == 100 || keycode == 65363)
		move_player(1, 0, data);

	return (0);
}

void	move_player(int dx, int dy, t_data *data)
{
	int	new_x = data->player_x + dx;
	int	new_y = data->player_y + dy;
	char	next_tile = data->map.map[new_y][new_x];

	if (next_tile == WALL)
		return;

	if (next_tile == EXIT && data->collectibles != 0)
		return;

	if (data->map.map[data->player_y][data->player_x] != EXIT)
		data->map.map[data->player_y][data->player_x] = FLOOR;

	if (next_tile == COLLECT)
		data->collectibles--;

	if (next_tile != EXIT)
		data->map.map[new_y][new_x] = PLAYER;

	data->player_x = new_x;
	data->player_y = new_y;
	data->player_moves++;

	printf("Moves: %d\n", data->player_moves);

	render_map(data);
	if (next_tile == EXIT && data->collectibles == 0)
		ft_exit_success("You win!");
}