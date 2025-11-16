#include "cub3d.h"

size_t	ft_countlines(char const *s, char c)
{
	int	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char    *append_and_free(char *fcontent, char *read_buf)
{
    char    *new_fcontent;
    
    if (!fcontent)
        return (ft_strdup(read_buf));
    new_fcontent = ft_strjoin(fcontent, read_buf);
    if (!new_fcontent)
        return (free(fcontent), NULL);
    free(fcontent);
    return (new_fcontent);
}

char    *save_file_content(const char *file)
{
    int     fd;
    char    read_buf[4096 + 1];
    size_t    already_read;
    char    *fcontent;
    
    fcontent = NULL;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (err_msg("cannot open file"), NULL);
    already_read = read(fd, read_buf, 4096);
    while (already_read > 0)
    {
        read_buf[already_read] = '\0';
        fcontent = append_and_free(fcontent, read_buf);
        if (!fcontent)
            return (close(fd), NULL);
        already_read = read(fd, read_buf, 4096);
    }
    close (fd);
    return (fcontent);
}

int init_file_info(t_map *map, const char *file)
{
    char    *fcontent;

    fcontent = save_file_content(file);
    if (!fcontent)
        return (-1);
    map->file_info = ft_split(fcontent, '\n');
    map->file_lines = ft_countlines(fcontent, '\n');
    free(fcontent);
    if (!map->file_info)
        return (-1);
    return (0);
}

void	print_arr(t_map *map)
{
    for (int i = 0; i < map->file_lines; i++)
		printf("line[%d] : %s\n", i, map->file_info[i]);
}

int main(int ac, char **av)
{
    t_map   map;
   
    (void) av;
    ft_memset(&map, 0, sizeof(t_map));
    if (ac != 2)
        return (err_msg("wrong number of args"), -1);
    if (is_cub_file(av[1]) == 0)
        return (err_msg("bad file name"), -1);
    if (init_file_info(&map, av[1]) == -1)
        return (err_msg("file_info init"), -1);
    print_arr(&map);
    // PARSE MAP part (map, fd)
    map.floor_color = create_color(128, 0, 128);
	map.ceiling_color = create_color(135, 206, 235); 
    setup_graphic(&map);
    if (load_all_textures(&map) == -1)
		return (err_msg("Error to load textures"), -1);
    test_display_textures(&map);
    handle_events(&map);
    return (0);
}