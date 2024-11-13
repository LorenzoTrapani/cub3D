/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:55:53 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/13 17:08:19 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_planes(t_data *data)
{
	const double	plane_limit = FOV;

	data->ray.plane_x = -data->player.dir_y * plane_limit;
	data->ray.plane_y = data->player.dir_x * plane_limit;
}

void	calculate_ray_direction(t_data *data, double camera_x)
{
	data->ray.ray_dir_x = data->player.dir_x + data->ray.plane_x * camera_x;
	data->ray.ray_dir_y = data->player.dir_y + data->ray.plane_y * camera_x;
}

void	calculate_delta_distance(t_data *data)
{
	data->ray.delta_dist_x = INT_MAX;
	data->ray.delta_dist_y = INT_MAX;
	if (data->ray.ray_dir_x != 0)
		data->ray.delta_dist_x = fabs(1.0 / data->ray.ray_dir_x);
	if (data->ray.ray_dir_y != 0)
		data->ray.delta_dist_y = fabs(1.0 / data->ray.ray_dir_y);
}

void	init_step_and_side_dist(t_data *data, t_raycasting *ray)
{
	ray->map_x = (int)data->player.x;
	ray->map_y = (int)data->player.y;
	ray->step_x = 1;
	ray->step_y = 1;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_d_x = (data->player.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_d_x = (ray->map_x + 1.0 - data->player.x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_d_y = (data->player.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_d_y = (ray->map_y + 1.0 - data->player.y) * ray->delta_dist_y;
	}
}

t_img	*selected_texture(t_data *data)
{
	t_img	*texture;

	if (data->ray.wall_dir == NORTH)
		texture = &data->tex.north_img;
	else if (data->ray.wall_dir == SOUTH)
		texture = &data->tex.south_img;
	else if (data->ray.wall_dir == WEST)
		texture = &data->tex.west_img;
	else
		texture = &data->tex.east_img;
	return (texture);
}

int get_texture_color(t_data *data, int tex_x, double tex_pos)
{
    int tex_y;
    int color;
    t_img *texture;

    // Seleziona la texture corretta in base alla direzione del raggio
    texture = selected_texture(data);

    // Calcola la coordinata Y attuale nella texture
    tex_y = (int)tex_pos & (TEX_HEIGHT - 1);

    // Recupera il colore del pixel dalla texture alla posizione (tex_x, tex_y)
    int pixel_offset = (tex_y * texture->size_line) + (tex_x * (texture->bpp / 8));
    color = *(int *)(texture->data + pixel_offset);

    return color;
}


void	render_wall_column(t_data *data, int x)
{
	double	camera_x;
	int		wall_height;
	int		wall_top;
	int		wall_bottom;

	camera_x = 2.0 * x / (double)WIN_WIDTH - 1.0;
	calculate_ray_direction(data, camera_x);
	calculate_delta_distance(data);
	init_step_and_side_dist(data, &data->ray);
	perform_dda(data, &data->ray);
	if (data->ray.perp_wall_dist < 0.001)
		data->ray.perp_wall_dist = 0.001;
	wall_height = (int)(WIN_HEIGHT / data->ray.perp_wall_dist);
	calculate_wall_limits(wall_height, &wall_top, &wall_bottom);
	/* while (wall_top <= wall_bottom)
	{
		draw_pixel(data->img, x, wall_top, get_texture_color(data, x, wall_top, wall_bottom));
		wall_top++;
	} */
	double step = (double)TEX_HEIGHT / wall_height;
    double tex_pos = (wall_top < 0 ? 0 : wall_top - WIN_HEIGHT / 2 + wall_height / 2) * step;

    // Calcola la coordinata X nella texture (da 0 a TEX_WIDTH - 1) in base al punto di impatto del raggio
    double hit_point;
    if (data->ray.side == 0) // Colpito un lato verticale
        hit_point = data->player.y + data->ray.perp_wall_dist * data->ray.ray_dir_y;
    else                      // Colpito un lato orizzontale
        hit_point = data->player.x + data->ray.perp_wall_dist * data->ray.ray_dir_x;

    hit_point -= floor(hit_point);
    int tex_x = (int)(hit_point * TEX_WIDTH);

    // Disegna ogni pixel della colonna del muro
    for (int y = wall_top; y <= wall_bottom; y++)
    {
        if (y >= 0 && y < WIN_HEIGHT)  // Assicurati di disegnare solo all'interno della finestra
        {
            int color = get_texture_color(data, tex_x, tex_pos);
            draw_pixel(data->img, x, y, color);
        }
        tex_pos += step; // Avanza nella texture per ogni riga della colonna
    }
}
