/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:12:02 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/08 04:27:22 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_close(int keycode, t_vars *v)
{
	if (keycode == XK_Escape)
		ft_exitclean(v);
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
	mlx_key_hook(v->mlx_win, ft_close, v);
	mlx_loop(v->mlx);
}

//valgrind ./cub3D "maps/example.cub"
//valgrind --suppressions=mlx.supp ./cub3D maps/example.cub
