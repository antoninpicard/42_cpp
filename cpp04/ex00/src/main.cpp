/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:02:00 by anpicard          #+#    #+#             */
/*   Updated: 2026/01/16 13:07:50 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Testing Animal Polymorphism ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "\n=== Testing getType() ===" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    std::cout << "\n=== Testing makeSound() ===" << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    std::cout << "\n=== Deleting Animals ===" << std::endl;
    delete i;
    delete j;
    delete meta;
    
    std::cout << "\n=== Testing Wrong Classes (No Polymorphism) ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "\n=== Testing WrongAnimal getType() ===" << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    
    std::cout << "\n=== Testing WrongAnimal makeSound() ===" << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();
    
    std::cout << "\n=== Deleting WrongAnimals ===" << std::endl;
    delete wrongCat;
    delete wrongMeta;
    
    std::cout << "\n=== Additional Tests ===" << std::endl;
    std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
    Dog originalDog;
    Dog copiedDog(originalDog);
    
    std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
    Cat cat1;
    Cat cat2;
    cat2 = cat1;
    
    std::cout << "\n--- Testing Direct Instantiation ---" << std::endl;
    Dog dog;
    Cat cat;
    std::cout << "Dog type: " << dog.getType() << std::endl;
    std::cout << "Cat type: " << cat.getType() << std::endl;
    dog.makeSound();
    cat.makeSound();
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    return 0;
}
