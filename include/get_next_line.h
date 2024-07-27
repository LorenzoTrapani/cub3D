/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:02:42 by lotrapan          #+#    #+#             */
/*   Updated: 2024/04/25 19:13:19 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/******************************************************************************/
/*                      Definizione BUFFER_SIZE se non definito in altro modo */
/******************************************************************************/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
/******************************************************************************/
/*						Definizione FD_MAX se non definito in altro modo      */
/******************************************************************************/
# ifndef FD_MAX
#  define FD_MAX 4096
# endif
/******************************************************************************/
/*						Librerie di supporto								  */
/******************************************************************************/
# include "libft.h"
/******************************************************************************/
/*						Funzioni principale									  */
/******************************************************************************/
char	*ft_get_next_line(int fd);

#endif

/******************************************************************************/
/*                     	DESCRIZIONE											  */
/* File: get_next_line.c | get_next_line_utils.c | get_next_line.h  		  */
/* ---------------------													  */
/* Descrizione: 															  */
/* Questi file implementano la funzione get_next_line per la lettura		  */
/* incrementale da uno o piu' file descriptor.								  */
/*																			  */
/* Gestione FD:																  */
/* Il limite di 4096 file descriptor aperti è stato impostato per evitare	  */
/* l'esaurimento delle risorse del sistema. Tale limite è verificabile		  */
/* e configurabile attraverso il comando `ulimit`.							  */
/******************************************************************************/
