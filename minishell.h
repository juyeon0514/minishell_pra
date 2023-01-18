/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:30:14 by juykang           #+#    #+#             */
/*   Updated: 2023/01/18 16:57:25 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* printf, perror*/
# include <stdio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* readline, rl_clear_history, rl_on_new_line, rl_replace_line,
	rl_redisplay, add_history */
# include <readline/readline.h>
# include <readline/history.h>

/* write, read, close, access, pipe, dup, dup2, execve, fork, getcwd, chdir */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>

/* stat, lstat, fstat */
# include <sys/stat.h>

/* open, unlink */
# include <fcntl.h>

/* strerror */
# include <string.h>

/* signal, sigaction, sigemptyset, sigaddset */
# include <signal.h>
/* tcsetattr, tcgetattr */
# include <termios.h>

/* tgetent, tgetflag, tgetnum, tgetstr */
# include <curses.h>
# include <term.h>

enum e_token_type {
	T_NON = 0,
	T_WORD = 1,
	T_PIPE = 2,
	T_REDIR_IN = 3,
	T_REDIR_OUT = 4,
	T_DLESS = 5,
	T_DGREAT = 6,
	T_SIGLE_Q = 7,
	T_DOBBLE_Q = 8
};

typedef struct s_cmd_tree
{
	struct s_cmd_tree	*left;
	struct s_cmd_tree	*right;
}t_cmd_tree;

typedef struct s_token
{
	int				type;
	char			*str;
	struct s_token	*next;
}t_token;

typedef struct s_list
{
	char			c;
	int				len;
	struct s_list	*next;
}t_list;

typedef struct s_envp_list
{
	int					len;
	char				*key;
	char				*value;
	struct s_envp_list	*next;
}t_envp_list;

int		is_white_space(char *str);
void	set_envp_list(char **envp);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	set_signal(void);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	set_token(char	*line, t_token **token_head);
t_list	*new_node(void);
t_token	*new_token(void);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	destroy_list(t_list **node_head);
void	ft_lstadd_token(t_token **lst, t_token *new);
t_list	*new_node(void);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	destroy_list(t_list **node_head);

#endif