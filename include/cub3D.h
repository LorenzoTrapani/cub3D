#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef	struct s_map
{
	char		**map_mtx;
	int			width;
	int			height;
}				t_map;


typedef struct s_data
{
	void		*mlx;
	int			fd;
	t_map		map;
}				t_data;


/*-------FILE_VALIDATION-------*/
int file_validation(t_data *data, int argc, char **argv);
/*-------PARSE_MAP-------*/
int	get_map(t_data *data, char *file);
void	cleanup(t_data *data);


#endif