/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:03:52 by lotrapan          #+#    #+#             */
/*   Updated: 2024/02/21 18:14:40 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}

/*DESCRIPTION
       These functions check whether c, which must have the value
       of an unsigned char or EOF, falls into a certain character
       class according to the specified  locale.
		isascii()
              checks whether c is a  7-bit  unsigned  char  value
              that fits into the ASCII character set.

RETURN VALUE
       The values returned are nonzero if the character  c  falls
       into the tested class, and zero if not.
-------------------------------------------------------------------------------
#include <stdio.h>

int	main(void) {
    char testChar;
    // Test ft_isascii
    testChar = 127;  // maximum ASCII value
    printf("ft_isascii('%c') = %d\n", testChar, ft_isascii(testChar));
    return (0);
}
*/