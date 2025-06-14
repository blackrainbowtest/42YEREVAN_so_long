/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:01:17 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/14 09:46:23 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @file get_next_line_utils_bonus.c
 *
 * @brief Calculates the length of a string
 * @param s The string to calculate the length of
 * @returns The length of the string
 */
size_t	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * @file get_next_line_utils_bonus.c
 *
 * @brief Joins two strings and returns the new string
 * @param s First string to join
 * @param d Second string to join
 * @returns A new string that is the concatenation of s and d
 */
char	*ft_strjoin_gnl(char *s, char *d)
{
	size_t	index;
	size_t	s_len;
	size_t	d_len;
	char	*result;

	s_len = (s != NULL) * ft_strlen_gnl(s);
	d_len = (d != NULL) * ft_strlen_gnl(d);
	result = (char *)malloc(s_len + d_len + 1);
	index = 0;
	if (!result)
		return (NULL);
	while (s && *s)
		result[index++] = *s++;
	while (d && *d)
		result[index++] = *d++;
	result[index] = '\0';
	return (result);
}

/**
 * @file get_next_line_utils_bonus.c
 *
 * @brief Searches for the first occurrence of a character in a string
 * @param s The string to search in
 * @param c The character to search for
 * @returns A pointer to the first occurrence of the character in the string,
 */
char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (((unsigned char)*s) == c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((unsigned char)*s == c)
		return ((char *)s);
	return (NULL);
}

/**
 * @file get_next_line_utils_bonus.c
 *
 * @brief Finds the next line in the string and returns it
 * @param ptr The string to search for the next line
 * @returns The next line found in the string
 */
char	*ft_find_line(char *ptr)
{
	int		i;
	int		j;
	char	*cube;

	i = 0;
	j = 0;
	cube = 0;
	if (!ptr || (ptr[0] == '\0'))
		return (NULL);
	while (ptr[i] && (ptr[i] != '\n'))
		i++;
	if (ptr[i] == '\n')
		i++;
	cube = malloc(i + 1);
	if (!cube)
		return (NULL);
	while (j < i)
	{
		cube[j] = ptr[j];
		j++;
	}
	cube[j] = '\0';
	return (cube);
}

/**
 * @file get_next_line_utils_bonus.c
 *
 * @brief Saves the remaining part of the string after the first line
 * @param set The string to save the remaining part from
 * @returns A new string that contains the remaining part of the original string
 */
char	*ft_save_line(char *set)
{
	char	*caze;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!set)
		return (NULL);
	while (set[i] && (set[i] != '\n'))
		i++;
	if (!set[i])
	{
		free(set);
		return (NULL);
	}
	i += (set[i] == '\n');
	caze = malloc(ft_strlen_gnl(set) - i + 1);
	if (!caze)
		return (NULL);
	while (set[i])
		caze[j++] = set[i++];
	caze[j] = '\0';
	free(set);
	return (caze);
}
