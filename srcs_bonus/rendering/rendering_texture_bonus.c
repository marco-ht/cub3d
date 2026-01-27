/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_texture_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:17:11 by mpierant &        #+#    #+#             */
/*   Updated: 2025/12/15 20:19:40 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	select_wall_texture(t_vars *v)
{
	if (v->ray.hit_door && v->door.img)
		v->ray.current_texture = &v->door;
	else if (!v->ray.side && v->ray.dir_x > 0)
		v->ray.current_texture = &v->ea;
	else if (!v->ray.side && v->ray.dir_x < 0)
		v->ray.current_texture = &v->we;
	else if (v->ray.side && v->ray.dir_y > 0)
		v->ray.current_texture = &v->so;
	else
		v->ray.current_texture = &v->no;
}

void	set_texture(t_vars *v)
{
	double	wall_x;
	double	perp;

	select_wall_texture(v);
	if (v->ray.side == 0)
		perp = v->ray.dist_x - v->ray.delta_x;
	else
		perp = v->ray.dist_y - v->ray.delta_y;
	if (v->ray.side == 0)
		wall_x = (v->player.y / BLOCK) + perp * v->ray.dir_y;
	else
		wall_x = (v->player.x / BLOCK) + perp * v->ray.dir_x;
	wall_x -= floor(wall_x);
	v->ray.tex_x = (int)(wall_x * v->ray.current_texture->width);
	if (v->ray.side == 0 && v->ray.dir_x > 0)
		v->ray.tex_x = v->ray.current_texture->width - v->ray.tex_x - 1;
	if (v->ray.side == 1 && v->ray.dir_y < 0)
		v->ray.tex_x = v->ray.current_texture->width - v->ray.tex_x - 1;
}

void	get_pixel_color_from_texture(t_vars *v, int tx, int ty)
{
	t_texture	*t;
	int			x;
	int			y;
	int			idx;

	t = v->ray.current_texture;
	x = tx % t->width;
	y = ty % t->height;
	if (x < 0)
		x += t->width;
	if (y < 0)
		y += t->height;
	if (x >= t->width || y >= t->height)
		return ;
	idx = y * t->size_line + x * (t->bpp / 8);
	v->ray.current_pixel[2] = t->data[idx];
	v->ray.current_pixel[1] = t->data[idx + 1];
	v->ray.current_pixel[0] = t->data[idx + 2];
}
