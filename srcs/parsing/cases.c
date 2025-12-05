/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 00:35:17 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/05 00:52:11 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_isno(int i, int j, char *str)
{
	return (str[i] && str[i] != '\n' && str[j] && str[j + 1] && str[j + 2]
		&& str[j] == 'N' && str[j + 1] == 'O' && str[j + 2] == ' ');
}

int	ft_isso(int i, int j, char *str)
{
	return (str[i] && str[i] != '\n' && str[j] && str[j + 1] && str[j + 2]
		&& str[j] == 'S' && str[j + 1] == 'O' && str[j + 2] == ' ');
}

int	ft_iswe(int i, int j, char *str)
{
	return (str[i] && str[i] != '\n' && str[j] && str[j + 1] && str[j + 2]
		&& str[j] == 'W' && str[j + 1] == 'E' && str[j + 2] == ' ');
}

int	ft_isea(int i, int j, char *str)
{
	return (str[i] && str[i] != '\n' && str[j] && str[j + 1] && str[j + 2]
		&& str[j] == 'E' && str[j + 1] == 'A' && str[j + 2] == ' ');
}
