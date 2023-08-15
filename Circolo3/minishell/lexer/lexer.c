/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:20:46 by fcardina          #+#    #+#             */
/*   Updated: 2023/08/16 01:20:47 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "brain.h"
#include "lexer_utils.h"

static void	*free_tokens(char **tokens, char **adjusted)
{
	ft_free_split(tokens);
	ft_free_split(adjusted);
	reset_lex_toks();
	return (NULL);
}

static char	*get_next_token(char **token)
{
	char	*next_token;
	char	*tmp;
	char	next_special;
	int		i;

	tmp = *token;
	next_special = get_next_special(tmp);
	next_token = ft_calloc(get_next_token_size(tmp, next_special) + 1, \
			sizeof(*next_token));
	if (next_token == NULL)
		return (NULL);
	i = 0;
	if (*tmp == next_special)
		while (*tmp && *tmp == next_special)
			next_token[i++] = *tmp++;
	else
		while (*tmp && *tmp != next_special)
			next_token[i++] = *tmp++;
	tmp = ft_substr(*token, i, ft_strlen(*token));
	if (*token == NULL)
		return (ft_free((void **)&next_token));
	free(*token);
	*token = tmp;
	return (next_token);
}

static char	*get_subshell_token(char *tokens[], int *i)
{
	char	*subshell_token;
	int		subshell_count;

	subshell_token = NULL;
	subshell_count = get_subshell_count(tokens, *i);
	while (tokens[*i] && subshell_count)
	{
		if (subshell_count == 1 && ft_strchr(tokens[*i], ')') \
		&& ft_strlen(ft_strrchr(tokens[*i], ')')) != 1)
			return (get_end_of_subshell(tokens, i, subshell_token));
		subshell_token = ft_append(&subshell_token, tokens[*i]);
		if (subshell_token == NULL)
			return (NULL);
		subshell_token = ft_append(&subshell_token, " ");
		if (subshell_token == NULL)
			return (NULL);
		if (ft_strchr(tokens[*i], '(') || ft_strchr(tokens[*i], ')'))
			subshell_count--;
		(*i)++;
	}
	return (subshell_token);
}

static char	**adjust_tokens(char **tokens)
{
	char	**adjusted;
	size_t	adjusted_size;
	int		i[2];

	adjusted_size = 50;
	adjusted = ft_calloc(adjusted_size + 1, sizeof(*adjusted));
	if (adjusted == NULL)
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	while (tokens[i[0]])
	{
		if (tokens[i[0]][0] == '(')
			adjusted[i[1]] = get_subshell_token(tokens, &i[0]);
		else if (!token_is_unadjusted(tokens[i[0]]))
			adjusted[i[1]] = ft_strdup(tokens[i[0]++]);
		else
			adjusted[i[1]] = get_next_token(&tokens[i[0]]);
		if (adjusted[i[1]++] == NULL)
			return (free_tokens(tokens, adjusted));
		if ((size_t)i[1] == adjusted_size - 1)
			adjusted = ft_str_arr_realloc(adjusted, adjusted_size += 10);
	}
	ft_free_str_array(&tokens);
	return (adjusted);
}

int	lexer(char *line)
{
	char	**tokens;
	int		exit_status;

	if (!is_valid_line_syntax(line))
		return (exit_on_syntax_error());
	tokens = ft_split_set(line, " \t\r\v\f\n");
	if (join_quotes(&tokens) == EXIT_FAILURE)
	{
		ft_free_str_array(&tokens);
		return (EXIT_FAILURE);
	}
	tokens = adjust_tokens(tokens);
	if (tokens == NULL)
		return (EXIT_FAILURE);
	set_lex_toks(tokens);
	if (!is_valid_syntax(tokens))
		return (exit_on_syntax_error());
	exit_status = parser(tokens);
	ft_free_split(tokens);
	reset_lex_toks();
	return (exit_status);
}