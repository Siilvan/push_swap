/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 08:59:56 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/16 11:24:01 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bench_counter(t_oparr *oparr)
{
	int		i;
	int		counter[11];
	long	op_left;
	t_oparr	*temp;

	i = 0;
	temp = oparr;
	op_left = oparr->n_op;
	while (i < op_left)
	{
		if (i == 2000)
		{
			temp = temp->next;
			i -= 2000;
			op_left -= 2000;
		}
		counter[temp->arr[i]] += 1;
		i++;
	}
	return (counter);
}

void	bench_result(t_oparr *oparr, char *mode, double disorder)
{
	char	*pre;
	char	adaptive;
	int		*cnt;

	cnt = bench_counter(oparr);
	pre = "[bench] ";
	adaptive = adaptive_choose(disorder);
	ft_fdprintf(2, "%sdisorder:   %f%%\n", pre, disorder);
	if (!ft_strcmp(mode, "adaptive"))
		ft_fdprintf(2, "%sstrategy:   %s / %s\n", pre, mode, adaptive);
	else
		ft_fdprintf(2, "%sstrategy:   %s\n", pre, mode);
	ft_fdprintf(2, "%stotal_ops: %d\n", pre, oparr->n_op - 1);
	ft_fdprintf(2, "%ssa:%5d  sb:%5d  ss:%5d\n", cnt[SA], cnt[SB], cnt[SS]);
	ft_fdprintf(2, "%spa:%5d  pn:%5d\n", cnt[PA], cnt[PB]);
	ft_fdprintf(2, "%sra:%5d  rb:%5d  rr:%5d\n", cnt[RA], cnt[RB], cnt[RR]);
	ft_fdprintf(2, "%srra:%5d  rrb:%5d  rrr:%5d\n", cnt[RRA], cnt[RRB], cnt[RRR]);
	ft_fdprintf(2, "%stotal_ops:  %d\n");
}