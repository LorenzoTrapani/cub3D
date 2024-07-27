/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:03:39 by lotrapan          #+#    #+#             */
/*   Updated: 2024/02/21 18:14:40 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*DESCRIPTION
       These functions check whether c, which must have the value
       of an unsigned char or EOF, falls into a certain character
       class according to the specified  locale.
		isalnum()
              checks for an alphanumeric character; it is equiva‐
              lent to (isalpha(c) || isdigit(c)).

RETURN VALUE
       The values returned are nonzero if the character  c  falls
       into the tested class, and zero if not.
-------------------------------------------------------------------------------
#include <stdio.h>

int	main(void) {
    char testChar;
    // Test ft_isalnum
    testChar = 'A';
    printf("ft_isalnum('%c') = %d\n", testChar, ft_isalnum(testChar));
    return (0);
}
*/