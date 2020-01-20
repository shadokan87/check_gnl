/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:33:39 by motoure           #+#    #+#             */
/*   Updated: 2020/01/20 10:33:42 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		c_len(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	if (c == '\0')
	{
		while (str[i])
			i++;
		return (i);
	}
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_memsub(void **dst, void *src, size_t index, int max)
{
	unsigned char *c_dst;
	unsigned char *c_src;

	c_dst = (unsigned char *)*dst;
	c_src = (unsigned char *)src;
	if (max == -1)
	{
		while (*c_src)
		{
			c_dst[index] = *c_src;
			*c_src++ && index++;
		}
		c_dst[index] = *c_src;
		return ;
	}
	while (max)
	{
		c_dst[index] = *c_src;
		*c_src++ && index++;
		max--;
	}
	c_dst[index] = 0;
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*return_value;

	if (!ptr)
		return (malloc(size));
	else if (size <= (unsigned long)c_len((char *)ptr, '\0'))
		return (ptr);
	else
	{
		if (!(return_value = malloc(size)))
			return (0);
		ft_memsub((void **)&return_value, ptr, 0, -1);
		free(ptr);
	}
	return (return_value);
}

void	check_last_line(char **line, char **stack)
{
	if (c_len(*stack, '\0') > -1 && c_len(*stack, ENDL) != 0)
	{
		if (!(*line = malloc(sizeof(char) * c_len(*stack, '\0') + 1)))
			return (-1);
		ft_memsub((void**)line, *stack, 0, -1);
	}
	else
	{
		*line = malloc(sizeof(char) * 1);
		*line[0] = '\0';
	}
	free(*stack);
	*stack = NULL;
}

int		return_value(char **line, char **stack)
{
	char *tmp;

	tmp = NULL;
	if (c_len(*stack, ENDL) > -1)
	{
		*line = malloc(sizeof(char) * c_len(*stack, ENDL) + 1);
		ft_memsub((void **)line, *stack, 0, c_len(*stack, ENDL));
		tmp = malloc(sizeof(char) * c_len(*stack, '\0') - c_len(*line, '\0'));
		ft_memsub((void **)&tmp, &(*stack)[c_len(*stack, ENDL) + 1], 0, -1);
		free(*stack);
		*stack = tmp;
		return (1);
	}
	check_last_line(line, stack);
	return (0);
}
