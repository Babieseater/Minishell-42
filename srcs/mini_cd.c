/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:55:13 by krochefo          #+#    #+#             */
/*   Updated: 2022/11/16 02:57:37 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* WIP */
// check if dirpath is a directory.
// check ~ character.
int mini_cd(t_var *data);
{
char *dirpath;
int i;

//malloc dirpath.
if (ft_strnstr(data->input[1], "..", ft_strlen(data->input[1])))
{
    // change dir to up.
    getcwd(dirpath, sizeof(dirpath));
    i = sizeof(dirpath)
    while (dirpath[i])
    {
        if (dirpath[i] == '/')
        {
            ft_bzero(dirpath, i);
            break ;
        }
        i--;
    }
	}
	else if (ft_strnstr(data->input[1], ".", ft_strlen(data->input[1])))
		getcwd(dirpath, sizeof(dirpath));
	else
	{
	    // dirpath = 
	}
	chdir(dirpath);
}