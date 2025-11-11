/* for the image we will need to know bpp(bits per pixel info), */

#include <string.h> 
// strerror, char *strerror(int errnum);
#include <fcntl.h> 
// open, int open(const char *pathname, int flags, mode_t mode);
#include <stdlib.h>
// exit, void exit(int status);
#include "libft.h"
#include <math.h>
#include <mlx.h>
#include <stdio.h> 
#include <unistd.h> 
//  close, int close(int fd); ssize_t read(int fd, void *buf, size_t count);

# define SIZE_X 1200
# define SIZE_Y 800

typedef struct  s_map
{
    void    *mlx;
    void    *win;
    void    *img;

}   t_map;

/*int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}*/

void    setup_graphic(t_map *map)
{
    map->mlx = mlx_init();
    // void *mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );
    map->win = mlx_new_window(map->mlx, SIZE_X, SIZE_Y, "cub3d");
    // clear window ?
    map->img = mlx_new_image(map->mlx, SIZE_X, SIZE_Y);

}

int main(int ac, char **av)
{
    t_map   map;
    //int     fd;
   
    (void) av;
    if (ac != 2)
        return (strerror(5), -1);
    /*    // open file .cub
    if (av[1])
    { 
        if (ft_strcmp(av[1], ".cub") != 0)
            return (strerror(5), -1);
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
            return (strerror(9), -1);
    }*/
    setup_graphic(&map);
    mlx_loop(map.mlx);
    // int mlx_loop ( void *mlx_ptr );
    //close(fd);
    return (0);
}