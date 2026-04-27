/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:13:46 by tkenji-u          #+#    #+#             */
/*   Updated: 2026/04/27 20:47:54 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_file(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nCould not open the file.\n");
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (ft_strncmp(line, "NO ", 3) == 0)
		{
			i = 2;
			while(line[i] == " ")
				i++;
			game->map.n_texture = ft_strtrim(&line[i], " \n");
		}
		if (ft_strncmp(line, "SO ", 3) == 0)
		{
			
		}
		if (ft_strncmp(line, "WE ", 3) == 0)
		{
			
		}
		if (ft_strncmp(line, "EA ", 3) == 0)
		{
			
		}
		printf("%s", line);
		free(line);
	}
	close(fd);
}

//teste