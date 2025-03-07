/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 07:42:41 by iaskour           #+#    #+#             */
/*   Updated: 2025/03/07 14:53:46 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	second_child(int fd, char **argv, char **env, int argc)
{
	char	**cmd_args;
	char	*cmd_path;
	
	dup2(fd, STDOUT_FILENO);
	close(fd);
	cmd_args = ft_split(argv[argc - 2], ' ');
	cmd_path = get_cmd_path(argv[argc - 2], env);
	if (!cmd_args || !cmd_path)
	{
		if ((!ft_strncmp(argv[argc - 2], "./", 2) || !ft_strncmp(argv[argc - 2], "/", 1))
			&& !access(argv[argc - 2], F_OK) && !access(argv[argc - 2], X_OK))
			cmd_path = argv[argc - 2];
		else
			return (perror("command not found 2"), 0);
	}
	if (execve (cmd_path, cmd_args, env) == -1)
		return (ft_putstr_fd("Error: EXECVE => (second child)", 2), 0);
	return (1);
}
