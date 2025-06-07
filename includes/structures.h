/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:01:26 by aramarak          #+#    #+#             */
/*   Updated: 2025/06/06 20:12:47 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_img
{
	void	*up;
	void	*down;
	void	*left;
	void	*right;
	void	*bg;
}               t_img;

typedef struct s_map
{
    char    **map;
    void    *obj;
    int     x;
    int     y;
    int     couns;
}               t_map;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    int     p_x;
    int     p_y;
    int     collected;
    int     size_x;
    int     size_y;
    t_img   img;
    t_map   map;
}               t_data;
