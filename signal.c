/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:14:37 by juykang           #+#    #+#             */
/*   Updated: 2023/01/16 11:15:02 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("minishell$ \n");
	}
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

void	set_signal(void)
{
	struct termios	term;

	/* CTRL + C */
	signal(SIGINT, sig_handler);
	/* CTRL + */
	signal(SIGQUIT, SIG_IGN);
	/* CTRL + D */
	signal(SIGTERM, sig_handler);
}
