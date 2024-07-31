/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:30:01 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 17:57:58 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack(void);
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack& other);
		~MutantStack(void);

		iterator begin(void);
		iterator end(void);
};

template<typename T>
MutantStack<T>::MutantStack(void) {
	#ifdef DEBUG
		std::cout << "[MutantStack] default constructor called" << std::endl;
	#endif
};

template<typename T>
MutantStack<T>::MutantStack(MutantStack const& other) {
	*this = other;
	#ifdef DEBUG
		std::cout << "[MutantStack] copy constructor called" << std::endl;
	#endif
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const& other)
{
	std::stack<int>::operator=(other);
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack(void) {
	#ifdef DEBUG
		std::cout << "[MutantStack] default destructor called" << std::endl;
	#endif
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
};

#endif // SPAN_HPP