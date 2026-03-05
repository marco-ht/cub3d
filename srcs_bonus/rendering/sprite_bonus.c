/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritete_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:00:00 by mpierant          #+#    #+#             */
/*   Updated: 2026/02/17 18:31:56 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	scale_frame(t_vars *v, t_texture *src, t_texture *dst)
{
	int	x;
	int	y;
	int	src_x;
	int	src_y;
	int	src_idx;
	int	dst_idx;

	dst->img = mlx_new_image(v->mlx, SPRITE_WIDTH, SPRITE_HEIGHT);
	dst->data = mlx_get_data_addr(dst->img, &dst->bpp, &dst->size_line,
			&dst->endian);
	y = -1;
	while (++y < SPRITE_HEIGHT)
	{
		x = -1;
		while (++x < SPRITE_WIDTH)
		{
			src_x = x * src->width / SPRITE_WIDTH;
			src_y = y * src->height / SPRITE_HEIGHT;
			src_idx = src_y * src->size_line + src_x * src->bpp / 8;
			dst_idx = y * dst->size_line + x * dst->bpp / 8;
			dst->data[dst_idx] = src->data[src_idx];
			dst->data[dst_idx + 1] = src->data[src_idx + 1];
			dst->data[dst_idx + 2] = src->data[src_idx + 2];
			if (src->bpp == 32)
				dst->data[dst_idx + 3] = src->data[src_idx + 3];
		}
	}
}

void	load_walk_frames(t_vars *v)
{
	char		*paths[5];
	int			i;
	t_texture	tmp;

	paths[0] = "./frame/1.xpm";
	paths[1] = "./frame/2.xpm";
	paths[2] = "./frame/3.xpm";
	paths[3] = "./frame/4.xpm";
	paths[4] = "./frame/5.xpm";
	i = 0;
	while (i < NUM_WALK_FRAMES)
	{
		tmp.img = mlx_xpm_file_to_image(v->mlx, paths[i], &tmp.width,
				&tmp.height);
		if (tmp.img)
		{
			tmp.data = mlx_get_data_addr(tmp.img, &tmp.bpp, &tmp.size_line,
					&tmp.endian);
			scale_frame(v, &tmp, &v->walk_frames[i]);
			mlx_destroy_image(v->mlx, tmp.img);
		}
		i++;
	}
	v->current_frame = 0;
	v->frame_counter = 0;
}

static int	is_player_moving(t_vars *v)
{
	return (v->player.key_up || v->player.key_down || v->player.key_left
		|| v->player.key_right);
}

void	draw_walk_animation(t_vars *v)
{
	if (!is_player_moving(v))
	{
		v->frame_counter = 0;
		v->current_frame = 0;
	}
	else
	{
		v->frame_counter++;
		if (v->frame_counter >= FRAME_SPEED)
		{
			v->frame_counter = 0;
			v->current_frame = (v->current_frame + 1) % NUM_WALK_FRAMES;
		}
	}
	if (v->walk_frames[v->current_frame].img)
		mlx_put_image_to_window(v->mlx, v->win,
			v->walk_frames[v->current_frame].img, SPRITE_X, SPRITE_Y);
}
