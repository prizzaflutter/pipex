/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:00:16 by iaskour           #+#    #+#             */
/*   Updated: 2025/03/12 13:40:42 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_first_child(int *fd_array, char **argv, char **env)
{
	if (!check_infile(argv[1]))
		return (0);
	if (!first_child(fd_array, argv, env))
		return (0);
	return (1);
}

int	handle_second_child(int *fd_array, char **argv, char **env)
{
	int	fd;

	fd = 0;
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0 || !check_outfile(argv[4]))
		return (0);
	if (second_child(fd, fd_array, argv, env) == 0)
		return (0);
	return (1);
}

int	excute_children(int pid1, int fd_array[2], char **argv, char **env)
{
	pid_t	pid2;
	int		fd;

	pid2 = 0;
	fd = 0;
	if (pid1 == 0)
		return (handle_first_child(fd_array, argv, env));
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			return (0);
		if (pid2 == 0)
			return (handle_second_child(fd_array, argv, env));
		else
		{
			close(fd_array[0]);
			close(fd_array[1]);
		}
	}
	return (pid2);
}

int	main(int argc, char **argv, char **env)
{
	int		fd_array[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (argc == 5)
	{
		if (pipe(fd_array) == -1)
			return (0);
		pid1 = fork();
		if (pid1 == -1)
			return (ft_printf(2, "Error: Something wrong with fork\n"), 0);
		pid2 = excute_children(pid1, fd_array, argv, env);
		if (pid1 > 0)
		{
			waitpid(pid1, NULL, 0);
			waitpid(pid2, &status, 0);
		}
		close (fd_array[0]);
		close (fd_array[1]);
	}
	else
		ft_printf(2, "Error: Invalid Arguments number\n");
	return (WEXITSTATUS(status));
}
