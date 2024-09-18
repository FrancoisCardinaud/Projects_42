/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:30:01 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 17:30:44 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		// Typedef for iterator type to match the underlying container's iterator
		typedef typename std::stack<T>::container_type::iterator iterator;

		// Default constructor
		MutantStack(void);
		
		// Copy constructor
		MutantStack(const MutantStack &other);

		// Assignment operator overload
		MutantStack &operator=(const MutantStack& other);

		// Destructor
		~MutantStack(void);

		// Iterator access methods
		iterator begin(void);
		iterator end(void);
};

// Implementation of default constructor
template<typename T>
MutantStack<T>::MutantStack(void) {
	#ifdef DEBUG
		std::cout << "[MutantStack] Default constructor called" << std::endl;
	#endif
}

// Implementation of copy constructor
template<typename T>
MutantStack<T>::MutantStack(MutantStack const& other) {
	*this = other;
	#ifdef DEBUG
		std::cout << "[MutantStack] Copy constructor called" << std::endl;
	#endif
}

// Implementation of assignment operator
template<typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const& other) {
	if (this != &other)
		std::stack<T>::operator=(other); // Use base class operator=
	return *this;
}

// Implementation of destructor
template<typename T>
MutantStack<T>::~MutantStack(void) {
	#ifdef DEBUG
		std::cout << "[MutantStack] Destructor called" << std::endl;
	#endif
}

// Begin iterator pointing to the start of the stack's underlying container
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin(); // 'c' is the protected container of std::stack
}

// End iterator pointing to the end of the stack's underlying container
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}

#endif // MUTANTSTACK_HPP
