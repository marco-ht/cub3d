/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:09:32 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/15 19:06:56 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_parse(t_vars *v)
{
	int	fd;

	ft_extension(v);
	fd = open(v->scene, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nNot possible to open .cub file\n%s\n",
				strerror(errno)), ft_exitclean(v), 1);
	ft_parse_fields(v, fd);
	ft_parse_map(v, fd);
	close(fd);
	ft_checkmap(v);
	return (0);
}
