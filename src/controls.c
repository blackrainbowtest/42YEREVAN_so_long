#include "../solong.h"

int	handle_keys(int keycode, t_data *data)
{
	if (keycode == 65307) // ESC
		ft_exit_success("Exit");

	ft_putstr_fd("Keycode: ", 1);
	ft_putnbr_fd(keycode, 1);
	ft_putchar_fd('\n', 1);

	return (0);
}