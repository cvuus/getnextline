/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 15:50:35 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/11/02 11:51:18 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;

	if (!s1)
		return (NULL);
	cpy = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (cpy == 0)
		return (cpy);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length;
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	newstr = malloc(sizeof(*newstr) * (length));
	if (newstr == 0)
		return (newstr);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	return (newstr);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*substr;
	size_t	i;
	size_t	len_s;

	len_s = (unsigned int) ft_strlen(s);
	i = 0;
	str = (char *) s;
	if (start >= len_s)
		return (ft_strdup("\0"));
	if (len_s < len)
		len = len_s;
	if (len > (len_s - start - 1))
		len = len_s - start;
	substr = malloc(sizeof(*substr) * (len + 1));
	if (substr == NULL)
		return (substr);
	while (i < len && str[start + i])
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
