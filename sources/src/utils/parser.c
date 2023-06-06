/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:54:00 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/06 16:05:56 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

// CONTROL DE LOS FLAG PARA EL PARSER
void	ctrl_line(int flag[], char *line)
{
	int	i;
	int	double_quote;

	double_quote = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == DOUBLE_QUOTE)
			double_quote++;
		i++;
	}
	if (double_quote == 2)
		flag[DOUBLE_QUOTE] = 1;
}

void	parser_space_lst(char *line, t_list **token)
{
	int		quotes;
	char	*start;

	quotes = 0;
	start = line;
	while (*line != '\0')
	{
		if (*line == DOUBLE_QUOTE)
			quotes = !quotes;
		else if (*line == WHITE_SPACE && !quotes)
		{
			*line = '\0';
			ft_lstadd_back(token, ft_lstnew(start));
			start = line + 1;
		}
		line++;
	}
	ft_lstadd_back(token, ft_lstnew(start));
}

// YA NO
// CUANDO SEA IMPAR " o ' SE abre la consola de lineas,
// esto hay que comprobarlo en el segundo paso de parser_space
// en la stacic de next_token
