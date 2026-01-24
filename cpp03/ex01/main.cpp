/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:14:00 by anpicard          #+#    #+#             */
/*   Updated: 2026/01/15 11:10:08 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "=== Test 1: Construction/Destruction chaining ===" << std::endl;
    {
        std::cout << "\n--- Creating ScavTrap ---" << std::endl;
        ScavTrap scav("ST-01");
        std::cout << "\n--- Destroying ScavTrap ---" << std::endl;
    }
    
    std::cout << "\n=== Test 2: ScavTrap vs ClapTrap ===" << std::endl;
    {
        ClapTrap clap("ClapTrap");
        ScavTrap scav("ScavTrap");
        
        std::cout << "\n--- ClapTrap attacks ---" << std::endl;
        clap.attack("Enemy");
        
        std::cout << "\n--- ScavTrap attacks ---" << std::endl;
        scav.attack("Enemy");
    }
    
    std::cout << "\n=== Test 3: ScavTrap special ability ===" << std::endl;
    {
        ScavTrap guard("Guardian");
        guard.guardGate();
        guard.attack("Intruder");
        guard.guardGate();
    }
    
    std::cout << "\n=== Test 4: ScavTrap taking damage ===" << std::endl;
    {
        ScavTrap tank("Tank");
        tank.takeDamage(30);
        tank.takeDamage(50);
        tank.beRepaired(20);
        tank.takeDamage(40);
        tank.attack("Enemy");
    }
    
    std::cout << "\n=== Test 5: ScavTrap energy management ===" << std::endl;
    {
        ScavTrap fighter("Fighter");
        for (int i = 0; i < 5; i++) {
            fighter.attack("Target");
        }
        fighter.beRepaired(10);
        fighter.guardGate();
    }
    
    std::cout << "\n=== Test 6: Copy constructor and assignment ===" << std::endl;
    {
        std::cout << "\n--- Creating original ---" << std::endl;
        ScavTrap original("Original");
        original.takeDamage(20);
        
        std::cout << "\n--- Copy constructor ---" << std::endl;
        ScavTrap copy1(original);
        
        std::cout << "\n--- Assignment operator ---" << std::endl;
        ScavTrap copy2("Copy2");
        copy2 = original;
        
        std::cout << "\n--- Testing copies ---" << std::endl;
        copy1.attack("Target1");
        copy2.guardGate();
        
        std::cout << "\n--- Destroying copies ---" << std::endl;
    }
    
    std::cout << "\n=== Test 7: Multiple ScavTraps ===" << std::endl;
    {
        ScavTrap squad1("Alpha");
        ScavTrap squad2("Bravo");
        ScavTrap squad3("Charlie");
        
        squad1.guardGate();
        squad2.attack("Enemy");
        squad3.guardGate();
    }
    
    std::cout << "\n=== End of tests ===" << std::endl;
    return 0;
}
