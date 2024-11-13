/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:09:22 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/13 20:25:26 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_texture(t_tex *texture, char *line)
{
	char	*path;

	path = ft_strtrim(line + 2, " ,'\n'");
	if (access(path, R_OK) == -1)
	{
		perror("Error: Invalid texture");
		free(path);
		return (0);
	}
	if (line[0] == 'N' && line[1] == 'O')
		texture->north_path = ft_strdup(path);
	if (line[0] == 'S' && line[1] == 'O')
		texture->south_path = ft_strdup(path);
	if (line[0] == 'W' && line[1] == 'E')
		texture->west_path = ft_strdup(path);
	if (line[0] == 'E' && line[1] == 'A')
		texture->east_path = ft_strdup(path);
	free(path);
	return (1);
}

int	load_texture(t_data *data, t_img *img, char *path)
{
	img->image = mlx_xpm_file_to_image(data->mlx, path,
			&img->width, &img->height);
	if (!img->image)
	{
		perror("Error: Could not load texture");
		return (0);
	}
	img->data = mlx_get_data_addr(img->image,
			&img->bpp, &img->size_line, &img->format);
	if (!img->data)
	{
		perror("Error: Failed to get image data");
		mlx_destroy_image(data->mlx, img->image);
		return (0);
	}
	return (1);
}

int	init_textures(t_data *data)
{
	if (!load_texture(data, &data->tex.north_img, data->tex.north_path))
		return (0);
	if (!load_texture(data, &data->tex.south_img, data->tex.south_path))
		return (0);
	if (!load_texture(data, &data->tex.west_img, data->tex.west_path))
		return (0);
	if (!load_texture(data, &data->tex.east_img, data->tex.east_path))
		return (0);
	return (1);
}
