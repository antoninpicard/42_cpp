/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:43:00 by anpicard          #+#    #+#             */
/*   Updated: 2026/01/16 11:33:59 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    std::cout << "=== Test 1: Basic construction and destruction ===" << std::endl;
    {
        ClapTrap clap1("CT-01");
        ClapTrap clap2("CT-02");
    }
    
    std::cout << "\n=== Test 2: Attack tests ===" << std::endl;
    {
        ClapTrap attacker("Attacker");
        attacker.attack("Target1");
        attacker.attack("Target2");
        attacker.attack("Target3");
    }
    
    std::cout << "\n=== Test 3: Taking damage ===" << std::endl;
    {
        ClapTrap victim("Victim");
        victim.takeDamage(3);
        victim.takeDamage(5);
        victim.takeDamage(10);
        victim.attack("Someone");
    }
    
    std::cout << "\n=== Test 4: Repair tests ===" << std::endl;
    {
        ClapTrap healer("Healer");
        healer.takeDamage(5);
        healer.beRepaired(3);
        healer.beRepaired(2);
    }
    
    std::cout << "\n=== Test 5: Energy depletion ===" << std::endl;
    {
        ClapTrap tired("Tired");
        for (int i = 0; i < 10; i++) {
            tired.attack("Enemy");
        }
        tired.attack("Enemy");
        tired.beRepaired(5);
    }
    
    std::cout << "\n=== Test 6: Copy constructor and assignment ===" << std::endl;
    {
        ClapTrap original("Original");
        original.takeDamage(3);
        
        ClapTrap copy1(original);
        ClapTrap copy2("Copy2");
        copy2 = original;
        
        copy1.attack("Target");
        copy2.beRepaired(2);
    }
    
    std::cout << "\n=== End of tests ===" << std::endl;
    return 0;
}
