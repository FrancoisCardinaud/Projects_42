/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:26:43 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/17 18:24:31 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Serialization.hpp"

int main() {
    Data foo;
    uintptr_t reinterpreted;

    foo.dummy_str = "test";
    reinterpreted = Serialization::serialize(&foo);

    std::cout << "Original foo (Data) Address = " << &foo << std::endl;
    std::cout << "dummy_str value = " << foo.dummy_str << std::endl;

    std::cout << std::endl;

    std::cout << "Serialized foo value = " << reinterpreted << std::endl;

    std::cout << std::endl;

    Data *deserialized = Serialization::deserialize(reinterpreted);

    std::cout << "Deserialized Address = " << deserialized << std::endl;
    std::cout << "dummy_str value = " << deserialized->dummy_str << std::endl;

    std::cout << "------------------------------" << std::endl;

    // Edge case: nullptr serialization
    std::cout << "TEST: Serialization and deserialization of nullptr" << std::endl;
    Data* nullData = NULL;
    uintptr_t serializedNull = Serialization::serialize(nullData);
    std::cout << "Serialized nullptr: " << serializedNull << std::endl;
    Data* deserializedNull = Serialization::deserialize(serializedNull);
    std::cout << "Deserialized nullptr: " << deserializedNull << std::endl;
    std::cout << "------------------------------" << std::endl;

    // Edge case: Double serialization
    std::cout << "TEST: Double serialization and deserialization" << std::endl;
    Data foo2;
    foo2.dummy_str = "Double Serialize Test";
    uintptr_t serializedTwice = Serialization::serialize(&foo2);
    uintptr_t serializedAgain = Serialization::serialize(reinterpret_cast<Data*>(serializedTwice));
    Data* deserializedTwice = Serialization::deserialize(serializedAgain);
    std::cout << "Original foo2 (Data) Address = " << &foo2 << std::endl;
    std::cout << "Deserialized Twice Address = " << deserializedTwice << std::endl;
    std::cout << "Deserialized Twice dummy_str value = " << deserializedTwice->dummy_str << std::endl;
    std::cout << "------------------------------" << std::endl;

    // Edge case: Uninitialized pointer
    std::cout << "TEST: Uninitialized pointer" << std::endl;
    Data* uninitializedData = NULL;
    uintptr_t serializedUninitialized = Serialization::serialize(uninitializedData);
    std::cout << "Serialized uninitialized pointer: " << serializedUninitialized << std::endl;
    Data* deserializedUninitialized = Serialization::deserialize(serializedUninitialized);
    std::cout << "Deserialized uninitialized pointer: " << deserializedUninitialized << std::endl;
    std::cout << "------------------------------" << std::endl;

    // Edge case: Large Data Structure
    std::cout << "TEST: Large Data Structure" << std::endl;
    Data largeData;
    largeData.dummy_str = std::string(1000, 'X');  // String of 1000 X's
    uintptr_t serializedLargeData = Serialization::serialize(&largeData);
    std::cout << "Serialized large data: " << serializedLargeData << std::endl;
    Data* deserializedLargeData = Serialization::deserialize(serializedLargeData);
    std::cout << "Deserialized large data dummy_str length: " << deserializedLargeData->dummy_str.length() << std::endl;
    std::cout << "------------------------------" << std::endl;

    // Edge case: Multiple instances
    std::cout << "TEST: Multiple Data instances" << std::endl;
    Data foo3, foo4;
    foo3.dummy_str = "Foo3 Data";
    foo4.dummy_str = "Foo4 Data";
    uintptr_t serializedFoo3 = Serialization::serialize(&foo3);
    uintptr_t serializedFoo4 = Serialization::serialize(&foo4);
    Data* deserializedFoo3 = Serialization::deserialize(serializedFoo3);
    Data* deserializedFoo4 = Serialization::deserialize(serializedFoo4);
    std::cout << "Deserialized Foo3 dummy_str: " << deserializedFoo3->dummy_str << std::endl;
    std::cout << "Deserialized Foo4 dummy_str: " << deserializedFoo4->dummy_str << std::endl;
    std::cout << "------------------------------" << std::endl;

    // Edge case: Casting non-Data object
    std::cout << "TEST: Casting non-Data object" << std::endl;
    uintptr_t fakeDataPointer = 0xDEADBEEF;  // Fake pointer value
    Data* deserializedFake = Serialization::deserialize(fakeDataPointer);
    std::cout << "Deserialized Fake Address: " << deserializedFake << std::endl;
    if (deserializedFake == NULL)
        std::cout << "Fake pointer deserialization resulted in nullptr (as expected)." << std::endl;

    return EXIT_SUCCESS;
}
