/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:11:58 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/15 20:20:19 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	set_ray_2(t_vars *v)
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
		v->ray.side = 0;
	}
	else
	{
		v->ray.dist_y += v->ray.delta_y;
		v->ray.map_y += v->ray.step_y;
		v->ray.side = 1;
	}
}
