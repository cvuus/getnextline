/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cuechtri <cuechtri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 15:46:33 by cuechtri      #+#    #+#                 */
/*   Updated: 2022/11/02 11:58:51 by cuechtri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define   GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

//GET_NEXT_LINE
char	*get_next_line(int fd);
char	*get_cur_line(char *buffer);
char	*read_file(int fd, char *text);
char	*clean_buffer(char *buffer);

//GET_NEXT_LINE_UTILS
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*no_new_line(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif