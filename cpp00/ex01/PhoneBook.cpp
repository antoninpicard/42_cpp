/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:41:12 by anpicard          #+#    #+#             */
/*   Updated: 2026/01/15 11:01:43 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

static int get_index();

PhoneBook::PhoneBook()
{
	currentIndex = 0;
	totalContacts = 0;
}

PhoneBook::~PhoneBook()
{
	// none
}

void PhoneBook::setContact(Contact newContact, int index)
{
	if (index >= 0 && index < 8)
	{
		contact[index] = newContact;
		if (index >= totalContacts)
			totalContacts = index + 1;
	}
}

int PhoneBook::add()
{
	std::string input;
	Contact newContact;

	do
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
		if (!std::cin)
		{
			std::cin.clear();
			return (1);
		}
	} while (input.empty());
	newContact.setFirstName(input);
	do
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, input);
		if (!std::cin)
		{
			std::cin.clear();
			return (1);
		}
	} while (input.empty());
	newContact.setLastName(input);
	do
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, input);
		if (!std::cin)
		{
			std::cin.clear();
			return (1);
		}
	} while (input.empty());
	newContact.setNickName(input);
	do
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		if (!std::cin)
		{
			std::cin.clear();
			return (1);
		}
	} while (input.empty());
	newContact.setPhoneNumber(input);
	do
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, input);
		if (!std::cin)
		{
			std::cin.clear();
			return (1);
		}
	} while (input.empty());
	newContact.setDarkestSecret(input);
	setContact(newContact, currentIndex);
	currentIndex = (currentIndex + 1) % 8;
	std::cout << "Contact added successfully!" << std::endl;
	return (0);
}

int PhoneBook::search()
{
	if (PhoneBook::totalContacts > 0)
	{
		std::cout << "     INDEX| FIRSTNAME|  LASTNAME|  NICKNAME|" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		for (int i = 0; i < PhoneBook::totalContacts; i++)
		{
			std::cout << std::setw(10) << i << "|";
			if (PhoneBook::contact[i].getFirstName().size() >= 10)
				std::cout << std::setw(10) << PhoneBook::contact[i].getFirstName().substr(0, 9) + ".|";
			else
				std::cout << std::setw(10) << PhoneBook::contact[i].getFirstName() << "|";
			if (PhoneBook::contact[i].getLastName().size() >= 10)
				std::cout << std::setw(10) << PhoneBook::contact[i].getLastName().substr(0, 9) + ".|";
			else
				std::cout << std::setw(10) << PhoneBook::contact[i].getLastName() << "|";
			if (PhoneBook::contact[i].getNickname().size() >= 10)
				std::cout << std::setw(10) << PhoneBook::contact[i].getNickname().substr(0, 9) + ".|" << std::endl;
			else
				std::cout << std::setw(10) << PhoneBook::contact[i].getNickname() << "|" << std::endl;
		}
		int index = get_index();
		if (index < 0)
			return (1);
		if (index >= PhoneBook::totalContacts)
			std::cout << "No contact found at this index" << std::endl;
		else
		{
			std::cout << "FirstName : " << PhoneBook::contact[index].getFirstName() << std::endl;
			std::cout << "LastName : " << PhoneBook::contact[index].getLastName() << std::endl;
			std::cout << "NickName : " << PhoneBook::contact[index].getNickname() << std::endl;
			std::cout << "PhoneNumber : " << PhoneBook::contact[index].getPhoneNumber() << std::endl;
			std::cout << "Darkest secret: " << PhoneBook::contact[index].getDarkestSecret() << std::endl;
		}
	}
	else
		std::cout << "No contacts available" << std::endl;
	return (0);
}

static int get_index()
{
	std::string str;
	do
	{
		std::cout << "Enter an index (0-7) : ";
		std::getline(std::cin, str);
		if (!std::cin)
		{
			std::cin.clear();
			return (-1);
		}
	} while (!(str.size() == 1 && (str[0] >= '0' && str[0] <= '9')));
	return (std::atoi(str.c_str()));
}