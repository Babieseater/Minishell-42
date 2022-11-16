/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:39:25 by smayrand          #+#    #+#             */
/*   Updated: 2022/11/16 03:14:03 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

//void	mini_echo(t_var *buffer)
//{
//	buffer->i = 0;
//	buffer->flag = 0;
//	if (ft_strnstr(buffer->env[1], "-n", ft_strlen(buffer->env[1])))
//	{
//		buffer->flag = 1;
//		buffer->i = 1;
//	}
//	while (buffer->env[++buffer->i] && buffer->env[buffer->i + 1])
//	{
//		printf("%s ", buffer->env[buffer->i]);
//	}
//	printf("%s", buffer->env[buffer->i]);
//	if (buffer->flag == 0)
//		printf("\n");
//}

//void	mini_exit(t_var *data)
//{
//	free(data->buffer);
//	free(data->input);
//	exit (0);
//}

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

int	main(int ac, char **av, char **env)
{
	t_var	data;

	data.i = -1;
	while (env[++data.i])
		data.env[data.i] = ft_strdup(env[data.i]);
//	data.i = -1;
//	while (data.env[++data.i])
//		printf("%s\n", data.env[data.i]);
	while (1)
	{
		data.buffer = readline("MINIFUCK: ");
		data.input = ft_split(data.buffer, ' ');
		if (data.input[0]
			&& ft_strnstr(data.input[0], "env", ft_strlen(data.input[0])))
			mini_env(&data);
		free(data.buffer);
		free(data.input);
	}
	return (0);
}