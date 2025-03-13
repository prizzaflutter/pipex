/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 07:42:41 by iaskour           #+#    #+#             */
/*   Updated: 2025/03/13 22:30:23 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	*check_for_cmd(char *cmd, char **env)
{
	char	*cmd_path;

	cmd_path = get_cmd_path(cmd, env);
	if (!cmd_path)
	{
		if ((!ft_strncmp(cmd, "./", 2) || !ft_strncmp(cmd, "/", 1))
			&& !access(cmd, F_OK) && !access(cmd, X_OK))
			cmd_path = cmd;
		else
			return (ft_printf(2, "Error: Command not found : %s\n", cmd), NULL);
	}
	return (cmd_path);
}

int	second_child(int fd, char **argv, char **env, int argc)
{
	char	**cmd_args;
	char	*cmd_path;
	pid_t	pid;

	dup2(fd, STDOUT_FILENO);
	close(fd);
	pid = fork();
	if (pid == -1)
		return (ft_printf(2, "Error: fork failed (second child)\n"), 0);
	if (pid == 0)
	{
		cmd_args = ft_split(argv[argc - 2], ' ');
		if (!cmd_args)
			return (0);
		cmd_path = check_for_cmd(argv[argc - 2], env);
		if (!cmd_path)
			return (free_args(cmd_args), 0);
		if (execve (cmd_path, cmd_args, env) == -1)
			return (free(cmd_path), free_args(cmd_args),
				ft_putstr_fd("Error: EXECVE => (second child)", 2), 0);
	}
	return (1);
}
