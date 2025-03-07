/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:00:01 by iaskour           #+#    #+#             */
/*   Updated: 2024/11/30 18:24:21 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d_st;
	char	*s_rc;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	d_st = (char *)dst;
	s_rc = (char *)src;
	i = 0;
	if (d_st > s_rc && d_st < s_rc + len)
		while (len-- > 0)
			d_st[len] = s_rc[len];
	else
	{
		while (i < len)
		{
			d_st[i] = s_rc[i];
			i++;
		}
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	char	*src;
	int		len;

	len = ft_strlen(s1) + 1;
	src = (char *)s1;
	dst = (char *) malloc (len);
	if (dst == NULL)
		return (NULL);
	ft_memmove(dst, src, len);
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	size;
	unsigned int	lenght;
	char			*substr;
	size_t			i;

	if (s == NULL)
		return (NULL);
	size = (unsigned int) ft_strlen(s);
	lenght = (unsigned int) len;
	if (start > size || size == 0)
		return (ft_strdup(""));
	if (lenght > (size - start))
		lenght = (size - start);
	substr = (char *)malloc((lenght + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < lenght)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;
	size_t			lenght;

	lenght = (ft_strlen(s1) + ft_strlen(s2));
	res = (char *) malloc((lenght + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
