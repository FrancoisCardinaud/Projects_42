/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:21:17 by francoiscar       #+#    #+#             */
/*   Updated: 2023/03/27 00:16:13 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// Define the Stack structure
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

// Define Utility Functions
t_list				*ft_new_stack(int value);
t_list				*ft_lstlast(t_list *head);
void				ft_lstadd_front(t_list **stack, t_list *new);
void				ft_lstadd_back(t_list **stack, t_list *new);
void				print_stack(t_list *head);
int					ft_lstsize(t_list *head);
void				ft_error(char *msg);
void				ft_validate_args(int argc, char **argv);
int					is_sorted(t_list **stack);
int					get_distance_to_top(t_list **stack, int index);
void				make_top_of_stack(t_list **stack, int distance);
void				free_stack(t_list **stack);
void				ft_free(char **str);

// Define Sorting Utility Functions
void				radix_sort(t_list **stack_a, t_list **stack_b);
void				simple_sort(t_list **stack_a, t_list **stack_b);
void				index_stack_elements(t_list **stack);
void				sort_five_elements(t_list **stack_a, t_list **stack_b);

// Define Instruction Functions
int					swap_first_two(t_list **stack);
int					push_top_to_other_stack(t_list **stack_to,
						t_list **stack_from);
int					rotate_stack(t_list **stack);
int					reverse_rotate_stack(t_list **stack);

int					swap_stack_a(t_list **stack_a);
int					swap_stack_b(t_list **stack_b);
int					swap_stacks(t_list **stack_a, t_list **stack_b);
int					push_top_from_b_to_a(t_list **stack_a, t_list **stack_b);
int					push_top_from_a_to_b(t_list **stack_b, t_list **stack_a);
int					rotate_stack_a(t_list **stack_a);
int					rotate_stack_b(t_list **stack_b);
int					rotate_stacks(t_list **stack_a, t_list **stack_b);
int					reverse_rotate_stack_a(t_list **stack_a);
int					reverse_rotate_stack_b(t_list **stack_b);
int					reverse_rotate_stacks(t_list **stack_a, t_list **stack_b);

#endif