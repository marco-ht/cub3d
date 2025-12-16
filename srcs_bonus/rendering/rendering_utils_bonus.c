/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:40:14 by mpierant &        #+#    #+#             */
/*   Updated: 2025/12/16 12:54:44 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	clear_image(t_vars *v)
{
	size_t	bytes;

	bytes = (size_t)HEIGHT * v->size_line;
	ft_memset(v->data, 0, bytes);
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
