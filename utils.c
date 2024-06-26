/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:24:27 by kkarakus          #+#    #+#             */
/*   Updated: 2024/04/16 10:08:18 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

char	**arg_join(char **argv)
{
	int		i;
	char	**listed_all;
	char	*tmp;

	i = 1;
	tmp = NULL;
	while (argv[i])
	{
		tmp = my_strjoin(tmp, argv[i]);
		i++;
	}
	listed_all = ft_split(tmp, ' ');
	free(tmp);
	return (listed_all);
}

char	*my_strjoin(char *s1, char *s2)
{
	char			*res;
	size_t			i;
	size_t			j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!res)
		return (NULL);
	j = 0;
	i = 0;
	if (s1)
		while (s1[i])
			res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = ' ';
	res[j + 1] = '\0';
	free(s1);
	return (res);
}

void	arg_check(int ac, char **argv)
{
	int	i;
	int	x;

	i = 1;
	while (i < ac)
	{
		x = 0;
		if (argv[i][x] == '\0')
			print_error();
		while (argv[i][x])
		{
			if ((argv[i][x] < '0' || argv[i][x] > '9') && argv[i][x] != ' '
				&& argv[i][x] != '-' && argv[i][x] != '+')
				print_error();
			if (argv[i][x] == '-' || argv[i][x] == '+')
				if ((argv[i][x + 1] < '0' || argv[i][x + 1] > '9') ||
					(argv[i][x - 1] >= '0' && argv[i][x - 1]))
					print_error();
			x++;
		}
		i++;
	}
}

int	my_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (sign * result > 2147483647 || sign * result < -2147483648)
		print_error();
	return (sign * result);
}
