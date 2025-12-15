/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:12:02 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/15 19:34:33 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_textures(t_vars *v)
{
	v->no.img = mlx_xpm_file_to_image(v->mlx, v->no.path, &v->no.width,
			&v->no.height);
	v->so.img = mlx_xpm_file_to_image(v->mlx, v->so.path, &v->so.width,
			&v->so.height);
	v->we.img = mlx_xpm_file_to_image(v->mlx, v->we.path, &v->we.width,
			&v->we.height);
	v->ea.img = mlx_xpm_file_to_image(v->mlx, v->ea.path, &v->ea.width,
			&v->ea.height);
	v->no.data = mlx_get_data_addr(v->no.img, &v->no.bpp, &v->no.size_line,
			&v->no.endian);
	v->so.data = mlx_get_data_addr(v->so.img, &v->so.bpp, &v->so.size_line,
			&v->so.endian);
	v->we.data = mlx_get_data_addr(v->we.img, &v->we.bpp, &v->we.size_line,
			&v->we.endian);
	v->ea.data = mlx_get_data_addr(v->ea.img, &v->ea.bpp, &v->ea.size_line,
			&v->ea.endian);
}

static void	init_mlx(t_vars *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WIDTH, HEIGHT, "Raycasting");
	v->img = mlx_new_image(v->mlx, WIDTH, HEIGHT);
	v->data = mlx_get_data_addr(v->img, &v->bpp, &v->size_line, &v->endian);
	init_textures(v);
}

static int	key_press(int keycode, t_vars *v)
{
	if (keycode == XK_Escape)
		ft_exitsucces(v);
	if (keycode == XK_w)
		v->player.key_up = 1;
	if (keycode == XK_s)
		v->player.key_down = 1;
	if (keycode == XK_a)
		v->player.key_left = 1;
	if (keycode == XK_d)
		v->player.key_right = 1;
	if (keycode == XK_Left)
		v->player.key_rotleft = 1;
	if (keycode == XK_Right)
		v->player.key_rotright = 1;
	return (0);
}

static int	key_release(int keycode, t_vars *v)
{
	if (keycode == XK_w)
		v->player.key_up = 0;
	if (keycode == XK_s)
		v->player.key_down = 0;
	if (keycode == XK_a)
		v->player.key_left = 0;
	if (keycode == XK_d)
		v->player.key_right = 0;
	if (keycode == XK_Left)
		v->player.key_rotleft = 0;
	if (keycode == XK_Right)
		v->player.key_rotright = 0;
	return (0);
}

void	ft_launch(t_vars *v)
{
	init_mlx(v);
	init_player(&v->player, v->map);
	mlx_loop_hook(v->mlx, loop_rendering, v);
	mlx_hook(v->win, 2, 1L << 0, key_press, v);
	mlx_hook(v->win, 3, 1L << 1, key_release, v);
	mlx_hook(v->win, 17, 0, ft_exitsucces, v);
	mlx_loop(v->mlx);
}

// valgrind ./cub3D "maps/example.cub"
// valgrind --suppressions=mlx.supp ./cub3D maps/example.cub
