/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:06:51 by lotrapan          #+#    #+#             */
/*   Updated: 2024/07/29 13:06:55 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){0};
	if (!file_validation(&data, argc, argv))
		return (0);
	cleanup(&data);
	return (1);
}
