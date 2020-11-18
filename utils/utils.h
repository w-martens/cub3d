/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: y4k_wm <y4k_wm@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 15:15:17 by y4k_wm        #+#    #+#                 */
/*   Updated: 2020/11/13 14:26:54 by y4k_wm        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, int len);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		get_next_line(int fd, char **line);
int		nl_check(char *str);
char	*free_str(char *str1);
char	*joiner(char *str1, char *str2);
char	*ft_nldup(char *s1);
int		ft_atoi(const char *str);
char	*ft_strnljoin(char *s1, char *s2);
int		strcmp(const char *s1, const char *s2);

#endif