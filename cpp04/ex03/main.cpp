/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:05:00 by anpicard          #+#    #+#             */
/*   Updated: 2026/01/24 10:05:00 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    
    std::cout << "\n=== Additional Test 1: Full Inventory ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* hero = new Character("hero");

        AMateria* tmp;
        for (int i = 0; i < 5; i++) {
            tmp = src->createMateria("ice");
            hero->equip(tmp);
            if (i == 4) {
                // Inventory is full, need to delete the materia
                delete tmp;
            }
        }

        delete hero;
        delete src;
    }

    std::cout << "\n=== Additional Test 2: Unequip and Memory Management ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* player = new Character("player");

        AMateria* ice = src->createMateria("ice");
        AMateria* cure = src->createMateria("cure");
        
        player->equip(ice);
        player->equip(cure);

        ICharacter* enemy = new Character("enemy");
        player->use(0, *enemy);
        player->use(1, *enemy);

        // Unequip and save addresses to delete later
        player->unequip(0);
        player->unequip(1);

        // Delete unequipped materias
        delete ice;
        delete cure;

        delete enemy;
        delete player;
        delete src;
    }

    std::cout << "\n=== Additional Test 3: Invalid Operations ===" << std::endl;
    {
        ICharacter* test = new Character("test");
        
        // Try to use empty slot
        test->use(0, *test);
        
        // Try to use invalid slot
        test->use(-1, *test);
        test->use(5, *test);
        
        // Try to unequip empty slot
        test->unequip(0);
        
        // Try to unequip invalid slot
        test->unequip(-1);
        test->unequip(5);

        delete test;
    }

    std::cout << "\n=== Additional Test 4: Unknown Materia Type ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());

        AMateria* unknown = src->createMateria("fire");
        if (!unknown) {
            std::cout << "Correctly returned NULL for unknown type" << std::endl;
        }

        delete src;
    }

    std::cout << "\n=== Additional Test 5: Deep Copy Test ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        Character* original = new Character("original");
        AMateria* ice = src->createMateria("ice");
        AMateria* cure = src->createMateria("cure");
        original->equip(ice);
        original->equip(cure);

        std::cout << "\n--- Creating copy ---" << std::endl;
        Character* copy = new Character(*original);

        std::cout << "\n--- Testing copy ---" << std::endl;
        ICharacter* target = new Character("target");
        copy->use(0, *target);
        copy->use(1, *target);

        delete target;
        delete copy;
        delete original;
        delete src;
    }

    std::cout << "\n=== Additional Test 6: MateriaSource Full ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        
        src->learnMateria(new Ice());
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->learnMateria(new Cure());
        
        AMateria* ice3 = new Ice();
        src->learnMateria(ice3); // Should fail, source is full
        delete ice3; // Need to delete since it wasn't added

        delete src;
    }

    std::cout << "\n=== End of Tests ===" << std::endl;
    return 0;
}
