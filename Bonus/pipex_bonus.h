/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:10:45 by iaskour           #+#    #+#             */
/*   Updated: 2025/03/09 06:52:38 by iaskour          ###   ########.fr       */
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
char	*ft_strjoin(char const *s1, char const *s2);

#endif