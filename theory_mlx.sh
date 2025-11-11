
STEP 1:
# to launch window we will need to initialize mlx, and create a new window:
# principaly, do not forget to loop mlx  to initiate the window rendering(performance)

void  *mlx_init();
# The mlx_init() function will create this connection. No parameters are needed, and it will 
# return a void* identifier, used for further calls to the library routines.
void *mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );



STEP 2: 

void *mlx_new_image ( void *mlx_ptr, int width, int height );
# mlx_new_image() creates a new image in memory;
# return value: It returns a void * identifier needed to manipulate this image later.

char *mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );
# mlx_get_data_addr() returns information about the created image, allowing a user to modify it later.

