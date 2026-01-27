/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_loop_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:10:10 by mpierant &        #+#    #+#             */
/*   Updated: 2025/12/15 21:12:22 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	draw_wall_line(float height, int line_x, t_vars *v)
{
	int		end;
	int		dot_y;
	float	tex_step;
	double	tex_pos;

	dot_y = (HEIGHT - height) / 2;
	if (dot_y < 0)
		dot_y = 0;
	end = dot_y + height;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	tex_step = (float)v->ray.current_texture->height / (float)height;
	tex_pos = (dot_y - HEIGHT / 2 + height / 2) * tex_step;
	while (dot_y < end)
	{
		v->ray.tex_y = (int)tex_pos % v->ray.current_texture->height;
		if (v->ray.tex_y < 0)
			v->ray.tex_y += v->ray.current_texture->height;
		get_pixel_color_from_texture(v, v->ray.tex_x, v->ray.tex_y);
		put_pixel_nohex(v, line_x, dot_y, v->ray.current_pixel);
		tex_pos += tex_step;
		dot_y++;
	}
}

static void	draw_vertical_line(t_vars *v, int x)
{
	double	dist;
	float	height;
	int		wall_start_y;
	int		wall_end_y;
	char	hit_char;

	set_ray(v);
	while (!stouch(v->map, v->ray.map_x, v->ray.map_y))
		advance_ray(v);
	hit_char = v->map[v->ray.map_y][v->ray.map_x];
	v->ray.hit_door = (hit_char == 'D');
	if (v->ray.side == 0)
		dist = (v->ray.dist_x - v->ray.delta_x);
	else
		dist = (v->ray.dist_y - v->ray.delta_y);
	if (dist < 0.0001)
		dist = 0.0001;
	v->ray.dist_real = dist;
	dist *= cos(v->ray.angle - v->player.angle);
	if (dist < 0.0001)
		dist = 0.0001;
	height = HEIGHT / dist;
	wall_start_y = (HEIGHT - height) / 2;
	wall_end_y = wall_start_y + height;
	set_texture(v);
	draw_ceiling(v, x, 0, wall_start_y);
	draw_wall_line(height, x, v);
	draw_floor(v, x, wall_end_y, HEIGHT - 1);
}

static void	draw_vertical_lines(t_vars *v)
{
	int		i;
	float	fraction;

	v->ray.angle = v->player.angle - PI / 6;
	fraction = PI / 3 / WIDTH;
	i = 0;
	while (i < WIDTH)
	{
		draw_vertical_line(v, i);
		v->ray.angle += fraction;
		i++;
	}
}

int	loop_rendering(t_vars *v)
{
	gettime(&v->player.prev_time, &v->player.time_diff, &v->player.start_sec);
	move_player(&v->player, v->map);
	clear_image(v);
	if (DEBUG)
	{
		draw_player(v, 0x347434);
		draw_map(v);
		draw_rays(v, 0xFF0000);
	}
	else
	{
		draw_vertical_lines(v);
		draw_minimap(v);
		draw_miniplayer(v, 0x347434);
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	return (0);
}
