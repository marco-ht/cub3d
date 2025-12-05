/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:55:47 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/05 06:31:51 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_extension(t_vars *v)
{
	int	i;

	i = 0;
	while (v->scene[i])
		i++;
	if (i >= 5 && v->scene[i - 4] == '.' && v->scene[i - 3] == 'c' && v->scene[i
		- 2] == 'u' && v->scene[i - 1] == 'b')
		return ;
	printf("Error\nExtension must be .cub\n");
	ft_exitclean(v);
}

static int	ft_check_format_f(t_vars *v, int fd)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (k < 3)
	{
		while (ft_isdigit(v->fl[i]))
			i++;
		if (i - j < 1 || i - j > 3)
			return (printf("Error\nInvalid floor colour format\n"),
				ft_free_gnl(fd), close(fd), ft_exitclean(v), 1);
		if ((k < 2 && v->fl[i] != ',') || (k == 2 && v->fl[i] != '\n'))
			return (printf("Error\nInvalid floor colour format\n"),
				ft_free_gnl(fd), close(fd), ft_exitclean(v), 1);
		else if (k < 2)
			i++;
		j = i;
		k++;
	}
	return (0);
}

static int	ft_check_format_c(t_vars *v, int fd)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (k < 3)
	{
		while (ft_isdigit(v->ce[i]))
			i++;
		if (i - j < 1 || i - j > 3)
			return (printf("Error\nInvalid ceiling colour format\n"),
				ft_free_gnl(fd), close(fd), ft_exitclean(v), 1);
		if ((k < 2 && v->ce[i] != ',') || (k == 2 && v->ce[i] != '\n'))
			return (printf("Error\nInvalid ceiling colour format\n"),
				ft_free_gnl(fd), close(fd), ft_exitclean(v), 1);
		else if (k < 2)
			i++;
		j = i;
		k++;
	}
	return (0);
}

void	ft_check_format(t_vars *v, int fd)
{
	ft_check_format_c(v, fd);
	ft_check_format_f(v, fd);
}

int	ft_check_values(t_vars *v, int fd)
{
	if (v->f[0] < 0 || v->f[0] > 255 || v->f[1] < 0 || v->f[1] > 255
		|| v->f[2] < 0 || v->f[2] > 255)
		return (printf("Error\nInvalid floor colour values. Range is [0,255]\n"),
			ft_free_gnl(fd), close(fd), ft_exitclean(v), 1);
	if (v->c[0] < 0 || v->c[0] > 255 || v->c[1] < 0 || v->c[1] > 255
		|| v->c[2] < 0 || v->c[2] > 255)
		return (printf("Error\nInvalid ceiling colour values. Range is [0,255]\n"),
			ft_free_gnl(fd), close(fd), ft_exitclean(v), 1);
	return (0);
}
