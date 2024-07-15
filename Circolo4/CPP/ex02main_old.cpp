/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:15:14 by fcardina          #+#    #+#             */
/*   Updated: 2024/02/06 20:20:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
	//AAnimal *aanimal = new AAnimal();

    // Create an array of Animal pointers
    const int numAnimals = 2;
    AAnimal *aanimals[numAnimals];
    int dogCount = 0;
    int catCount = 0;

    // Fill the array with half Dog and half Cat objects
    for (int i = 0; i < numAnimals; i++)
    {
        if (i < numAnimals / 2)
            aanimals[i] = new Dog();
        else
            aanimals[i] = new Cat();
    }

    for (int i = 0; i < numAnimals; i++)
    {
        AAnimal *aanimal = aanimals[i];
        if (aanimal->getType() == "Dog")
        {
            dogCount++;
            std::cout << "Dog n°" << dogCount << " says: ";
            aanimals[i]->makeSound();
        }
        else if (aanimal->getType() == "Cat")
        {
            catCount++;
            std::cout << "Cat n°" << catCount << " says: ";
            aanimals[i]->makeSound();
        }
    }

    // Make some deep copies of animals
    for (int i = 0; i < numAnimals; i++)
    {
        AAnimal *aanimal = aanimals[i];
        if (aanimal->getType() == "Dog")
        {
            std::cout << std::endl;
            // Testing for deep copy
            Dog *dog = dynamic_cast<Dog*>(aanimal);
            Dog dogCopy(*dog);  // Create a copy using the copy constructor
            dogCopy.getBrain()->setIdea(0, "New Dog Idea");  // Modify the copy

            std::cout << "Original Dog's Idea: " << dog->getBrain()->getIdea(0) << std::endl;
            std::cout << "Copied Dog's Idea: " << dogCopy.getBrain()->getIdea(0) << std::endl;
            std::cout << std::endl;
            std::cout << "Dog says: ";
			dog->makeSound(); 
            std::cout << "DogCopy says: ";
            dogCopy.makeSound();
            std::cout << std::endl;
        }
        else if (aanimal->getType() == "Cat")
        {
            std::cout << std::endl;
            // Testing for deep copy
            Cat *cat = dynamic_cast<Cat*>(aanimal);
            Cat catCopy(*cat);  // Create a copy using the copy constructor
            catCopy.getBrain()->setIdea(0, "New Cat Idea");  // Modify the copy
            
            std::cout << "Original Cat's Idea: " << cat->getBrain()->getIdea(0) << std::endl;
            std::cout << "Copied Cat's Idea: " << catCopy.getBrain()->getIdea(0) << std::endl;
            std::cout << std::endl;
			std::cout << "Cat says: ";
            cat->makeSound();
            std::cout << "CatCopy says: ";
            catCopy.makeSound();    
            std::cout << std::endl;
        }
    }

    // Delete the original animals and their brains
    for (int i = 0; i < numAnimals; i++)
    {
        delete aanimals[i];
    }

    return (0);
}
