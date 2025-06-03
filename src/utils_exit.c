/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:32:10 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/03 19:45:10 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	ft_exit_ok()
{
	exit(EXIT_SUCCESS);
}

void	ft_exit_ko()
{
	exit(EXIT_FAILURE);
}

void	ft_exit_error()
{
	exit(EXIT_FAILURE);
}