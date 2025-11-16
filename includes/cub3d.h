#ifndef CUB3D_H
# define CUB3D_H

/* for the image we will need to know bpp(bits per pixel info), */
# include <string.h> 
// strerror, char *strerror(int errnum);
# include <fcntl.h> 
// open, int open(const char *pathname, int flags, mode_t mode);
# include <stdlib.h>
// exit, void exit(int status);
# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h> 
# include <unistd.h> 
//  close, int close(int fd); ssize_t read(int fd, void *buf, size_t count);

# define SIZE_X 1200
# define SIZE_Y 800

# define TEX_SIZE 64

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_map
{
	void    *mlx;
	void    *win;
	void    *img;
	char	**file_info;
	int		file_lines;
	t_image	buffer;
	t_image	tex_north;
	t_image	tex_south;
	t_image	tex_east;
	t_image	tex_west;
	int		floor_color;
	int		ceiling_color;	
}	t_map;

// ================================================================================
// 							SRCS
// ================================================================================

/*****************************SETUP_GRAPHIC****************************************/

int    	close_key_win(int keycode, t_map *map);
int     close_cross_win(t_map *map);
void    setup_graphic(t_map *map);
void    handle_events(t_map *map);

// ================================================================================
// 							UTILS
// ================================================================================

/*****************************UTILS_ARGS_VERIF***************************************/
void    err_msg(char *msg);
int 	is_cub_file(const char *file);

/*****************************UTILS_EXIT*********************************************/
void    free_and_exit(t_map *map, int status);

/*****************************COPY_FILE_CONTENT**************************************/
int		init_file_info(t_map *map, const char *file);

/****************************TEXTURES************************************************/
int		load_texture(t_map *map, char *path, t_image *texture);
int		load_all_textures(t_map *map);
int		create_color(int r, int g, int b);

/*****************************BUFFER************************************************/
int		init_buffer(t_map *map);
void	put_pixel_to_buffer(t_image *buffer, int x, int y, int color);
int		get_pixel_from_texture(t_image *texture, int x, int y);
void	display_buffer(t_map *map);

/****************************POUR  TESTÉ A EFFACER APRES****************************/
void	test_display_textures(t_map *map);

#endif