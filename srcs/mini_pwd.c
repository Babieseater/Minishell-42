/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 02:31:46 by smayrand          #+#    #+#             */
/*   Updated: 2022/11/16 03:05:59 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
