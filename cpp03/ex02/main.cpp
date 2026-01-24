/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:14:00 by anpicard          #+#    #+#             */
/*   Updated: 2026/01/15 11:11:18 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "=== Test 1: FragTrap Construction/Destruction chaining ===" << std::endl;
    {
        std::cout << "\n--- Creating FragTrap ---" << std::endl;
        FragTrap frag("FT-01");
        std::cout << "\n--- Destroying FragTrap ---" << std::endl;
    }
    
    std::cout << "\n=== Test 2: All three types comparison ===" << std::endl;
    {
        ClapTrap clap("ClapTrap");
        ScavTrap scav("ScavTrap");
        FragTrap frag("FragTrap");
        
        std::cout << "\n--- ClapTrap attacks ---" << std::endl;
        clap.attack("Enemy");
        
        std::cout << "\n--- ScavTrap attacks ---" << std::endl;
        scav.attack("Enemy");
        
        std::cout << "\n--- FragTrap attacks ---" << std::endl;
        frag.attack("Enemy");
    }
    
    std::cout << "\n=== Test 3: FragTrap special ability ===" << std::endl;
    {
        FragTrap friendly("Friendly");
        friendly.highFivesGuys();
        friendly.attack("Target");
        friendly.highFivesGuys();
    }
    
    std::cout << "\n=== Test 4: FragTrap vs ScavTrap special abilities ===" << std::endl;
    {
        ScavTrap guard("Guardian");
        FragTrap buddy("Buddy");
        
        guard.guardGate();
        buddy.highFivesGuys();
        
        guard.attack("Intruder");
        buddy.attack("Intruder");
    }
    
    std::cout << "\n=== Test 5: FragTrap taking damage ===" << std::endl;
    {
        FragTrap tank("Tank");
        tank.takeDamage(40);
        tank.takeDamage(30);
        tank.beRepaired(25);
        tank.highFivesGuys();
        tank.takeDamage(55);
        tank.attack("Enemy");
    }
    
    std::cout << "\n=== Test 6: FragTrap energy management ===" << std::endl;
    {
        FragTrap energetic("Energetic");
        for (int i = 0; i < 10; i++) {
            energetic.attack("Target");
        }
        energetic.beRepaired(15);
        energetic.highFivesGuys();
    }
    
    std::cout << "\n=== Test 7: Copy constructor and assignment ===" << std::endl;
    {
        std::cout << "\n--- Creating original ---" << std::endl;
        FragTrap original("Original");
        original.takeDamage(30);
        
        std::cout << "\n--- Copy constructor ---" << std::endl;
        FragTrap copy1(original);
        
        std::cout << "\n--- Assignment operator ---" << std::endl;
        FragTrap copy2("Copy2");
        copy2 = original;
        
        std::cout << "\n--- Testing copies ---" << std::endl;
        copy1.attack("Target1");
        copy2.highFivesGuys();
        
        std::cout << "\n--- Destroying copies ---" << std::endl;
    }
    
    std::cout << "\n=== Test 8: Multiple FragTraps ===" << std::endl;
    {
        FragTrap team1("Alpha");
        FragTrap team2("Bravo");
        FragTrap team3("Charlie");
        
        team1.highFivesGuys();
        team2.attack("Enemy");
        team3.highFivesGuys();
        
        team1.beRepaired(10);
        team2.highFivesGuys();
        team3.attack("Enemy");
    }
    
    std::cout << "\n=== Test 9: Mixed types interaction ===" << std::endl;
    {
        ClapTrap clap("Clap");
        ScavTrap scav("Scav");
        FragTrap frag("Frag");
        
        clap.attack("Target");
        scav.guardGate();
        frag.highFivesGuys();
        
        clap.beRepaired(5);
        scav.attack("Target");
        frag.attack("Target");
    }
    
    std::cout << "\n=== End of tests ===" << std::endl;
    return 0;
}
