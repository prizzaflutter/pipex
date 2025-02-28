/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:44:39 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/28 09:58:43 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdio.h>

int	check_infile(char *infile)
{
	if (access(infile, F_OK) != 0 || access(infile, R_OK) != 0)
		return (0);
	return (1);
}

int	check_outfile(char *outfile)
{
	if (access(outfile, F_OK) != 0 || access(outfile, W_OK) != 0)
		return (0);
	return (1);
}
