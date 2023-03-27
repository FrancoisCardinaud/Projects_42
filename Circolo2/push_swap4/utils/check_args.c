/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoiscardinaud <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:14:56 by francoiscardi     #+#    #+#             */
/*   Updated: 2023/03/24 17:15:20 by francoiscardi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int hasNumber(int num, char **args, int startIdx) {
    startIdx++;
    while (args[startIdx]) {
        if (ft_atoi(args[startIdx]) == num) {
            return 1;
        }
        startIdx++;
    }
    return 0;
}

static int isNumeric(char *num) {
    int i = 0;
    if (num[0] == '-') {
        i++;
    }
    while (num[i]) {
        if (!ft_isdigit(num[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

void validateInput(int argc, char **argv) {
    int i = 0;
    long tmp;
    char **args;

    if (argc == 2) {
        args = ft_split(argv[1], ' ');
    } else {
        i = 1;
        args = argv;
    }

    while (args[i]) {
        tmp = ft_atoi(args[i]);
        if (!isNumeric(args[i])) {
            ft_error("Invalid input");
        }
        if (hasNumber(tmp, args, i)) {
            ft_error("Duplicate input");
        }
        if (tmp < -2147483648 || tmp > 2147483647) {
            ft_error("Input out of range");
        }
        i++;
    }

    if (argc == 2) {
        ft_free(args);
    }
}
