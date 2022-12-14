/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:54:19 by smayrand          #+#    #+#             */
/*   Updated: 2022/11/16 07:23:43 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_var
{
	char	**env;
	char	**input;
	char	*input_tmp;
	char	*prompt;
	char	*buffer;
	char	*exp_def;
	char	*oldpwd;
	int		i;
	int		tmp_i;
	int		flag;
}			t_var;

#endif