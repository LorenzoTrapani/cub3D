/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:39:03 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/01 14:35:17 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_keys(t_data *data)
{
	data->keys[0] = KEY_W;
	data->keys[1] = KEY_S;
	data->keys[2] = KEY_A;
	data->keys[3] = KEY_D;
	data->keys[4] = KEY_RIGHT;
	data->keys[5] = KEY_LEFT;
}
