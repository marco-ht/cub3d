/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:40:14 by mpierant &        #+#    #+#             */
/*   Updated: 2025/12/15 20:19:36 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	clear_image(t_vars *v)
{
	size_t	bytes;

	bytes = (size_t)HEIGHT * v->size_line;
	ft_memset(v->data, 0, bytes);
}

int	touch(char **map, float new_x, float new_y)
{
	if (map[(int)new_y / BLOCK][(int)new_x / BLOCK] == '1')
		return (1);
	return (0);
}

int	stouch(char **map, int map_x, int map_y)
{
	if (map[map_y][map_x] == '1')
		return (1);
	return (0);
}

void	draw_ceiling(t_vars *v, int x, int y, int end)
{
	while (y < end)
		put_pixel_nohex(v, x, y++, v->c);
}

void	draw_floor(t_vars *v, int x, int y, int end)
{
	while (y < end)
		put_pixel_nohex(v, x, y++, v->f);
}
