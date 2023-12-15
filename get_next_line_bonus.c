/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:20:08 by moel-gha          #+#    #+#             */
/*   Updated: 2023/12/14 16:16:22 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_all(int fd, char *buffer)
{
	char	*buftmp;
	int		rd;

	rd = 1;
	buftmp = malloc((size_t)BUFFER_SIZE + 1);
	if (!buftmp)
		return (free(buffer), NULL);
	while (rd && !ft_strchr(buffer, '\n'))
	{
		rd = read(fd, buftmp, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buftmp);
			free(buffer);
			return (NULL);
		}
		buftmp[rd] = '\0';
		buffer = ft_strjoin(buffer, buftmp);
		if (!buffer)
			return (NULL);
	}
	free(buftmp);
	return (buffer);
}

static char	*read_line(char *line)
{
	char	*l;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*line == '\0')
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	l = malloc(i + 1);
	if (!l)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		l[j++] = line[i++];
	if (line[i] == '\n')
		l[j++] = '\n';
	l[j] = '\0';
	return (l);
}

static char	*rests(char *str)
{
	int		i;
	char	*rs;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	rs = malloc(ft_strlen(str) - i + 1);
	if (!rs)
		return (NULL);
	if (str[i] == '\n')
		i++;
	ft_strlcpy(rs, &str[i], ft_strlen(str) - i + 1);
	free(str);
	return (rs);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*tmpbuf;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer[fd] = read_all(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	tmpbuf = read_line(buffer[fd]);
	buffer[fd] = rests(buffer[fd]);
	return (tmpbuf);
}
