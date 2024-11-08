/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:56:15 by logkoege          #+#    #+#             */
/*   Updated: 2024/11/08 13:41:35 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("Error: wrong number of arguments -> must be 5\n", 2);
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Error: fork failed\n", 2);
		return (1);
	}
	if (pid == 0)
		first_process(argv, envp, fd);
	waitpid(pid, NULL, 0);
	second_process(argv, envp, fd);
	return (0);
}
