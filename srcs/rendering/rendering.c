/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:12:02 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/15 01:15:16 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_handle_key(int keycode, t_vars *v)
{
	if (keycode == XK_Escape)
		ft_exitsucces(v);
	if (keycode == XK_Left)
		printf("<-: look to left\n");
	if (keycode == XK_Right)
		printf("->: look to right\n");
	if (keycode == XK_w)
		printf("W: go forward\n");
	if (keycode == XK_s)
		printf("S: move back\n");
	if (keycode == XK_d)
		printf("D: go right\n");
	if (keycode == XK_a)
		printf("A: go left\n");
	return (0);
}

void	ft_launch(t_vars *v)
{
	int	w = 82;
	int	h = 80;
	
	v->mlx = mlx_init();
	v->mlx_win = mlx_new_window(v->mlx, 1920, 1080, "Hello world!");
	v->mlx_img = mlx_xpm_file_to_image(v->mlx, "textures/Water_tiles.xpm", &w , &h);
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->mlx_img,
				500, 500);
	mlx_key_hook(v->mlx_win, ft_handle_key, v);
	mlx_hook(v->mlx_win, 17, 0, ft_exitsucces, v);
	mlx_loop(v->mlx);
}

//valgrind ./cub3D "maps/example.cub"
//valgrind --suppressions=mlx.supp ./cub3D maps/example.cub
