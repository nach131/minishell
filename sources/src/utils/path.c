/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:58:53 by carles            #+#    #+#             */
/*   Updated: 2023/05/27 13:39:20 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"
#include "working_tools.h"

int get_evar_index(t_env *env, char *str)
{
    int i;

    i = 0;
    while (i < env->count)
    {
        if (ft_strcmp(str, env->var[i].name) == 0)
            return (i);
        i++;
    }
    return (-1);
}

char    *get_evar(t_data *data, t_env *env, char *str)
{
    int i;

    i = get_evar_index(env, str);
    if (ft_strcmp(str, "?") == 0)
    {
        return (ft_itoa(data->status));
    }
    if (i == -1)
        return (env->var[i].content);
}

void	init_path(t_data *data, t_env *env)
{
    data->path = ft_split(get_evar(data, env, "PATH"), ':');
}
