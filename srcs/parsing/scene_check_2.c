/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_check_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:39:26 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/12 15:11:15 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_check_texture(char *value, t_vars *v, int fd)
{
	int	fd_txt;
	int	i;

	i = ft_strlen(value);
	if (!(i >= 5 && value[i - 4] == '.' && value[i - 3] == 'x' && value[i
			- 2] == 'p' && value[i - 1] == 'm'))
		return (printf("Error\nTextures must be .xpm files (and filename at least one char)\n"),
			printf("Therefore '%s' is not a valid texture file path\n", value),
			ft_free_gnl(fd), close(fd), ft_exitclean(v), 1);
	fd_txt = open(value, O_RDONLY);
	if (fd_txt == -1)
		return (printf("Error\nNot possible to open '%s' texture file\n",
				value), ft_free_gnl(fd), close(fd), ft_exitclean(v), 1);
	close(fd_txt);
	return (0);
}

void	ft_check_textures(t_vars *v, int fd)
{
	if (v->no[ft_strlen(v->no) - 1] == '\n')
		v->no[ft_strlen(v->no) - 1] = '\0';
	if (v->so[ft_strlen(v->so) - 1] == '\n')
		v->so[ft_strlen(v->so) - 1] = '\0';
	if (v->ea[ft_strlen(v->ea) - 1] == '\n')
		v->ea[ft_strlen(v->ea) - 1] = '\0';
	if (v->we[ft_strlen(v->we) - 1] == '\n')
		v->we[ft_strlen(v->we) - 1] = '\0';
	ft_check_texture(v->no, v, fd);
	ft_check_texture(v->so, v, fd);
	ft_check_texture(v->ea, v, fd);
	ft_check_texture(v->we, v, fd);
}
