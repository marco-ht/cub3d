/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:09:32 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/05 07:23:28 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_parse(t_vars *v)
{
	int	fd;

	ft_extension(v);
	fd = open(v->scene, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nOpening .cub file\n"), ft_exitclean(v), 1);
	ft_parse_fields(v, fd);
	//ft_parse_map(v, fd);
	close(fd);
	return (0);
}
