/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atembras <atembras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:26:02 by atembras          #+#    #+#             */
/*   Updated: 2024/01/17 16:50:29 by atembras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	if (!str)
		return (0);
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*def;
	int		i;
	int		j;
	size_t	len_1;
	size_t	len_2;

	i = -1;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	len_1 = ft_strlen((char *)s1);
	len_2 = ft_strlen((char *)s2);
	def = (char *)malloc(len_1 + len_2 + 1);
	if (!def)
		return (NULL);
	while (s1[++i])
		def[i] = s1[i];
	while (s2[j])
		def[i++] = s2[j++];
	def[i] = '\0';
	return (def);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	string_len;
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	string_len = ft_strlen((char *)s);
	if (start >= string_len)
		return (ft_strdup(""));
	if (string_len - start < len)
		len = string_len - start;
	sub = (char *)malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strchr(char *str, int c)
{
	unsigned int	i;
	unsigned char	p;

	i = 0;
	p = c;
	if (!str)
		return (NULL);
	if (p == 0)
	{
		while (str[i])
			i++;
		return (&str[i]);
	}
	while (str[i])
	{
		if (str[i] == p)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*n_str;
	int		i;
	size_t	lenght;

	i = 0;
	if (!str)
		return (NULL);
	lenght = ft_strlen((char *)str);
	n_str = (char *)malloc(lenght + 1);
	if (!n_str)
		return (NULL);
	while (str[i])
	{
		n_str[i] = str[i];
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
