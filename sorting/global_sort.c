// 1. amount of instructions to put elem to the 0 position
// 2. find a place in B where to put elem (between min and max)
// 3. calculate total amount of instruction
// 4. do for all elems in A, then pick the one with least number => repeat

#include "../src/push_swap.h"

int		find_place_in_a(int *stack, int len, int elem, char **rot_type)
{
	register int i;
	register int place;

	i = 0;
	place = 0;
	if (len == 2 && elem > stack[0] && elem < stack[1])
		place = 1;
	else if (len == 2 && elem < stack[0] && elem > stack[1])
		place = 0;
	else if (elem > stack[find_max_elem(stack, len)] || elem < stack[find_min_elem(stack, len)])
		place = find_min_elem(stack, len);
	else
		while (i < len)
		{
			if (elem > stack[i] && ((i + 1 < len && elem < stack[i + 1]) ||
			(i + 1 == len && elem < stack[0])))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	return (find_a_rot_type(len, place, rot_type));
}

static void	insert_back_in_a(t_stack *stack)
{
	register int	num_of_rots;
	char			*rot_type;

	num_of_rots = 0;
	rot_type = ft_strnew(3);
	while (stack->b_len)
	{
		num_of_rots = find_place_in_a(stack->a,
			stack->a_len, stack->b[0], &rot_type);
		while (num_of_rots > 0)
		{
			if (ft_strequ(rot_type, "ra"))
				ra(stack);
			else
				rra(stack);
			num_of_rots--;
		}
		pa(stack);
	}
	place_smallest_first_a(stack);
	free(rot_type);
}

static void	insert_leftover_to_b(t_stack *stack)
{
	int idx;

	idx = 0;
	while (stack->a_len > 2)
	{
		idx = find_min_elem(stack->a, stack->a_len);
		if (idx == 0)
			pb(stack);
		else if (idx <= stack->a_len / 2)
			ra(stack);
		else if (idx > stack->a_len / 2)
			rra(stack);
	}
}

static void	process_moves(t_moves *best_move, t_stack *stack)
{
	while (best_move->a_moves)
	{
		if (ft_strequ(best_move->a_rot_type, "ra"))
			ra(stack);
		else
			rra(stack);
		best_move->a_moves--;
	}
	while (best_move->b_moves)
	{
		if (ft_strequ(best_move->b_rot_type, "rb"))
			rb(stack);
		else
			rrb(stack);
		best_move->b_moves--;
	}
}

void		global_sort(t_stack *stack)
{
	t_moves	*best_move;
	int		optimizer;

	optimizer = (stack->a_len > 200)? 50 : 2;
	while (stack->b_len != 2)
		pb(stack);
	while (stack->a_len > optimizer)
	{
		best_move = best_way_from_a_to_b(stack);
		while (best_move->common_moves)
		{
			if (ft_strequ(best_move->common_rot, "rr"))
				rr(stack);
			else
				rrr(stack);
			best_move->common_moves--;
		}
		process_moves(best_move, stack);
		pb(stack);
		free_moves(best_move);
	}
	insert_leftover_to_b(stack);
	insert_back_in_a(stack);
}
