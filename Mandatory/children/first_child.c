/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 07:35:38 by iaskour           #+#    #+#             */
/*   Updated: 2025/03/12 11:16:51 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*configure_path(char *cmd, char **env)
{
	char	*cmd_path;

	cmd_path = get_cmd_path(cmd, env);
	if (!cmd_path)
	{
		if ((!ft_strncmp(cmd, "./", 2) || !ft_strncmp(cmd, "/", 1))
			&& !access(cmd, F_OK) && !access(cmd, X_OK))
			cmd_path = cmd;
		else
		{
			ft_printf(2, "Error: Command not found => %s\n", cmd);
			return (NULL);
		}
	}
	return (cmd_path);
}

int	first_child(int *fd_array, char **argv, char **env)
{
	int		fd;
	char	**cmd_args;
	char	*cmd_path;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	close (fd_array[0]);
	dup2(fd, STDIN_FILENO);
	dup2(fd_array[1], STDOUT_FILENO);
	close(fd_array[1]);
	close(fd);
	cmd_args = ft_split(argv[2], ' ');
	if (!cmd_args)
		return (0);
	cmd_path = configure_path(argv[2], env);
	if (!cmd_path)
		return (free_args(cmd_args), 0);
	if (execve (cmd_path, cmd_args, env) == -1)
	{
		free_args(cmd_args);
		return (ft_printf(2, "Error: EXECVE => (first child)\n"), 0);
	}
	return (1);
}
