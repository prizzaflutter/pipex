/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:56:46 by iaskour           #+#    #+#             */
/*   Updated: 2025/03/07 17:41:15 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Mandatory/pipex.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lenght;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lenght = (ft_strlen(s1) + ft_strlen(s2));
	str = (char *)malloc((lenght + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1 != NULL && i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 != NULL && i < lenght)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
