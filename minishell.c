/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:50:46 by smayrand          #+#    #+#             */
/*   Updated: 2022/11/16 03:11:45 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//-lreadline -lncurses
// char *readline(const char *prompt)
//https://github.com/iciamyplant/Minishell
//https://github.com/Swoorup/mysh
int	main(int argc, char ***argv, char **env)
{
	t_var	data;

	(void)argc;
	(void)argv;
	data.i = -1;
//	init(&shell, env); quoi c'est ça? :P
	while (env[++data.i])
		data.env[data.i] = ft_strdup(env[data.i]);
	while (1)
	{
		data.buffer = readline("MINIFUCK: ");
		data.env = ft_split(data.buffer, ' ');
		the_parser(&data);
		free(data.buffer);
		free(data.env);
	}
	//parsing prompt (1st job) put prompt in malloc struct shell? then parse into childs(fork)
	//prompt builtins(childs into childs) = output
}

// FONCTIONS A ETUDIER:
// readline, rl_clear_history, rl_on_new_line,
// rl_replace_line, rl_redisplay, add_history
// printf, malloc, free, write, access, open, read,
// close, fork, wait, waitpid, wait3, wait4, signal,
// sigaction, sigemptyset, sigaddset, kill, exit,
// getcwd, chdir, stat, lstat, fstat, unlink, execve,
// dup, dup2, pipe, opendir, readdir, closedir,
// strerror, perror, isatty, ttyname, ttyslot, ioctl,
// getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
// tgetnum, tgetstr, tgoto, tputs

// structure du projet:
// - Main program with childs.
// - Parsing into childs from main.
// - Childs into childs (no parent talk)
// - Parsing must include all the docs redirections and pipes
// - childs must be the builtins
// - childs must push the follow up information even if fail to modify
// - history must be in a .txt file or use the computer built in temp.
// - Steven must be good looking at all time

// - we can share workload by Parsing and built-in. Main should be main.
// - main will use fork.
// - Parsing will use read.
// - builtins will use pipe.

/*	***	Notes Steven ***

	Récupérer toutes les variables d'environnement
	Récupérer PATH (qui est dans env) dans un char**
	Récupérer la ligne de commande et écrire le prompt
	
*/

void init(t_var *shell, char **env)
{
	shell->i = 0;
	shell->env = env;
}
