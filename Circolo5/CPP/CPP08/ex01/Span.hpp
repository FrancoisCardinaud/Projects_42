/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:52 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:29:53 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdint.h>
# include <exception>
# include <vector>

class Span {
	public:
		Span(uint32_t N);
		Span(const Span &to_copy);
		Span &operator=(const Span& to_copy);
		~Span(void);

		void addNumber(int nbr);
		void addRandomNumbers(uint32_t quantity);
		int shortestSpan(void);
		int longestSpan(void);

		void printStorage(void);

		class NotEnoughElementsException : public std::exception {
			public:
				char const* what() const throw();
		};
		
		class BeyondMaxSize : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		uint32_t max_size;
		std::vector<int> storage;
		Span();
};

#endif // SPAN_HPP