/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:52 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/30 17:56:22 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <algorithm>

class Span {
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span& other);
		~Span(void);

		void addNumber(int nbr);
		void addRandomNumbers(unsigned int quantity);
		int64_t shortestSpan(void) const;
		int64_t longestSpan(void) const;
		void printStorage(void) const;

		class NotEnoughElementsException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class BeyondMaxSize : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		Span(); // Private default constructor to prevent instantiation without size
		unsigned int max_size;
		std::vector<int> storage;
};

#endif
