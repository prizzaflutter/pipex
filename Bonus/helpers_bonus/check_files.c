/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:44:39 by iaskour           #+#    #+#             */
/*   Updated: 2025/03/11 14:26:52 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	check_infile(char *infile)
{
	if (!ft_strncmp(infile, "here_doc", 8))
		return (1);
	if (access(infile, F_OK) != 0)
		return (ft_putstr_fd("Error: No such file or directory\n", 2), 0);
	else if (access(infile, R_OK) != 0)
		return (ft_putstr_fd("Error: Permission denied\n", 2), 0);
	return (1);
}

int	check_outfile(char *outfile)
{
	if (access(outfile, W_OK) != 0)
		return (ft_putstr_fd("Error: Permission denied\n", 2), 0);
	return (1);
}
