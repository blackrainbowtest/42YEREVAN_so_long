/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:32:10 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/07 15:05:04 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static void	ft_msg_put(char *msg, int fd)
{
	if (msg)
		ft_putstr_fd(msg, fd);
	else
		ft_putstr_fd("Error\n", fd);
}

void	ft_exit_success(char *msg)
{
	ft_msg_put(msg, STDERR_FILENO);
	exit(EXIT_SUCCESS);
}

void	ft_exit_error(char *msg)
{
	if (!msg)
		perror("Error");
	else
		perror(msg);
	exit(EXIT_FAILURE);
}
