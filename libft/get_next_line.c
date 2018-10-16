/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:39:08 by glebouch          #+#    #+#             */
/*   Updated: 2018/01/09 17:12:09 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcjoin(char *line, char *buffer, char c)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!(new = (char *)malloc(ft_strlen(line) + ft_strlen(buffer) + 1)))
		return (NULL);
	while (line && line[i])
	{
		new[i] = line[i];
		i++;
	}
	while (buffer[j] && buffer[j] != c)
	{
		new[i + j] = buffer[j];
		j++;
	}
	free(line);
	new[i + j] = 0;
	return (new);
}

static int		ft_taboulet(char **stat, char **line)
{
	char *tmp;

	tmp = *stat;
	if (*stat && *stat[0])
	{
		*line = ft_strcjoin(*line, *stat, '\n');
		*stat = ft_strdup(ft_strchr(tmp, '\n') == NULL ?\
			NULL : ft_strchr(tmp, '\n') + 1);
		free(tmp);
		if (*stat)
			return (1);
		ft_strdel(stat);
	}
	return (0);
}

int				ft_check(int fd, char **line, char *stat)
{
	if (fd == 0 && !line)
	{
		free(stat);
		return (-1);
	}
	if (fd < 0 || !line)
		return (-1);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	int			i;
	char		buffer[BUFF_SIZE + 1];
	static char	*stat;

	if (ft_check(fd, line, stat) == -1)
		return (-1);
	*line = NULL;
	if (ft_taboulet(&stat, line) == 1)
		return (1);
	while ((i = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[i] = '\0';
		if (ft_strchr(buffer, '\n'))
		{
			*line = ft_strcjoin(*line, buffer, '\n');
			if (stat)
				free(stat);
			stat = ft_strdup(ft_strchr(buffer, '\n') + 1);
			return (1);
		}
		*line = ft_strcjoin(*line, buffer, '\n');
	}
	return (*line ? 1 : i);
}
