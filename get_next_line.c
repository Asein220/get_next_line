/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atembras <atembras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:45:21 by atembras          #+#    #+#             */
/*   Updated: 2024/01/15 21:48:14 by atembras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*definitive_line(char *stack)
{
	char	*line;
	int		i;

	if (!stack || !*stack)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*join_and_free(char *stack, char *tmp)
{
	char	*aux;

	if (!stack)
	{
		stack = ft_strdup("");
		if (!stack)
			return (NULL);
	}
	aux = ft_strjoin(stack, tmp);
	if (!aux)
	{
		free(stack);
		return (NULL);
	}
	free(stack);
	return (aux);
}

char	*update_stack(char *stack)
{
	char	*aux;
	char	*p;
	int		i;

	i = 0;
	p = ft_strchr(stack, '\n');
	if (!p)
	{
		free(stack);
		return (NULL);
	}
	p++;
	aux = malloc(sizeof(char) * (ft_strlen(p) + 1));
	if (!aux)
		return (NULL);
	while (*p != '\0')
	{
		aux[i] = *p;
		i++;
		p++;
	}
	aux[i] = '\0';
	free(stack);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*stack[256];
	char		*line;
	char		tmp[BUFFER_SIZE + 1];
	ssize_t		nbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nbytes = 1;
	while (!(ft_strchr(stack[fd], '\n')) && nbytes > 0)
	{
		nbytes = read(fd, tmp, BUFFER_SIZE);
		if (nbytes < 0)
			return (free(stack[fd]), stack[fd] = NULL, NULL);
		tmp[nbytes] = '\0';
		stack[fd] = join_and_free(stack[fd], tmp);
		if (!stack[fd])
			return (NULL);
	}
	line = definitive_line(stack[fd]);
	stack[fd] = update_stack(stack[fd]);
	return (line);
}
