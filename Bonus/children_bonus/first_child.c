/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 07:35:38 by iaskour           #+#    #+#             */
/*   Updated: 2025/03/09 06:49:09 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

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
			return (ft_printf(2, "Error: Command not found : %s\n", cmd), NULL);
	}
	return (cmd_path);
}

int	excute_cmd(int i, int *fd_array, char **argv, char **env)
{
	char	**cmd_args;
	char	*cmd_path;

	close(fd_array[0]);
	dup2(fd_array[1], STDOUT_FILENO);
	close(fd_array[1]);
	cmd_args = ft_split(argv[i], ' ');
	if (!cmd_args)
		return (0);
	cmd_path = configure_path(argv[i], env);
	if (!cmd_path)
		return (0);
	if (execve(cmd_path, cmd_args, env) == -1)
		return (ft_putstr_fd("Error: EXECVE => (first child)", 2), 0);
	return (1);
}

int	open_infile(char **argv)
{
	int	fd;

	fd = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf(1, "am here\n"), 0);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (1);
}

int	first_child(int i, char **argv, char **env, int flag)
{
	int		fd_array[2];
	pid_t	pid;

	if (pipe(fd_array) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (ft_printf(2, "Error: fork issue\n"), 0);
	if (flag == 0)
		if (open_infile(argv) == 0)
			return (ft_printf(2, "Error: in open file funciton\n"), 0);
	if (pid == 0)
	{
		if (excute_cmd(i, fd_array, argv, env) == 0)
			return (ft_printf(2, "Error: in excute command\n"), 0);
	}
	else
		return (close(fd_array[1]), dup2(fd_array[0], STDIN_FILENO),
			close(fd_array[0]), 1);
	return (1);
}
