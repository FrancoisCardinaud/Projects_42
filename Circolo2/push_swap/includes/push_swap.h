/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:21:17 by francoiscar       #+#    #+#             */
/*   Updated: 2023/04/18 14:09:30 by fcardina         ###   ########.fr       */
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
t_list				*ft_lstnew(int value);
t_list				*ft_lstlast(t_list *head);
void				ft_lstadd_front(t_list **stack, t_list *new);
void				ft_lstadd_back(t_list **stack, t_list *new);
void				print_list(t_list *head);
int					ft_lstsize(t_list *head);
void				report_error(char *msg);
void				ft_check_args(int argc, char **argv);
int					is_sorted(t_list **stack);
int					get_distance_to_top(t_list **stack, int index);
void				free_stack(t_list **stack);
void				ft_free(char **str);

// Define Sorting Utility Functions
void				else_three(t_list **stack_a);
void				radix_sort(t_list **stack_a, t_list **stack_b);
void				simple_sort(t_list **stack_a, t_list **stack_b);
void				index_stack_elements(t_list **stack);
void				sort_five_elements(t_list **stack_a, t_list **stack_b);
void				three_op1(t_list **stack_a);

// Define Instruction Functions
int					swap(t_list **stack);
int					push(t_list **stack_to,
						t_list **stack_from);
int					rotate(t_list **stack);
int					reverse_rotate(t_list **stack);

int					swap_a(t_list **stack_a);
int					swap_b(t_list **stack_b);
int					swap_stacks(t_list **stack_a, t_list **stack_b);
int					push_a(t_list **stack_a, t_list **stack_b);
int					push_b(t_list **stack_b, t_list **stack_a);
int					rotate_a(t_list **stack_a);
int					rotate_b(t_list **stack_b);
int					rr(t_list **stack_a, t_list **stack_b);
int					reverse_rotate_a(t_list **stack_a);
int					reverse_rotate_b(t_list **stack_b);
int					reverse_rotate_stacks(t_list **stack_a, t_list **stack_b);

#endif
