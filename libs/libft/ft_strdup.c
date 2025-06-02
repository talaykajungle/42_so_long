/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:01:49 by tamutlu           #+#    #+#             */
/*   Updated: 2025/04/18 21:53:20 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (new == NULL)
		return (NULL);
	while (*s)
		new[i++] = *s++;
	new[i] = '\0';
	return (new);
}

// int	main(int ac, char **av)
// {
// 	char	*mine;
// 	char	*theirs;

// 	if (ac == 2)
// 	{
// 		mine = ft_strdup(av[1]);
// 		theirs = strdup(av[1]);
// 		printf(":%s:\n:%s:\n", mine, theirs);
// 	}
// 	return (0);
// }
