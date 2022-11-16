/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:24:56 by smayrand          #+#    #+#             */
/*   Updated: 2022/11/16 03:15:49 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// WIP // Leaks 
void	mini_exit(t_var *data)
{
	free(data->buffer);
	ft_free_ptr(data->env);
	ft_free_ptr(data->input);
	exit (0);
}
