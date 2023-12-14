/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:20:08 by moel-gha          #+#    #+#             */
/*   Updated: 2023/12/14 11:23:16 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(char *buffer)
{
	size_t	i;
	char	*line;

	if (*buffer == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, i + 1);
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*rests(char *str)
{
	size_t	i;
	char	*rs;

	if (!str)
		return (NULL);
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
	static char	*buffer;
	int			rd;
	char		*tmpbuf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rd = 1;
	tmpbuf = malloc(BUFFER_SIZE + 1);
	if (!tmpbuf)
		return (NULL);
	while (!(ft_strchr(buffer, '\n')) && rd)
	{
		rd = read(fd, tmpbuf, BUFFER_SIZE);
		if (rd == -1)
		{
			free(tmpbuf);
			return (NULL);
		}
		tmpbuf[rd] = '\0';
		buffer = ft_strjoin(buffer, tmpbuf);
	}
	free(tmpbuf);
	tmpbuf = read_line(buffer);
	buffer = rests(buffer);
	return (tmpbuf);
}
