/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 13:54:58 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/11/03 11:45:55 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

// Error Managment if Nothing to return or NULL
// Dynamic Memory Allocation

// gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 
// test.c get_next_line.c get_next_line_utils.c

char	*get_next_line(int fd)
{
	static char	*buffer[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 10240)
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!(buffer[fd]))
		return (NULL);
	line = get_cur_line(buffer[fd]);
	buffer[fd] = clean_buffer(buffer[fd]);
	return (line);
}

char	*get_cur_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (buffer[i] == 0)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_substr(buffer, 0, i);
	if (!line)
	{
		free (buffer);
		return (NULL);
	}
	return (line);
}

char	*read_file(int fd, char *buffer)
{
	char	tmp[BUFFER_SIZE + 1];
	int		re;
	char	*oldbuffer;

	re = 1;
	while (no_new_line(buffer) == 0 && re > 0)
	{
		re = read(fd, tmp, BUFFER_SIZE);
		if (!buffer)
			buffer = ft_strdup("");
		if (!buffer || re < 0)
		{
			free(buffer);
			return (NULL);
		}
		tmp[re] = '\0';
		oldbuffer = buffer;
		buffer = ft_strjoin(buffer, tmp);
		if (!buffer)
			return (free(oldbuffer), NULL);
		free(oldbuffer);
	}
	return (buffer);
}

char	*clean_buffer(char *buffer)
{
	int		i;
	char	*tmp;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	tmp = ft_substr(buffer, i, ft_strlen(buffer) - i);
	if (!(tmp))
	{
		free(buffer);
		return (NULL);
	}
	free (buffer);
	return (tmp);
}

char	*no_new_line(const char *s)
{
	char	c;

	if (!s)
		return (NULL);
	c = '\n';
	while (*s)
	{
		if (*s == c)
			return ((char *) s);
		s++;
	}
	return (0);
}
