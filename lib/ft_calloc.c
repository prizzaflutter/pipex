/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:15:55 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/25 18:09:47 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;

	if (size != 0 && count >= SIZE_MAX / size)
		return (NULL);
	tmp = malloc(count * size);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, (count * size));
	return (tmp);
}
