/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:09:44 by smayrand          #+#    #+#             */
/*   Updated: 2022/11/16 03:18:38 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// WIP //
void	the_parser(t_var data)
{
	if (data.input[0]
		&& ft_strnstr(data.input[0], "echo", ft_strlen(data.input[0])))
		mini_echo(&data);
	else if (data.input[0]
		&& ft_strnstr(data.input[0], "cd", ft_strlen(data.input[0])))
		mini_cd(&data);
	else if (data.input[0]
		&& ft_strnstr(data.input[0], "pwd", ft_strlen(data.input[0])))
		mini_pwd(&data);
	else if (data.input[0]
		&& ft_strnstr(data.input[0], "export", ft_strlen(data.input[0])))
		mini_export(&data);
	else if (data.input[0]
		&& ft_strnstr(data.input[0], "unset", ft_strlen(data.input[0])))
		mini_unset(&data);
	else if (data.input[0]
		&& ft_strnstr(data.input[0], "env", ft_strlen(data.input[0])))
		mini_env(&data);
	else if (data.input[0]
		&& ft_strnstr(data.input[0], "exit", ft_strlen(data.input[0])))
		mini_exit(&data);
}
