/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagouemura <thiagouemura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:13:46 by tkenji-u          #+#    #+#             */
/*   Updated: 2026/04/28 09:57:21 by thiagouemur      ###   ########.fr       */
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
		printf("Error\nCould not open the file.\n");
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (ft_strncmp(line, "NO ", 3) == 0)
		{
			if (game->map.n_texture != NULL)
			{
				printf("Error\nDuplicate texture for NO.\n");
				exit(1);
			}
			i = 2;
			while(line[i] == ' ')
				i++;
			game->map.n_texture = ft_strtrim(&line[i], " \n");
		}
		if (ft_strncmp(line, "SO ", 3) == 0)
		{
			if (game->map.s_texture != NULL)
			{
				printf("Error\nDuplicate texture for SO.\n");
				exit(1);
			}
			i = 2;
			while(line[i] == ' ')
				i++;
			game->map.s_texture = ft_strtrim(&line[i], " \n");
		}
		if (ft_strncmp(line, "WE ", 3) == 0)
		{
			if (game->map.n_texture != NULL)
			{
				printf("Error\nDuplicate texture for NO.\n");
				exit(1);
			}
			i = 2;
			while(line[i] == ' ')
				i++;
			game->map.w_texture = ft_strtrim(&line[i], " \n");
		}
		if (ft_strncmp(line, "EA ", 3) == 0)
		{
			if (game->map.n_texture != NULL)
			{
				printf("Error\nDuplicate texture for NO.\n");
				exit(1);
			}
			i = 2;
			while(line[i] == ' ')
				i++;
			game->map.e_texture = ft_strtrim(&line[i], " \n");
		}
		free(line);
	}
	close(fd);
}
