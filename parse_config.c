/* ************************************************************************** */
/*                           PARSE_CONFIG.C                                   */
/*               Parsing textures et couleurs - Version simple                */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Structure pour stocker les données de configuration
** SIMPLE : Un int pour tracker ce qui a été parsé
*/
typedef struct s_config
{
	// Chemins des textures
	char	*north_path;
	char	*south_path;
	char	*east_path;
	char	*west_path;
	
	// Couleurs
	int		floor_color;
	int		ceiling_color;
	
	// Flags pour savoir ce qui a été parsé (bit flags)
	int		parsed_flags;
}	t_config;

// Définitions pour les flags (optionnel, rend le code plus lisible)
#define FLAG_NORTH   (1 << 0)  // 0b000001
#define FLAG_SOUTH   (1 << 1)  // 0b000010
#define FLAG_EAST    (1 << 2)  // 0b000100
#define FLAG_WEST    (1 << 3)  // 0b001000
#define FLAG_FLOOR   (1 << 4)  // 0b010000
#define FLAG_CEILING (1 << 5)  // 0b100000
#define FLAG_ALL     0x3F      // 0b111111

/*
** Saute les espaces
*/
static char	*skip_whitespace(char *str)
{
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}

/*
** Extrait un chemin de fichier
*/
static char	*extract_file_path(char *line)
{
	char	*start;
	char	*end;
	int		len;
	char	*path;
	
	start = skip_whitespace(line);
	end = start;
	
	while (*end && *end != ' ' && *end != '\t' && *end != '\n')
		end++;
	
	len = end - start;
	path = malloc(len + 1);
	if (!path)
		return (NULL);
	
	ft_strlcpy(path, start, len + 1);
	return (path);
}

/*
** Vérifie qu'un fichier existe
*/
static int	file_exists(char *path)
{
	int	fd;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

/*
** Parse une ligne de texture (NO, SO, EA, WE)
*/
int	parse_texture(char *line, t_config *config)
{
	char	*path;
	
	line = skip_whitespace(line);
	
	// North
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (config->parsed_flags & FLAG_NORTH)
			return (err_msg("Duplicate NO"), -1);
		path = extract_file_path(line + 3);
		if (!path || !file_exists(path))
			return (free(path), err_msg("Invalid NO path"), -1);
		config->north_path = path;
		config->parsed_flags |= FLAG_NORTH;
		return (1);
	}
	// South
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (config->parsed_flags & FLAG_SOUTH)
			return (err_msg("Duplicate SO"), -1);
		path = extract_file_path(line + 3);
		if (!path || !file_exists(path))
			return (free(path), err_msg("Invalid SO path"), -1);
		config->south_path = path;
		config->parsed_flags |= FLAG_SOUTH;
		return (1);
	}
	// East
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (config->parsed_flags & FLAG_EAST)
			return (err_msg("Duplicate EA"), -1);
		path = extract_file_path(line + 3);
		if (!path || !file_exists(path))
			return (free(path), err_msg("Invalid EA path"), -1);
		config->east_path = path;
		config->parsed_flags |= FLAG_EAST;
		return (1);
	}
	// West
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (config->parsed_flags & FLAG_WEST)
			return (err_msg("Duplicate WE"), -1);
		path = extract_file_path(line + 3);
		if (!path || !file_exists(path))
			return (free(path), err_msg("Invalid WE path"), -1);
		config->west_path = path;
		config->parsed_flags |= FLAG_WEST;
		return (1);
	}
	
	return (0);
}

/*
** Parse RGB "R,G,B"
*/
int	parse_rgb_color(char *line)
{
	char	**split;
	int		r, g, b;
	int		i;
	
	line = skip_whitespace(line);
	split = ft_split(line, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
	{
		i = 0;
		while (split && split[i])
			free(split[i++]);
		free(split);
		return (err_msg("Invalid RGB format"), -1);
	}
	
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (err_msg("RGB values must be 0-255"), -1);
	
	return ((r << 16) | (g << 8) | b);
}

/*
** Parse une ligne de couleur (F ou C)
*/
int	parse_color(char *line, t_config *config)
{
	int	color;
	
	line = skip_whitespace(line);
	
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (config->parsed_flags & FLAG_FLOOR)
			return (err_msg("Duplicate F"), -1);
		color = parse_rgb_color(line + 2);
		if (color == -1)
			return (-1);
		config->floor_color = color;
		config->parsed_flags |= FLAG_FLOOR;
		return (1);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (config->parsed_flags & FLAG_CEILING)
			return (err_msg("Duplicate C"), -1);
		color = parse_rgb_color(line + 2);
		if (color == -1)
			return (-1);
		config->ceiling_color = color;
		config->parsed_flags |= FLAG_CEILING;
		return (1);
	}
	
	return (0);
}

/*
** Parse une ligne (texture ou couleur)
*/
int	parse_config_line(char *line, t_config *config)
{
	int	result;
	
	if (!line || *line == '\n' || *line == '\0')
		return (0);
	
	result = parse_texture(line, config);
	if (result != 0)
		return (result);
	
	result = parse_color(line, config);
	return (result);
}

/*
** Vérifie que tout a été parsé
*/
int	check_config_complete(t_config *config)
{
	if (config->parsed_flags != FLAG_ALL)
	{
		if (!(config->parsed_flags & FLAG_NORTH))
			return (err_msg("Missing NO"), -1);
		if (!(config->parsed_flags & FLAG_SOUTH))
			return (err_msg("Missing SO"), -1);
		if (!(config->parsed_flags & FLAG_EAST))
			return (err_msg("Missing EA"), -1);
		if (!(config->parsed_flags & FLAG_WEST))
			return (err_msg("Missing WE"), -1);
		if (!(config->parsed_flags & FLAG_FLOOR))
			return (err_msg("Missing F"), -1);
		if (!(config->parsed_flags & FLAG_CEILING))
			return (err_msg("Missing C"), -1);
	}
	
	printf("✓ Config complete\n");
	return (0);
}
