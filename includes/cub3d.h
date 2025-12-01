#ifndef CUB3D_H
# define CUB3D_H

# include <string.h> 
# include <fcntl.h> 
# include <stdlib.h>
# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h> 
# include <unistd.h> 

# define KEY_W	119
# define KEY_A	97
# define KEY_S	115
# define KEY_D	100

# define KEY_ESC	65307
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_UP		65362
# define KEY_DOWN	65364

# define SIZE_X	1200
# define SIZE_Y	800

# define TEX_SIZE	64

# define FLAG_NORTH	1
# define FLAG_SOUTH	2
# define FLAG_EAST 	4
# define FLAG_WEST	8
# define FLAG_F		16
# define FLAG_C		32
# define ALL_FLAGS	(FLAG_NORTH | FLAG_SOUTH | FLAG_EAST | \
					FLAG_WEST | FLAG_F | FLAG_C)

typedef enum	e_line
{
	LINE_EMPTY,
	LINE_TEX_NO,
	LINE_TEX_SO,
	LINE_TEX_WE,
	LINE_TEX_EA,
	LINE_COL_F,
	LINE_COL_C,
	LINE_MAP,
	LINE_INVALID
}	t_line;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	rgb;
}	t_color;

typedef struct s_text_data
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	t_color		floor_color;
	t_color		ceiling_color;
	int			parsed_flags;
}	t_text_data;

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

/*le type des variables est "double" parce que c'est le type qui vas
permettre la fluidite des mouvement du joeur */
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	rot_speed;
	double	move_speed;
}	t_player;

typedef struct s_map
{
	void		*mlx;
	void		*win;
	void		*img;
	char		**file_info;
	int			file_lines;
	char		**map_arr;
	int			map_h;
	int			map_w;
	char		*path_no;
	char		*path_so;
	char		*path_ea;
	char		*path_we;
	t_image		buffer;
	t_image		tex_north;
	t_image		tex_south;
	t_image		tex_east;
	t_image		tex_west;
	int			floor_color;
	int			ceiling_color;
	t_player	player;
}	t_map;

// ================================================================================
// 							SRCS
// ================================================================================
// ================================================================================
// 							PARSING
// ================================================================================
/**********************PARSE TEXTURES ET COLOR *****************************/
char	*extract_file_path(char *line);
int		parsed_text_files(char *line, t_text_data *data);
int		parse_rgb_values(char *line, t_color *color);
int		parsed_colors(char *line, t_text_data *data);
int		ckeck_all_elements_parsed(t_text_data *data);

/*****************************PARSE_TEX_COLOR*******************************/
int		parse_bef_map(char **file_info, t_text_data *data, int *map_start);

/*****************************PARSE_MAP**************************************/
int		parse_map(t_map *map, int map_start);

// ================================================================================
// 							PLAYER
// ================================================================================
int		init_player(t_map *map);
void	move_forward(t_map *map);
void	move_backward(t_map *map);
void	move_left(t_map *map);
void	move_right(t_map *map);
int		handle_keypress(int keycode, t_map *map);
void	rotate_left(t_map *map);
void	rotate_right(t_map *map);

/*****************************SETUP_GRAPHIC****************************************/
int		close_key_win(int keycode, t_map *map);
int		close_cross_win(t_map *map);
void	setup_graphic(t_map *map);
void	handle_events(t_map *map);

// ================================================================================
// 							UTILS
// ================================================================================
/*****************************UTILS_PARSE_FILE******************************/
void	free_textures(t_text_data *data);
void	cpy_texcol_to_map(t_map *map, t_text_data *data);

/*****************************UTILS_PARSE_TEXT_COLOR************************/
char	*skip_whitespaces(char *str);
int		file_exists(char *path);

/*****************************UTILS_ARGS_VERIF***************************************/
void	err_msg(char *msg);
int		is_cub_file(const char *file);

/*****************************UTILS_EXIT************************************/
void	*safe_malloc(size_t size);
void	free_and_exit(t_map *map, int status);

/*****************************UTILS_VERIF_MAP*******************************/
int		verif_elems_of_map(t_map *map);
int		verif_closed_map(t_map *map);

/*****************************UTILS_PARS_TYPE_DEF***************************/
int		is_empty_line(char *str);
int		is_player(char c);
int		is_map_char(char c);
int		is_map_line(char *line);
t_line	find_line_type(char *line);

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