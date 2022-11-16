/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 00:39:51 by smayrand          #+#    #+#             */
/*   Updated: 2022/11/16 02:02:37 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
