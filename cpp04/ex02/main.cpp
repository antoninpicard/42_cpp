/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:02:00 by anpicard          #+#    #+#             */
/*   Updated: 2026/01/16 13:08:37 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "=== Testing Abstract Class ===" << std::endl;
    std::cout << "Note: Cannot instantiate AAnimal directly!" << std::endl;
    
    std::cout << "\n=== Testing Derived Classes ===" << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    
    std::cout << "\n=== Testing getType() ===" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    std::cout << "\n=== Testing makeSound() ===" << std::endl;
    i->makeSound();
    j->makeSound();
    
    std::cout << "\n=== Deleting Animals ===" << std::endl;
    delete j;
    delete i;
    
    std::cout << "\n=== Testing Array of Animals ===" << std::endl;
    const int arraySize = 6;
    AAnimal* animals[arraySize];
    
    std::cout << "\n--- Creating Dogs ---" << std::endl;
    for (int idx = 0; idx < arraySize / 2; idx++) {
        animals[idx] = new Dog();
    }
    
    std::cout << "\n--- Creating Cats ---" << std::endl;
    for (int idx = arraySize / 2; idx < arraySize; idx++) {
        animals[idx] = new Cat();
    }
    
    std::cout << "\n--- Testing Sounds ---" << std::endl;
    for (int idx = 0; idx < arraySize; idx++) {
        std::cout << animals[idx]->getType() << " says: ";
        animals[idx]->makeSound();
    }
    
    std::cout << "\n--- Deleting Animals ---" << std::endl;
    for (int idx = 0; idx < arraySize; idx++) {
        delete animals[idx];
    }
    
    std::cout << "\n=== Testing Deep Copy ===" << std::endl;
    std::cout << "\n--- Creating Original Dog ---" << std::endl;
    Dog* originalDog = new Dog();
    originalDog->getBrain()->setIdea(0, "I want to chase cats");
    originalDog->getBrain()->setIdea(1, "I love bones");
    
    std::cout << "\n--- Creating Copy of Dog ---" << std::endl;
    Dog* copiedDog = new Dog(*originalDog);
    
    std::cout << "\n--- Verifying Deep Copy ---" << std::endl;
    std::cout << "Original Dog's idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog's idea 0: " << copiedDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Original Dog's Brain address: " << originalDog->getBrain() << std::endl;
    std::cout << "Copied Dog's Brain address: " << copiedDog->getBrain() << std::endl;
    
    if (originalDog->getBrain() != copiedDog->getBrain()) {
        std::cout << "SUCCESS: Deep copy verified - Brain addresses are different!" << std::endl;
    } else {
        std::cout << "FAILURE: Shallow copy detected - Brain addresses are the same!" << std::endl;
    }
    
    std::cout << "\n--- Modifying Original Dog's Brain ---" << std::endl;
    originalDog->getBrain()->setIdea(0, "I want to sleep");
    std::cout << "Original Dog's idea 0 after modification: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog's idea 0 after original modification: " << copiedDog->getBrain()->getIdea(0) << std::endl;
    
    if (originalDog->getBrain()->getIdea(0) != copiedDog->getBrain()->getIdea(0)) {
        std::cout << "SUCCESS: Deep copy verified - Ideas are independent!" << std::endl;
    } else {
        std::cout << "FAILURE: Shallow copy detected - Ideas are linked!" << std::endl;
    }
    
    std::cout << "\n--- Deleting Dogs ---" << std::endl;
    delete originalDog;
    delete copiedDog;
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    return 0;
}
