#include "so_long.h"

int	file_len(char *path, t_mlx_params *mlx)
{
	int		fd;
	int		i;
	char	*line;

	if (ft_strncmp(&path[ft_strlen(path) - 4], ".ber", 5))
		error_handler(4, mlx, 2);
	fd = open(path, O_RDWR);
	if (fd < 0)
		error_handler(11, mlx, 2);
	i = 0;
	while (ft_get_next_line(fd, 10, &line))
	{
		free(line);
		i++;
	}
	free(line);
	i++;
	if (close(fd) < 0)
		error_handler(12, mlx, 2);
	return (i);
}

void	map_data_init(t_mlx_params *mlx, char *path)
{
	mlx->map->max_x = 0;
	mlx->map->max_y = 0;
	mlx->map->start_x = -1;
	mlx->map->start_y = -1;
	mlx->map->ratio = 50;
	mlx->map->file_len = file_len(path, mlx);
	mlx->file = ft_calloc(mlx->map->file_len + 1, sizeof(char *));
	mem_check(mlx->file, mlx, 2, 2);
}
