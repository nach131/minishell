/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_arry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:50:58 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/10 13:13:22 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../../libft/inc/libft.h"

void ft_lstprint(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}

char **lst_to_dptr(t_list *lst)
{
	int i = 0;
	int num_lst = ft_lstsize(lst);
	char **res;
	res = malloc((num_lst + 1) * sizeof(char *));

	while (lst)
	{
		res[i] = ft_strdup(lst->content);
		i++;
		lst = lst->next;
	}
	res[i] = NULL;
	return (res);
}

int main(void)
{
	t_list *lst;

	lst = ft_lstnew("UNO=uno");
	lst->next = ft_lstnew("DOS=dos");
	lst->next->next = ft_lstnew("TRES=tres");
	int num = ft_lstsize(lst);

	printf("elementos lst: %d\n", num);
	ft_lstprint(lst);

	char **array = lst_to_dptr(lst);

	int i = 0;

	i = 0;
	printf("----array----\n");
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
	printf("----lst----\n");
	if (lst)
		ft_lstprint(lst);

	ft_free_dptr(array);
	ft_lstfree(lst);

	return (0);
}
