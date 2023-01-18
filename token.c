/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:53:53 by juykang           #+#    #+#             */
/*   Updated: 2023/01/18 16:58:16 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	type_check(char c)
{
	int	type;

	if (c == '|')
		type = T_PIPE;
	else if (c == '<')
		type = T_REDIR_IN;
	else if (c == '>')
		type = T_REDIR_OUT;
	else if (c == '\'')
		type = T_SIGLE_Q;
	else if (c == '\"')
		type = T_DOBBLE_Q;
	else if (c == 32 || c == '\t')
		type = T_NON;
	else
		type = T_WORD;
	return (type);
}

int	type_make(char *res, int len)
{
	int	i;
	int	type_res;

	i = 0;
	if (res[i] == T_REDIR_IN && res[i + 1] == T_REDIR_IN)
		type_res = T_DLESS;
	else if (res[i] == T_REDIR_OUT && res[i + 1] == T_REDIR_OUT)
		type_res = T_DGREAT;
	return (type_res);
}

t_token	*do_tokenize(t_list *node_head, int len)
{
	t_token	*res;
	char	*value;
	int		i;

	res = new_token();
	value = malloc((len + 1));
	if (!value)
		return (NULL);
	i = 0;
	while (i < len)
	{
		value[i] = node_head->c;
		node_head = node_head->next;
		i++;
	}
	value[i] = '\0';
	res->str = value;
	res->type = type_make(value, len);
	if (res->type == T_NON)
		return (NULL);
	free(value);
	return (res);
}

int	is_same_type(char cur, char next)
{
	const int	cur_type = type_check(cur);
	const int	next_type = type_check(next);

	if (cur_type == next_type)
		return (1);
	else
		return (0);
}

void	set_token(char	*line, t_token **token_head)
{
	t_token	*token;
	t_list	*node_head;
	t_list	*node;
	int		len;

	if (is_white_space(line))
		line++;
	node_head = new_node();
	len = 0;
	while (*line)
	{
		node = new_node();
		node->c = *line;
		len += 1;
		ft_lstadd_back(&node_head, node);
		if (!is_same_type(*line, *(line + 1)))
		{
			token = new_token();
			token = do_tokenize(node_head->next, len);
			if (!token)
				ft_lstadd_token(token_head, token);
			destroy_list(&node_head);
			node_head = new_node();
			len = 0;
		}
		line++;
	}
}
