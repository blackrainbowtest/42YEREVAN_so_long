#include "../solong.h"

void	validate_rectangle(t_data *data)
{
	int	y = 0;
	int	line_len = ft_strlen(data->map.map[0]);

	while (data->map.map[y])
	{
		if ((int)ft_strlen(data->map.map[y]) != line_len)
			ft_exit_error("Map is not rectangular");
		y++;
	}
}