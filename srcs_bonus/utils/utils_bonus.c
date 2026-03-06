/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:46:51 by mpierant          #+#    #+#             */
/*   Updated: 2026/03/06 17:07:06 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

#ifndef __APPLE__
# define MLX_EXTRA_CLEANUP 1
#else
# define MLX_EXTRA_CLEANUP 0

void	mlx_destroy_display(void *mlx); /* stub per compilazione */

#endif

static void	ft_cleanup3(t_vars *v)
{
	int	i;

	i = -1;
	while (++i < NUM_WALK_FRAMES)
		if (v->walk_frames[i].img)
			mlx_destroy_image(v->mlx, v->walk_frames[i].img);
	if (v->img)
		mlx_destroy_image(v->mlx, v->img);
	if (v->win)
		mlx_destroy_window(v->mlx, v->win);
}

static void	ft_cleanup2(t_vars *v)
{
	if (v->map)
		ft_free_map(v->map, v->map_size);
	if (v->map_cpy)
		ft_freemapcpy(v);
	if (v->mlx)
	{
		if (v->no.img)
			mlx_destroy_image(v->mlx, v->no.img);
		if (v->so.img)
			mlx_destroy_image(v->mlx, v->so.img);
		if (v->we.img)
			mlx_destroy_image(v->mlx, v->we.img);
		if (v->ea.img)
			mlx_destroy_image(v->mlx, v->ea.img);
		if (v->door.img)
			mlx_destroy_image(v->mlx, v->door.img);
		ft_cleanup3(v);
	}
	if (MLX_EXTRA_CLEANUP && v->mlx)
	{
		mlx_destroy_display(v->mlx);
		free(v->mlx);
	}
}

void	ft_cleanup(t_vars *v)
{
	if (v->scene)
		free(v->scene);
	if (v->no.path)
		free(v->no.path);
	if (v->so.path)
		free(v->so.path);
	if (v->we.path)
		free(v->we.path);
	if (v->ea.path)
		free(v->ea.path);
	if (v->fl)
		free(v->fl);
	if (v->ce)
		free(v->ce);
	ft_cleanup2(v);
}

void	ft_exitclean(t_vars *v)
{
	ft_cleanup(v);
	exit(1);
}

int	ft_exitsucces(t_vars *v)
{
	mlx_mouse_show(v->mlx, v->win);
	ft_cleanup(v);
	exit(0);
	return (0);
}
