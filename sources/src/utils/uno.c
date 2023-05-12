/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uno.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:02:23 by caguerre          #+#    #+#             */
/*   Updated: 2023/05/12 10:53:29 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131/                       ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

// Imprime el mensaje sólo cuando los parámetros de entrada son incorrectos,
// enviando al fd stderr la string que debe printear.
//
// char	print_message(char return_val)
// {
// 	ft_putendl_fd("Usage: ./minishell", 2);
// 	ft_putendl_fd("Usage: ./minishell -c \"input line\"", 2);
// 	return (return_val);
// }

void	print_util(void)
{
	ft_printf(MAGENTA "Desde utils\n" CYAN);
}
