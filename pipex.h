/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:56:25 by logkoege          #+#    #+#             */
/*   Updated: 2024/11/08 17:14:59 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>

//utils.c
void		first_process(char **argv, char **envp, int *fd);
void		second_process(char **argv, char **envp, int *fd);
char		*find_path(char *cmd, char **envp);
void		execute(char *cmd, char **envp);

//utils2.c
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
int			ft_strlen(char *str);
void		ft_putendl_fd(char *s, int fd);
char		*ft_strjoin(char *s1, char *s2);

//ft_split.c
char		**ft_split(const char *str, char c);

#endif