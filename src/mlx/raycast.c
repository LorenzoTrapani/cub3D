/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:55:53 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/12 14:59:05 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_planes(double *plane_x, double *plane_y, t_data *data)
{
	const double plane_limit = 0.7;
	*plane_x = -data->player.dir_y * plane_limit;
	*plane_y = data->player.dir_x * plane_limit;
}
