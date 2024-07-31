/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:10 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 17:57:58 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdint.h>
# include <iostream>
# include <exception>




template<typename T>
class Array {
	public:
		Array(void);
		Array(uint32_t n);
		Array(Array& other);
		Array& operator=(Array const& other);
		T&	operator[](uint32_t n) throw(std::exception);
		~Array(void);

		uint32_t size(void);
		class OutOfBoundsException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

	private:
		T *storage;
		uint32_t storage_size;
};

template<typename T>
Array<T>::Array(void) : storage(new T[0]()), storage_size(0) {
	#ifdef LOGS
		std::cout << "[Array] Default Constructor has been called" << std::endl;
	#endif
}

template<typename T>
Array<T>::Array(uint32_t n) : storage(new T[n]()), storage_size(n) {
	#ifdef LOGS
		std::cout << "[Array] Parametrized Constructor has been called" << std::endl;
	#endif
}

template<typename T>
Array<T>::Array(Array& other)
: storage(new T[other.size()]), storage_size(other.size())
{
	*this = other;
	#ifdef LOGS
		std::cout << "[Array] Copy Constructor has been called" << std::endl;
	#endif
}

template<typename T>
Array<T>& Array<T>::operator=(Array const& other)
{
	delete[] this->storage;
	this->storage = new T[other.storage_size];
	this->storage_size = other.storage_size;
	for (uint32_t i = 0; i < other.storage_size; i += 1)
		this->storage[i] = other.storage[i];
	#ifdef LOGS
		std::cout << "[Array] Copy Assignment Operator has been called" << std::endl;
	#endif
	return *this;
}

template <typename T>
T&	Array<T>::operator[](uint32_t n) throw(std::exception)
{
	if (n >= this->storage_size)
		throw Array<T>::OutOfBoundsException();
	return this->storage[n];
}

template <typename T>
Array<T>::~Array(void) {
	delete[] this->storage;
	#ifdef LOGS
		std::cout << "[Array] Default Destructor has been called" << std::endl;
	#endif
}

template<typename T>
uint32_t Array<T>::size(void) {
	return this->storage_size;
}

template <typename T>
char const*	Array<T>::OutOfBoundsException::what(void) const throw() {
	return "Array: Exception: index out of bounds";
}

#endif // ARRAY_HPP