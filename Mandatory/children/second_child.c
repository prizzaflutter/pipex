/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 07:42:41 by iaskour           #+#    #+#             */
/*   Updated: 2025/03/08 15:57:14 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	second_child(int fd, int *fd_array, char **argv, char **env)
{
	char	**cmd_args;
	char	*cmd_path;

	close (fd_array[1]);
	dup2(fd_array[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd_array[0]);
	close(fd);
	cmd_args = ft_split(argv[3], ' ');
	cmd_path = get_cmd_path(argv[3], env);
	if (!cmd_args || !cmd_path)
	{
		if ((!ft_strncmp(argv[3], "./", 2) || !ft_strncmp(argv[3], "/", 1))
			&& !access(argv[3], F_OK) && !access(argv[3], X_OK))
			cmd_path = argv[3];
		else
			return (ft_printf(2, "Error: Command not found %s\n", argv[3]), 0);
	}
	if (execve (cmd_path, cmd_args, env) == -1)
		return (ft_putstr_fd("Error: EXECVE => (second child)", 2), 0);
	return (1);
}
