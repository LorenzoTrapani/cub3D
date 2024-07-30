/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:04:52 by lotrapan          #+#    #+#             */
/*   Updated: 2024/07/30 15:43:10 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_texture(t_tex *tex)
{
	if (tex && tex->north)
		free(tex->north);
	if (tex && tex->south)
		free(tex->south);
	if (tex && tex->west)
		free(tex->west);
	if (tex && tex->east)
		free(tex->east);
}

void	cleanup(t_data *data)
{
	if (data->map.map_mtx)
		ft_free_matrix(data->map.map_mtx);
	free_texture(&data->tex);
}
