/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:38:59 by mpierant &        #+#    #+#             */
/*   Updated: 2026/03/07 15:48:49 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	scale_frame(t_vars *v, t_texture *src, t_texture *dst)
{
	t_frame	f;

	dst->img = mlx_new_image(v->mlx, SPRITE_WIDTH, SPRITE_HEIGHT);
	dst->data = mlx_get_data_addr(dst->img, &dst->bpp, &dst->size_line,
			&dst->endian);
	f.y = -1;
	while (++f.y < SPRITE_HEIGHT)
	{
		f.x = -1;
		while (++f.x < SPRITE_WIDTH)
		{
			f.src_x = f.x * src->width / SPRITE_WIDTH;
			f.src_y = f.y * src->height / SPRITE_HEIGHT;
			f.src_idx = f.src_y * src->size_line + f.src_x * src->bpp / 8;
			f.dst_idx = f.y * dst->size_line + f.x * dst->bpp / 8;
			dst->data[f.dst_idx] = src->data[f.src_idx];
			dst->data[f.dst_idx + 1] = src->data[f.src_idx + 1];
			dst->data[f.dst_idx + 2] = src->data[f.src_idx + 2];
			if (src->bpp == 32)
				dst->data[f.dst_idx + 3] = src->data[f.src_idx + 3];
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
	int	sprite_x;

	sprite_x = WIDTH - SPRITE_WIDTH - 18;
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
			v->walk_frames[v->current_frame].img, sprite_x, SPRITE_Y);
}
