/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:03:59 by lotrapan          #+#    #+#             */
/*   Updated: 2024/04/11 17:38:05 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (('0' <= c && c <= '9'))
		return (1);
	return (0);
}

/*DESCRIPTION
       These functions check whether c, which must have the value
       of an unsigned char or EOF, falls into a certain character
       class according to the specified  locale.
		 isdigit()
              checks for a digit (0 through 9).

RETURN VALUE
       The values returned are nonzero if the character  c  falls
       into the tested class, and zero if not.
-------------------------------------------------------------------------------
#include <stdio.h>

int	main(void) {
    char testChar;
    // Test ft_isdigit
    testChar = '5';
    printf("ft_isdigit('%c') = %d\n", testChar, ft_isdigit(testChar));
    return (0);
}
*/