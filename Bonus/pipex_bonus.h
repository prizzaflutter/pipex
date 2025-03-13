/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:10:45 by iaskour           #+#    #+#             */
/*   Updated: 2025/03/13 14:13:02 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../lib/get_next_line/get_next_line.h"

void	ft_printf(int fd, const char *format, ...);
void	ft_putchar_fd(char c, int fd);
int		first_child(int i, char **argv, char **env, int flag);
int		second_child(int fd, char **argv, char **env, int argc);
int		check_infile(char *infile);
int		check_outfile(char *outfile);
char	*get_cmd_path(char *cmd, char**env);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		open_file(char *file_name);
int		is_here_doc(char	**argv);
int		open_here_doc(int *fd1, int *fd2);
void	free_args(char **cmd_args);

#endif