/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_check_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:39:26 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/15 21:25:10 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	ft_check_texture(char *value, t_vars *v, int fd)
{
	int	fd_txt;
	int	i;

	i = ft_strlen(value);
	if (!(i >= 5 && value[i - 4] == '.' && value[i - 3] == 'x'
			&& value[i - 2] == 'p' && value[i - 1] == 'm'))
		return (printf("Error\nTextures must be .xpm files "),
			printf("(and filename at least one char)\n"),
			printf("Therefore '%s' is not a valid texture file path\n", value),
			ft_free_gnl(fd), close(fd), ft_exitclean(v), 1);
	fd_txt = open(value, O_RDONLY);
	if (fd_txt == -1)
		return (printf("Error\nNot possible to open '%s' texture file\n%s\n",
				value, strerror(errno)), ft_free_gnl(fd), close(fd),
			ft_exitclean(v), 1);
	close(fd_txt);
	return (0);
}

void	ft_check_textures(t_vars *v, int fd)
{
	if (v->no.path[ft_strlen(v->no.path) - 1] == '\n')
		v->no.path[ft_strlen(v->no.path) - 1] = '\0';
	if (v->so.path[ft_strlen(v->so.path) - 1] == '\n')
		v->so.path[ft_strlen(v->so.path) - 1] = '\0';
	if (v->ea.path[ft_strlen(v->ea.path) - 1] == '\n')
		v->ea.path[ft_strlen(v->ea.path) - 1] = '\0';
	if (v->we.path[ft_strlen(v->we.path) - 1] == '\n')
		v->we.path[ft_strlen(v->we.path) - 1] = '\0';
	ft_check_texture(v->no.path, v, fd);
	ft_check_texture(v->so.path, v, fd);
	ft_check_texture(v->ea.path, v, fd);
	ft_check_texture(v->we.path, v, fd);
}
