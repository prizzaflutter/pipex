/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:44:39 by iaskour           #+#    #+#             */
/*   Updated: 2025/03/11 15:37:20 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_infile(char *infile)
{
	if (access(infile, F_OK) != 0)
		return (ft_printf(2, "Error: No such file or directory\n"), 0);
	else if (access(infile, R_OK) != 0)
		return (ft_printf(2, "Error: Permission denied\n"), 0);
	return (1);
}

int	check_outfile(char *outfile)
{
	if (access(outfile, W_OK) != 0)
		return (ft_printf(2, "Error: Permission denied\n"), 0);
	return (1);
}
