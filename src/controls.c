/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:45:50 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/13 17:54:31 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/**
 * @file handle_keys.c
 * 
 * @brief Handles key events for player movement and exit
 * @param keycode The key code of the pressed key
 * @param data Pointer to the game data structure
 * @return int Returns 0 if the key is handled, or exits 
 * the game if ESC is pressed
 */
int	handle_keys(int keycode, t_data *data)
{
	if (keycode == 65307)
		return (clean_exit(data, "Exit by ESC", EXIT_SUCCESS));
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

/**
 * @file move_player.c
 * 
 * @brief Moves the player in the specified direction if the next tile is valid
 * @param dx Change in x-coordinate (1 for right, -1 for left)
 * @param dy Change in y-coordinate (1 for down, -1 for up)
 * @param data Pointer to the game data structure
 * @return void
 */
void	move_player(int dx, int dy, t_data *data)
{
	int		new_x;
	int		new_y;
	char	next_tile;

	new_x = data->player_x + dx;
	new_y = data->player_y + dy;
	next_tile = data->map.map[new_y][new_x];
	if (next_tile == WALL)
		return ;
	if (next_tile == EXIT && data->collectibles != 0)
		return ;
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

/**
 * @file handle_exit.c
 * 
 * @brief Handles the exit event when the close button is clicked
 * @param data Pointer to the game data structure
 * @return int Returns EXIT_SUCCESS after cleaning up resources
 */
int	handle_exit(t_data *data)
{
	return (clean_exit(data, "Exit by close button", EXIT_SUCCESS));
}
