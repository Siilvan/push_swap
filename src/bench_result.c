/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 08:59:56 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/17 18:06:03 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_counter(t_oparr **oparr, int counter[11])
{
	int		i;
	int		val;
	t_oparr	*temp;

	temp = *oparr;
	while (temp)
	{
		i = 0;
		while (i < temp->n_op)
		{
			val = temp->arr[i];
			if (val >= 0 && val <= 11)
				counter[val] += 1;
			i++;
		}
		temp = temp->next;
	}	
}

int	ops_count(t_oparr **oparr)
{
	int		total;
	t_oparr	*temp;

	temp = *oparr;
	total = 0;
	while (temp)
	{
		total += temp->n_op;
		temp = temp->next;
	}
	return (total);
}
void	bench_result(t_oparr **oparr, char *mode, double disorder)
{
	char	*pre;
	char	*adaptive;
	int		cnt[11];
	int		total_ops;

	ft_memset(cnt, 0, 44);
	bench_counter(oparr, cnt);
	pre = "[bench] ";
	total_ops = ops_count(oparr);
	adaptive = adaptive_choose(disorder);
	ft_fdprintf(2, "%sdisorder:   %f%%\n", pre, disorder);
	if (!ft_strcmp(mode, "adaptive"))
		ft_fdprintf(2, "%sstrategy:   %s / %s\n", pre, mode, adaptive);
	else
		ft_fdprintf(2, "%sstrategy:   %s\n", pre, mode);
	ft_fdprintf(2, "%stotal_ops:  %d\n", pre, total_ops);
	ft_fdprintf(2, "%ssa:%5d  sb:%5d  ss:%5d\n", pre, cnt[SA], cnt[SB], cnt[SS]);
	ft_fdprintf(2, "%spa:%5d  pb:%5d\n", pre, cnt[PA], cnt[PB]);
	ft_fdprintf(2, "%sra:%5d  rb:%5d  rr:%5d\n", pre, cnt[RA], cnt[RB], cnt[RR]);
	ft_fdprintf(2, "%srra:%4d  rrb:%4d  rrr:%4d\n", pre, cnt[RRA], cnt[RRB], cnt[RRR]);
}
