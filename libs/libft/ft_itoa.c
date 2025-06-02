/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamutlu <tamutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:11:25 by tamutlu           #+#    #+#             */
/*   Updated: 2024/12/09 09:30:11 by tamutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*reversy(char *s)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	c = 0;
	j = ft_strlen(s) - 1;
	if (s[0] == '-')
		i++;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
	return (s);
}

int	condition_check(char **s, int index, long n, int is_op)
{
	if (n == 0)
	{
		(*s)[index++] = '0';
		(*s)[index] = '\0';
		return (2);
	}
	if (is_op == 1)
		index++;
	return (index);
}

int	check_negative(char **s, int index, long n)
{
	int	is_op;

	is_op = 0;
	if (n < 0)
	{
		(*s)[index] = '-';
		is_op = 1;
	}
	return (is_op);
}

int	get_size(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		is_op;
	int		i;
	char	*s;
	long	num;

	num = n;
	i = 0;
	s = (char *)malloc(get_size(num) + 1 * sizeof(char));
	if (!s)
		return (NULL);
	is_op = check_negative(&s, i, num);
	i = condition_check(&s, i, num, is_op);
	if (i == 2)
		return (s);
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		s[i++] = num % 10 + '0';
		num /= 10;
	}
	s[i] = '\0';
	s = reversy(s);
	return (s);
}

// int	main(void)

// {
// 	int numbers[] = {0, 42, -42, 123456, -123456, INT_MIN, INT_MAX};
// 	int size = sizeof(numbers) / sizeof(numbers[0]);
// 	for (int i = 0; i < size; i++)
// 	{
// 		char *result = ft_itoa(numbers[i]);
// 		if (result)
// 		{
// 			printf("ft_itoa(%d) = %s\n", numbers[i], result);
// 			free(result); // Free the allocated memory
// 		}
// 		else
// 		{
// 			printf("Memory allocation failed for %d\n", numbers[i]);
// 		}
// 	}
// 	return (0);
// }