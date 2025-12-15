/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:46:51 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/15 15:55:22 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	if (v->map)
		ft_free_map(v->map, v->map_size);
	if (v->map_cpy)
		ft_freemapcpy(v);
	if (v->no.img)
		mlx_destroy_image(v->mlx, v->no.img);
	if (v->so.img)
		mlx_destroy_image(v->mlx, v->so.img);
	if (v->we.img)
		mlx_destroy_image(v->mlx, v->we.img);
	if (v->ea.img)
		mlx_destroy_image(v->mlx, v->ea.img);
	if (v->img)
		mlx_destroy_image(v->mlx, v->img);
	if (v->win)
		mlx_destroy_window(v->mlx, v->win);
	if (v->mlx)
	{
		mlx_destroy_display(v->mlx);
		free(v->mlx);
	}
	printf("DEBUG: cleanup done.\n");
}
void	ft_exitclean(t_vars *v)
{
	printf("DEBUG: exit clean called.\n");
	ft_cleanup(v);
	exit(1);
}

int	ft_exitsucces(t_vars *v)
{
	printf("DEBUG: exit clean success called.\n");
	ft_cleanup(v);
	exit(0);
	return (0);
}

void	ft_init(t_vars *v)
{
	ft_memset(v, 0, sizeof(t_vars));
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	ft_free_gnl(int fd)
{
	char *str;

	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
}