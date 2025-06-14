/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:01:03 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/14 14:58:02 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @file get_next_line_bonus.c
 *
 * @brief Joins two strings and returns the new string
 * @param s First string to join
 * @param d Second string to join
 * @returns A new string that is the concatenation of s and d
 */
char	*read_stroke(int fd, char *store)
{
	char	*buf;
	int		count;
	char	*new_store;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	count = 1;
	while ((!ft_strchr(store, '\n')) && (count > 0))
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1)
		{
			free(buf);
			free(store);
			return (NULL);
		}
		buf[count] = '\0';
		new_store = ft_strjoin_gnl(store, buf);
		free(store);
		store = new_store;
	}
	free(buf);
	return (store);
}

/**
 * @file get_next_line_bonus.c
 * 
 * @brief Finds the next line in the string and returns it
 * @param ptr The string to search for the next line
 * @returns The next line found in the string
 */
static void	free_store(char **store)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		if (store[i])
		{
			free(store[i]);
			store[i] = NULL;
		}
		i++;
	}
}

/**
 * @file get_next_line_bonus.c
 *
 * @brief Finds the next line in the string and returns it
 * @param ptr The string to search for the next line
 * @returns The next line found in the string
 */
char	*get_next_line(int fd)
{
	static char	*store[1024];
	char		*line;
	int			i;

	if (fd == -42)
	{
		free_store(store);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store[fd] = read_stroke(fd, store[fd]);
	if (!store[fd])
		return (NULL);
	line = ft_find_line(store[fd]);
	store[fd] = ft_save_line(store[fd]);
	return (line);
}
