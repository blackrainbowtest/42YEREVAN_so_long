#include "../solong.h"

void	ft_exit_error(const char *msg)
{
	if (msg)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	exit(EXIT_FAILURE);
}

void	ft_exit_success(char *msg)
{
	ft_putstr_fd(msg, 1);
	ft_putchar_fd('\n', 1);
	exit(EXIT_SUCCESS);
}