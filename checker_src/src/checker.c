/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:56:20 by tkleynts          #+#    #+#             */
/*   Updated: 2021/04/02 16:12:31 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_error(t_stacks *stacks, t_instr **lst)
{
	write(2, "Error\n", 6);
	if (stacks->size_a)
		free(stacks->stack_a);
	if (stacks->size_b)
		free(stacks->stack_b);
	lst_free(lst);
	exit (-42);
}

u_int8_t	ft_read(t_instr **lst)
{
	char	*instr;

	while (ft_gnl(0, &instr) > 0)
		lst_add_back(lst, instr);
	return (0);
}

uint8_t	check_arg(int	argc, char	*argv[], t_stacks *stacks)
{
	int	i;
	uint8_t	flg;

	stacks->stack_a = malloc(sizeof(int32_t) * (argc - 1));
	stacks->stack_b = malloc(sizeof(int32_t) * (argc - 1));
	if (!stacks->stack_a || !stacks->stack_b)
		return (-1);
	i = 1;
	while (i < argc - 2)
	{
		stacks->stack_a[i - 1] = ft_fatoi(argv[i], &flg);
		if (flg)
			return (-1);
		i++;
	}
	stacks->size_a = argc - 1;
	return (0);
}

uint8_t	instr_init(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->size_a = 0;
	stacks->size_b = 0;
	return (0);
}

uint8_t	instr_exec(t_stacks *stacks, t_instr **lst)
{
	t_instr *tmp;
	
	tmp = lst_rm_head(lst);
	while (tmp)
	{
		if (check_instr(tmp->instr, stacks) != 0)
			return (-1);
		tmp = lst_rm_head(lst);
	}
	return (0);
}

uint8_t	print_stacks(t_stacks *stacks)
{
	int i;

	i = 0;
	printf("a \t\t\tb\n-\t\t\t-\n");

	while (i < stacks->size_a || i < stacks->size_b)
	{
		if (i < stacks->size_a)
			printf("%d\t\t\t", stacks->stack_a[i]);
		else
			printf("-\t\t\t");
		
		if (i < stacks->size_b)
			printf("%d\n", stacks->stack_b[i]);
		else
			printf("-\n");
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_instr		*lst;
	t_stacks	stacks;

	if (argc <= 1)
		ft_error(&stacks, &lst);
	if (check_arg(argc, argv, &stacks) != 0)
		ft_error(&stacks, &lst);
	ft_read(&lst);
	if (instr_exec(&stacks, &lst) != 0)
		ft_error(&stacks, &lst);
		print_stacks(&stacks);
	return (0);
}
