/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:10 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 17:08:30 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template<typename T>
class Array {
    public:
        Array(); // Default constructor
        Array(uint32_t n); // Parametrized constructor
        Array(const Array& other); // Copy constructor
        Array& operator=(const Array& other); // Copy assignment operator
        ~Array(); // Destructor

        T& operator[](uint32_t index) const; // Access operator
        uint32_t size() const; // Size getter

        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        T *storage; // Dynamic array
        uint32_t storage_size; // Size of the array
};

// Default constructor
template<typename T>
Array<T>::Array() : storage(nullptr), storage_size(0) {
    #ifdef LOGS
    std::cout << "[Array] Default constructor called" << std::endl;
    #endif
}

// Parametrized constructor
template<typename T>
Array<T>::Array(uint32_t n) : storage(new T[n]()), storage_size(n) {
    #ifdef LOGS
    std::cout << "[Array] Parametrized constructor called" << std::endl;
    #endif
}

// Copy constructor
template<typename T>
Array<T>::Array(const Array& other) : storage(nullptr), storage_size(0) {
    *this = other;
    #ifdef LOGS
    std::cout << "[Array] Copy constructor called" << std::endl;
    #endif
}

// Copy assignment operator
template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this == &other)
        return *this;

    delete[] storage;
    storage_size = other.storage_size;
    storage = new T[storage_size]();
    for (uint32_t i = 0; i < storage_size; i++)
        storage[i] = other.storage[i];

    #ifdef LOGS
    std::cout << "[Array] Copy assignment operator called" << std::endl;
    #endif

    return *this;
}

// Access operator
template <typename T>
T& Array<T>::operator[](uint32_t index) const {
    if (index >= storage_size)
        throw Array<T>::OutOfBoundsException();
    return storage[index];
}

// Destructor
template<typename T>
Array<T>::~Array() {
    delete[] storage;
    #ifdef LOGS
    std::cout << "[Array] Destructor called" << std::endl;
    #endif
}

// Get array size
template<typename T>
uint32_t Array<T>::size() const {
    return storage_size;
}

// Exception for out-of-bounds access
template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
    return "Array: Exception: Index out of bounds";
}

#endif // ARRAY_HPP
