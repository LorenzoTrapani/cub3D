#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>


/*-------FILE_VALIDATION-------*/
int file_validation(int argc, char **argv);
/*-------PARSE_MAP-------*/
int	parse_map(char *file);


#endif