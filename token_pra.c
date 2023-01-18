/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_pra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 01:31:15 by juykang           #+#    #+#             */
/*   Updated: 2023/01/18 01:41:05 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	type_check(char *line)
{
	
}

t_token	*set_token(const char *line)
{
	t_token	*token;
	t_list	*node;
	int		type;

	if (is_white_space(line))
		line++;
	while (type_check(line))
	{
		token = 
	}
}
