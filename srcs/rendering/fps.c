/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:09:46 by mpierant &        #+#    #+#             */
/*   Updated: 2025/12/15 18:11:19 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	gettime(float *prev_time, float *time_diff, long *start_sec)
{
	struct timeval	tv;
	float			current_time;

	gettimeofday(&tv, NULL);
	if (*start_sec == 0)
		*start_sec = tv.tv_sec;
	current_time = (float)(tv.tv_sec - *start_sec) + (float)tv.tv_usec
		/ 1000000.0f;
	if (*prev_time == 0)
		*prev_time = 0.016f;
	*time_diff = current_time - *prev_time;
	*prev_time = current_time;
}
