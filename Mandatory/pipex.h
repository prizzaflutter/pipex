/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:10:45 by iaskour           #+#    #+#             */
/*   Updated: 2025/03/07 17:47:09 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
#include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

int		first_child(int *fd_array, char **argv, char **env);
int		second_child(int fd, int *fd_array, char **argv, char **env);
int		check_infile(char *infile);
int		check_outfile(char *outfile);
char	*get_cmd_path(char *cmd, char**env);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);

#endif