/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:04:52 by lotrapan          #+#    #+#             */
/*   Updated: 2024/07/29 18:04:04 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_texture(t_tex *tex)
{
	if (tex->north)
	{
		free(tex->north);
	}
	if (tex->south)
	{
		free(tex->south);
	}
	if (tex->west)
	{
		free(tex->west);
	}
	if (tex->east)
	{
		free(tex->east);
	}
}
void	cleanup(t_data *data)
{
	ft_free_matrix(data->map.map_mtx);
	free_texture(&data->tex);
}
