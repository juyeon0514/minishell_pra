/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:18:54 by juykang           #+#    #+#             */
/*   Updated: 2023/01/17 23:10:48 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char			*str;
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	set_signal();
	set_envp_list(envp);
	while (1)
	{
		str = readline("minishell$ ");
		if (!str)
			break ;
		if (*str != '\0')
			add_history(str);
		if (*str != '\0' && !is_white_space(str))
		{
			printf("%d", 1);
		}
		free(str);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
