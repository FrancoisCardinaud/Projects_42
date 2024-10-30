/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:10 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/29 18:12:03 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstddef>  // for std::size_t in C++98
# include <exception>

template<typename T>
class Array {
    public:
        Array(); // Default constructor
        Array(std::size_t n); // Parametrized constructor
        Array(const Array& other); // Copy constructor
        Array& operator=(const Array& other); // Copy assignment operator
        ~Array(); // Destructor

        T& operator[](std::size_t index) const; // Access operator
        std::size_t size() const; // Size getter

        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        T *storage; // Dynamic array
        std::size_t storage_size; // Size of the array
        void copyArray(const Array& other); // Helper for copying
};

// Default constructor
template<typename T>
Array<T>::Array() : storage(NULL), storage_size(0) {}

// Parametrized constructor
template<typename T>
Array<T>::Array(std::size_t n) : storage(new T[n]()), storage_size(n) {}

// Copy constructor
template<typename T>
Array<T>::Array(const Array& other) : storage(NULL), storage_size(0) {
    copyArray(other);
}

// Copy assignment operator
template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    copyArray(other);
    return *this;
}

// Helper to copy an array
template<typename T>
void Array<T>::copyArray(const Array& other) {
    if (this != &other) {
        delete[] storage;
        storage_size = other.storage_size;
        storage = new T[storage_size]();
        for (std::size_t i = 0; i < storage_size; i++)
            storage[i] = other.storage[i];
    }
}

// Destructor
template<typename T>
Array<T>::~Array() {
    delete[] storage;
}

// Access operator with bounds-checking
template <typename T>
T& Array<T>::operator[](std::size_t index) const {
    if (index >= storage_size)
        throw OutOfBoundsException();
    return storage[index];
}

// Exception message
template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
    return "Array: Exception: Index out of bounds";
}

// Get array size
template<typename T>
std::size_t Array<T>::size() const {
    return storage_size;
}

#endif
