/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 03:18:59 by smayrand          #+#    #+#             */
/*   Updated: 2022/11/16 07:56:56 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// WIP // ***should work properly, more testing needed***
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
