/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:28:29 by pveeta            #+#    #+#             */
/*   Updated: 2022/04/07 19:06:45 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_RT.h"

int	process_line(t_tracer *rt, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (0);
	if (!split[0])
		return (-1 + stop_parse(split));
	if (!check_indentifier(split[0], rt))
		return (0 + stop_parse(split));
	if (!fill_struct(split, rt))
		return (0 + stop_parse(split));
	return (!stop_parse(split));
}

int	parse_rt_file(t_tracer *rt, char *path)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		i = process_line(rt, line);
		free(line);
		if (i < 0)
			continue ;
		if (!i)
			return (0);
	}
	i = process_line(rt, line);
	free(line);
	if (!i)
		return (0);
	close(fd);
	return (1);
}
