/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoiscardinaud <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:18:13 by francoiscardi     #+#    #+#             */
/*   Updated: 2023/03/24 17:18:52 by francoiscardi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void report_error(char *msg) {
    ft_putendl_fd(msg, 1);
    exit(0);
}

void free_strings(char **str) {
    int i = 0;
    while (str[i])
        i++;
    while (i >= 0)
        free(str[i--]);
}

int is_ascending(t_list **stack) {
    t_list *head = *stack;
    while (head && head->next) {
        if (head->value > head->next->value)
            return 0;
        head = head->next;
    }
    return 1;
}

int distance_to_index(t_list **stack, int index) {
    t_list *head = *stack;
    int distance = 0;
    while (head) {
        if (head->index == index)
            break;
        distance++;
        head = head->next;
    }
    return distance;
}

void move_to_top(t_list **stack, int distance) {
    t_list *head = *stack;
    int tmp;
    if (distance == 0)
        return;
    tmp = ft_lstsize(head) - distance;
    if (distance <= (ft_lstsize(head) / 2)) {
        while (distance-- > 0)
            rotate_a(stack);
    } else {
        while (tmp-- > 0)
            reverse_rotate_a(stack);
    }
}

void free_list(t_list **stack) {
    t_list *head = *stack;
    t_list *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    free(stack);
}
