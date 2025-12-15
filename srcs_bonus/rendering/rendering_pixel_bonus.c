/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_pixel_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:34:54 by mpierant &        #+#    #+#             */
/*   Updated: 2025/12/15 20:19:45 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	put_pixel(t_vars *v, float x, float y, int color)
{
	int	idx;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	idx = (int)y * v->size_line + (int)x * v->bpp / 8;
	v->data[idx] = color & 0xFF;
	v->data[idx + 1] = (color >> 8) & 0xFF;
	v->data[idx + 2] = (color >> 16) & 0xFF;
}

void	put_pixel_nohex(t_vars *v, float x, float y, int *color)
{
	int	idx;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	idx = (int)y * v->size_line + (int)x * v->bpp / 8;
	v->data[idx] = color[2];
	v->data[idx + 1] = color[1];
	v->data[idx + 2] = color[0];
}
