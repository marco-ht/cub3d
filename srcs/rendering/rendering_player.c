/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:10:10 by mpierant &        #+#    #+#             */
/*   Updated: 2025/12/15 17:12:00 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	gettime(float *prev_time, float *time_diff, long *start_sec)
{
	struct timeval	tv;
	float			current_time;

	gettimeofday(&tv, NULL);
	if (*start_sec == 0)
		*start_sec = tv.tv_sec;
	current_time = (float)(tv.tv_sec - *start_sec) + (float)tv.tv_usec
		/ 1000000.0f;
	if (*prev_time == 0)
		*prev_time = 0.016f;
	*time_diff = current_time - *prev_time;
	*prev_time = current_time;
}

float	get_player_angle(char c)
{
	if (c == 'N')
		return (PI * 3 / 2);
	if (c == 'S')
		return (PI / 2);
	if (c == 'E')
		return (0);
	if (c == 'W')
		return (PI);
	return (0);
}

void	set_player_pos(t_player *player, char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'W'
				|| map[j][i] == 'E')
			{
				player->angle = get_player_angle(map[j][i]);
				player->x = i * BLOCK + BLOCK / 2;
				player->y = j * BLOCK + BLOCK / 2;
				return ;
			}
			i++;
		}
		j++;
	}
}

void	init_player(t_player *player, char **map)
{
	set_player_pos(player, map);
	player->key_up = 0;
	player->key_down = 0;
	player->key_left = 0;
	player->key_right = 0;
	player->key_rotleft = 0;
	player->key_rotright = 0;
	player->start_sec = 0;
	player->prev_time = 0;
}

void	set_texture(t_vars *v)
{
	double	wall_x;
	double	perp;

	if (!v->ray.side && v->ray.dir_x > 0)
		v->ray.current_texture = &v->ea;
	else if (!v->ray.side && v->ray.dir_x < 0)
		v->ray.current_texture = &v->we;
	else if (v->ray.side && v->ray.dir_y > 0)
		v->ray.current_texture = &v->so;
	else
		v->ray.current_texture = &v->no;
	if (v->ray.side == 0)
		perp = v->ray.dist_x - v->ray.delta_x;
	else
		perp = v->ray.dist_y - v->ray.delta_y;
	if (v->ray.side == 0)
		wall_x = (v->player.y / BLOCK) + perp * v->ray.dir_y;
	else
		wall_x = (v->player.x / BLOCK) + perp * v->ray.dir_x;
	wall_x -= floor(wall_x); // [0,1)
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

#include <string.h> //poi userò ft_memset di libft quando unisco con parser

void	clear_image(t_vars *v)
{
	size_t	bytes;

	bytes = (size_t)HEIGHT * v->size_line;
	memset(v->data, 0, bytes);
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

void	set_ray_2(t_vars *v)
{
	if (v->ray.dir_x < 0)
	{
		v->ray.step_x = -1;
		v->ray.dist_x = (v->ray.x - v->ray.map_x) * v->ray.delta_x;
	}
	else
	{
		v->ray.step_x = 1;
		v->ray.dist_x = (v->ray.map_x + 1.0 - v->ray.x) * v->ray.delta_x;
	}
	if (v->ray.dir_y < 0)
	{
		v->ray.step_y = -1;
		v->ray.dist_y = (v->ray.y - v->ray.map_y) * v->ray.delta_y;
	}
	else
	{
		v->ray.step_y = 1;
		v->ray.dist_y = (v->ray.map_y + 1.0 - v->ray.y) * v->ray.delta_y;
	}
}

void	set_ray(t_vars *v)
{
	v->ray.x = v->player.x / BLOCK;
	v->ray.y = v->player.y / BLOCK;
	v->ray.dir_x = cos(v->ray.angle);
	v->ray.dir_y = sin(v->ray.angle);
	v->ray.map_x = (int)v->ray.x;
	v->ray.map_y = (int)v->ray.y;
	if (fabs(v->ray.dir_x) < 1e-9)
		v->ray.delta_x = 1e30;
	else
		v->ray.delta_x = fabs(1.0 / v->ray.dir_x);
	if (fabs(v->ray.dir_y) < 1e-9)
		v->ray.delta_y = 1e30;
	else
		v->ray.delta_y = fabs(1.0 / v->ray.dir_y);
	set_ray_2(v);
}

void	advance_ray(t_vars *v)
{
	if (v->ray.dist_x < v->ray.dist_y)
	{
		v->ray.dist_x += v->ray.delta_x;
		v->ray.map_x += v->ray.step_x;
		v->ray.side = 0; // Muro Verticale
	}
	else
	{
		v->ray.dist_y += v->ray.delta_y;
		v->ray.map_y += v->ray.step_y;
		v->ray.side = 1; // Muro Orizzontale
	}
}

void	draw_h_line(float height, int line_x, t_vars *v)
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

void	draw_line(t_vars *v, int x)
{
	double	dist;
	float	height;
	int		wall_start_y;
	int		wall_end_y;

	set_ray(v);
	while (!stouch(v->map, v->ray.map_x, v->ray.map_y))
		advance_ray(v);
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
	draw_h_line(height, x, v);
	draw_floor(v, x, wall_end_y, HEIGHT - 1);
}

void	draw_lines(t_vars *v)
{
	int		i;
	float	fraction;

	v->ray.angle = v->player.angle - PI / 6;
	fraction = PI / 3 / WIDTH;
	i = 0;
	while (i < WIDTH)
	{
		draw_line(v, i);
		v->ray.angle += fraction;
		i++;
	}
}

int	loop_put_player(t_vars *v)
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
		draw_lines(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	return (0);
}

void	move_rot(t_player *player)
{
	if (player->key_rotleft)
		player->angle -= player->angle_speed;
	if (player->key_rotright)
		player->angle += player->angle_speed;
	if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
	if (player->angle < 0)
		player->angle += 2 * PI;
}

void	move_vert(t_player *player)
{
	if (player->key_up)
	{
		player->move_x += cos(player->angle) * player->speed;
		player->move_y += sin(player->angle) * player->speed;
	}
	if (player->key_down)
	{
		player->move_x -= cos(player->angle) * player->speed;
		player->move_y -= sin(player->angle) * player->speed;
	}
}

void	move_oriz(t_player *player)
{
	if (player->key_left)
	{
		player->move_x += sin(player->angle) * player->speed;
		player->move_y -= cos(player->angle) * player->speed;
	}
	if (player->key_right)
	{
		player->move_x -= sin(player->angle) * player->speed;
		player->move_y += cos(player->angle) * player->speed;
	}
}

void	move_player(t_player *player, char **map)
{
	player->speed = SPEED * player->time_diff;
	player->angle_speed = ANGLE_SPEED * player->time_diff;
	move_rot(player);
	player->move_x = 0;
	player->move_y = 0;
	move_vert(player);
	move_oriz(player);
	if (!touch(map, player->x + player->move_x, player->y))
		player->x += player->move_x;
	if (!touch(map, player->x, player->y + player->move_y))
		player->y += player->move_y;
}
