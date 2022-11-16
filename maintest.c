/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:39:25 by smayrand          #+#    #+#             */
/*   Updated: 2022/11/16 08:15:38 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

//void	mini_cd(t_var *data)
//{
//	char	*dirpath;
//	int		i;
//
//	if (ft_strnstr(data->input[1], "..", ft_strlen(data->input[1])))
//	{
//		getcwd(dirpath, sizeof(dirpath));
//		i = sizeof(dirpath);
//		while (dirpath[i])
//		{
//			if (dirpath[i] == '/')
//			{
//				ft_bzero(dirpath, i);
//				break ;
//			}
//		i--;
//		}
//	}
//	else if (ft_strnstr(data->input[1], ".", ft_strlen(data->input[1])))
//		getcwd(dirpath, sizeof(dirpath));
//	else if (ft_strnstr(data->input[1], "~", ft_strlen(data->input[1])))
//		dirpath = data->oldpwd;
//	else if (ft_strnstr(data->input[1], "-", ft_strlen(data->input[1])))
//	{
//		dirpath = data->oldpwd;
//		printf("%s", dirpath);
//	}
//	else
//	{
//		if (chdir(dirpath) == -1)
//			printf("No such file or directory\n");
//	}
//	data->oldpwd = dirpath;
//	chdir(dirpath);
//}

void	mini_exit(t_var *data)
{
	free(data->buffer);
	ft_free_ptr(data->env);
	ft_free_ptr(data->input);
	exit (0);
}

void	mini_pwd(t_var *data)
{
	int	i;

	i = 3;
	data->i = -1;
	while (data->env[++data->i])
	{
		if (ft_strnstr(data->env[data->i], "PWD=", 4))
		{
			while (data->env[data->i][++i])
				printf("%c", data->env[data->i][i]);
			printf("\n");
		}
	}
}

void	mini_env(t_var *data)
{
	data->i = -1;
	while (data->env[++data->i])
		printf("%s\n", data->env[data->i]);
}

void	mini_echo(t_var *data)
{
	data->i = 0;
	data->flag = 0;
	if (ft_strnstr(data->input[1], "-n", ft_strlen(data->input[1])))
	{
		data->flag = 1;
		data->i = 1;
	}
	while (data->input[++data->i] && data->input[data->i + 1])
	{
		printf("%s ", data->input[data->i]);
	}
	printf("%s", data->input[data->i]);
	if (data->flag == 0)
		printf("\n");
}

void	mini_export(t_var *data)
{
	data->i = 0;
	if (!data->input[1])
		mini_env(data);
	else if (strchr(data->input[1], '='))
	{
		data->input_tmp = *ft_split(data->input[1], '=');
		while (data->env[data->i] != NULL
			&& (!(ft_strnstr(data->env[data->i],
						data->input_tmp, ft_strlen(data->input_tmp)))))
			data->i++;
		data->env[data->i] = data->input[1];
		data->env[data->i + 1] = NULL;
	}
}

// WIP // not working at all
void	mini_unset(t_var *data)
{
	data->i = 0;
	while (data->env[data->i] != NULL)
		data->i++;
	data->tmp_i = data->i;
	data->i = 0;
	data->input_tmp = *ft_split(data->input[1], '=');
	printf("%s\n", data->input_tmp);
	while (data->env[++data->i])
	{
		if (ft_strnstr(*ft_split(data->env[data->i], '='), data->input_tmp,
				ft_strlen(data->input_tmp)))
		{
			ft_swap_char(data->env[data->i], data->env[data->tmp_i]);
			data->env[data->i - 1] = NULL;
		}
	}
}

int	main(int ac, char **av, char **env)
{
	t_var	data;

	(void)ac;
	(void)av;
	data.env = ft_calloc(sizeof(char *), 10000);
	data.i = -1;
	while (env[++data.i])
		data.env[data.i] = ft_strdup(env[data.i]);
	while (1)
	{
		data.buffer = readline("MINIFUCK: ");
		data.input = ft_split(data.buffer, ' ');
		if (data.input[0]
			&& ft_strnstr(data.input[0], "env", ft_strlen(data.input[0])))
			mini_env(&data);
		else if (data.input[0]
			&& ft_strnstr(data.input[0], "exit", ft_strlen(data.input[0])))
			mini_exit(&data);
		else if (data.input[0]
			&& ft_strnstr(data.input[0], "echo", ft_strlen(data.input[0])))
			mini_echo(&data);
		else if (data.input[0]
			&& ft_strnstr(data.input[0], "pwd", ft_strlen(data.input[0])))
			mini_pwd(&data);
		else if (data.input[0]
			&& ft_strnstr(data.input[0], "export", ft_strlen(data.input[0])))
			mini_export(&data);
		else if (data.input[0]
			&& ft_strnstr(data.input[0], "unset", ft_strlen(data.input[0])))
			mini_unset(&data);
		free(data.buffer);
		free(data.input);
	}
	free(data.env);
	return (0);
}