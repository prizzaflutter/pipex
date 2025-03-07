/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:00:16 by iaskour           #+#    #+#             */
/*   Updated: 2025/03/07 17:15:43 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>

int	handle_first_child(int i, char **argv, char **env, int flag)
{
	if (!check_infile(argv[1]) && flag == 0)
		return (exit(1), 0);
	if (first_child(i, argv, env, flag) == 0)
		return (exit(1), 0);
	return (1);
}

int	handle_second_child(char **argv, char **env, int argc)
{
	int fd = 0;
	fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0 || !check_outfile(argv[argc - 1]))
		return (perror("pipex 2"), exit(1), 0);
	if (second_child(fd, argv, env, argc) == 0)
		return (exit(1), 0);
	return (1);
}



int	parent(int argc, char **argv, char **env)
{
	int	i;
	int	flag;

	i = 2;
	flag = 0;
	while (argv[i] && i < argc - 2)
	{
		handle_first_child(i, argv, env, flag);
		flag = 1;
		i++;
	}
	handle_second_child(argv, env, argc);
	while (wait(0) != -1)
		;
	return 1; 
}

int	main(int argc, char **argv, char **env)
{
	if (argc  >=  5)
		parent(argc, argv, env);
	else
		ft_putstr_fd("Invalid arguments\n", 2);
	return (0);
}