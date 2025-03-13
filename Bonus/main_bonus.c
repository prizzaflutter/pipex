/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:00:16 by iaskour           #+#    #+#             */
/*   Updated: 2025/03/13 11:09:48 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	handle_first_child(int i, char **argv, char **env, int flag)
{
	if (!check_infile(argv[1]) && flag == 0)
		return (0);
	if (first_child(i, argv, env, flag) == 0)
		return (0);
	return (1);
}

int	handle_second_child(char **argv, char **env, int argc)
{
	int	fd;

	fd = 0;
	fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0 || !check_outfile(argv[argc - 1]))
		return (ft_printf(2, "Error: in  outfile\n"), 0);
	if (second_child(fd, argv, env, argc) == 0)
		return (0);
	return (1);
}

int	is_here_doc(char	**argv)
{
	if (!ft_strncmp(argv[1], "here_doc", 8) && argv[1][8] == '\0')
		return (1);
	return (0);
}

void f(void)
{
	system("leaks pipex_bonus");
	system("lsof -c pipex_bonus");
}

int	parent(int argc, char **argv, char **env)
{
	int	i;
	int	flag;

	flag = 0;
	i = 2;
	if (is_here_doc(argv) == 1)
		i = 3;
	while (argv[i] && i < argc - 2)
	{
		if (!handle_first_child(i, argv, env, flag))
			break ;
		flag = 1;
		i++;
	}
	if (!handle_second_child(argv, env, argc))
		return (0);
	while (wait(0) != -1)
		;
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	atexit(f);
	if (is_here_doc(argv))
	{
		if (argc < 6)
			ft_printf(2, "Error: Invalid arguments\n");
		else
			parent(argc, argv, env);
	}
	else if (argc >= 5)
		parent(argc, argv, env);
	else
		ft_printf(2, "Error: Invalid arguments\n");
	return (0);
}
