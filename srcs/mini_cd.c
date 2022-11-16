/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:55:13 by krochefo          #+#    #+#             */
/*   Updated: 2022/11/16 06:24:50 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* WIP */
// PWD + OLDWPD in env update
//int mini_cd(t_var *data);
//{
//    char *dirpath;
//    int i;
//
//    if (ft_strnstr(data->input[1], "..", ft_strlen(data->input[1])))
//    {
//    getcwd(dirpath, sizeof(dirpath));
//    i = sizeof(dirpath)
//    while (dirpath[i])
//    {
//        if (dirpath[i] == '/')
//        {
//            ft_bzero(dirpath, i);
//            break ;
//        }
//        i--;
//    }
//	}
//	else if (ft_strnstr(data->input[1], ".", ft_strlen(data->input[1])))
//		getcwd(dirpath, sizeof(dirpath));
//    else if (ft_strnstr(data->input[1], "~", ft_strlen(data->input[1])))
//        dirpath = data->oldpwd;
//    else if (ft_strnstr(data->input[1], "-", ft_strlen(data->input[1])))
//    {
//        dirpath = data->oldpwd;
//        printf("%s", dirpath);
//    }
//	else
//	{
//        if (chdir(dirpath) == -1)
//            printf("not a directory");
//	}
//    data->oldpwd = dirpath;
//	chdir(dirpath);
//}
