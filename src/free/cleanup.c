/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:04:52 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/13 20:07:12 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_texture(void *mlx, t_tex *tex)
{
	if (tex->north_img.image)
		mlx_destroy_image(mlx, tex->north_img.image);
	if (tex->south_img.image)
		mlx_destroy_image(mlx, tex->south_img.image);
	if (tex->west_img.image)
		mlx_destroy_image(mlx, tex->west_img.image);
	if (tex->east_img.image)
		mlx_destroy_image(mlx, tex->east_img.image);
	if (tex->north_path)
		free(tex->north_path);
	if (tex->south_path)
		free(tex->south_path);
	if (tex->west_path)
		free(tex->west_path);
	if (tex->east_path)
		free(tex->east_path);
	tex->north_path = NULL;
	tex->south_path = NULL;
	tex->west_path = NULL;
	tex->east_path = NULL;
}

void	cleanup(t_data *data)
{
	if (data->map.map_mtx)
		ft_free_matrix(data->map.map_mtx);
	free_texture(data->mlx, &data->tex);
}
