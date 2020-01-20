/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:17:59 by motoure           #+#    #+#             */
/*   Updated: 2020/01/20 10:40:48 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define ENDL '\n'
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>

int		check_last_line(char **line, char **stack);
void	*ft_realloc(void *ptr, size_t size);
void	ft_memsub(void **dst, void *src, size_t index, int max);
int		c_len(char *str, char c);
int		return_value(char **line, char **stack);
int		get_next_line(int fd, char **line);
#endif
