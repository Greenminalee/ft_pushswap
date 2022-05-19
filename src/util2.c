/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 21:14:16 by samin             #+#    #+#             */
/*   Updated: 2021/06/11 21:32:25 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**trimed_argv(int argc, char **argv)
{
	int		i;
	int		j;
	char	**tmp;
	char	*tmp2;
	char	*array;

	i = -1;
	array = ft_strdup("");
	while (++i < argc - 1)
	{
		tmp = ft_split(argv[i + 1], ' ');
		j = -1;
		while (tmp[++j] != NULL)
		{
			tmp2 = ft_strjoin(array, tmp[j]);
			free(array);
			free(tmp[j]);
			array = ft_strjoin(tmp2, " ");
			free(tmp2);
		}
		free(tmp);
	}
	tmp = ft_split(array, ' ');
	free(array);
	return (tmp);
}

void	validate_argv(int value_num, char **array)
{
	int i;
	int j;

	i = 0;
	while (i < value_num)
	{
		j = 0;
		while (j < (int)ft_strlen(array[i]))
		{
			if (ft_isdigit(array[i][j]) == 0 && array[i][j] != '-')
			{
				ft_printf("Error\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	duplicate_check(int value_num, char **array)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < value_num)
	{
		j = i + 1;
		while (j < value_num)
		{
			if (ft_atoi(array[i]) == ft_atoi(array[j]))
			{
				ft_printf("Error\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

int		*array_order(int value_num, char **array)
{
	int i;
	int j;
	int tmp;
	int *ordered_array;

	i = -1;
	j = -1;
	ordered_array = malloc(sizeof(int) * value_num);
	while (++i < value_num)
		ordered_array[i] = atoi(array[i]);
	i = -1;
	while (++i < value_num)
	{
		j = i;
		while (++j < value_num)
		{
			if (ordered_array[i] < ordered_array[j])
			{
				tmp = ordered_array[i];
				ordered_array[i] = ordered_array[j];
				ordered_array[j] = tmp;
			}
		}
	}
	return (ordered_array);
}

void	interger_check(int value_num, char **array)
{
	int i;

	i = 0;
	while (i < value_num)
	{
		if (array[i][0] == '-')
		{
			if (ft_atoi(array[i]) == 0)
			{
				ft_printf("Error\n");
				exit(0);
			}
		}
		else
		{
			if (ft_atoi(array[i]) == -1)
			{
				ft_printf("Error\n");
				exit(0);
			}
		}
		i++;
	}
}
