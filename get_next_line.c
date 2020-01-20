/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 09:15:29 by motoure           #+#    #+#             */
/*   Updated: 2020/01/20 10:17:35 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char *stack[4094];
	char		buff[BUFFER_SIZE + 1];
	int			len;
	int			file;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (1)
	{
		len = 0;
		len = stack[fd] ? c_len(stack[fd], '\0') : len;
		if (c_len(stack[fd], ENDL) > -1)
			break ;
		file = read(fd, buff, BUFFER_SIZE);
		if (file == 0)
			break ;
		else if (file == -1)
			return (-1);
		buff[file] = '\0';
		if (!(stack[fd] = ft_realloc(stack[fd], file + len + 1 * sizeof(char))))
			return (-1);
		ft_memsub((void**)&stack[fd], buff, len, -1);
	}
	return (return_value(line, &stack[fd]));
}
