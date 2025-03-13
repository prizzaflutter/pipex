/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:04:22 by iaskour           #+#    #+#             */
/*   Updated: 2025/03/13 11:16:23 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (1);
}

int	open_here_doc(int *fd1, int *fd2)
{
	unlink("here_doc.txt");
	*fd1 = open("here_doc.txt", O_WRONLY
			| O_CREAT | O_TRUNC, 0777);
	*fd2 = open("here_doc.txt", O_RDONLY);
	if (*fd1 < 0)
		return (0);
	if (*fd2 < 0)
		return (close(*fd1), 0);
	unlink("here_doc.txt");
	return (1);
}
