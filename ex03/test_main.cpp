#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void test_basic()
{
	std::cout << "\n=== TEST BASIC (from subject) ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(cure);
	delete ice;
	delete cure;

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
}

void test_deep_copy()
{
	std::cout << "\n=== TEST DEEP COPY ===" << std::endl;
	Character* original = new Character("original");
	
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	
	original->equip(ice);
	original->equip(cure);
	
	Character* copy = new Character(*original);
	
	ICharacter* target = new Character("target");
	
	std::cout << "Original uses materias:" << std::endl;
	original->use(0, *target);
	original->use(1, *target);
	
	std::cout << "Copy uses materias:" << std::endl;
	copy->use(0, *target);
	copy->use(1, *target);
	
	delete target;
	delete copy;
	delete original;
}

void test_inventory_limits()
{
	std::cout << "\n=== TEST INVENTORY LIMITS (4 slots) ===" << std::endl;
	Character* character = new Character("test");
	
	AMateria* m1 = new Ice();
	AMateria* m2 = new Cure();
	AMateria* m3 = new Ice();
	AMateria* m4 = new Cure();
	AMateria* m5 = new Ice();
	
	character->equip(m1);
	character->equip(m2);
	character->equip(m3);
	character->equip(m4);
	
	std::cout << "Trying to equip 5th materia (should be ignored):" << std::endl;
	character->equip(m5);
	
	ICharacter* target = new Character("target");
	std::cout << "Using all 4 slots:" << std::endl;
	character->use(0, *target);
	character->use(1, *target);
	character->use(2, *target);
	character->use(3, *target);
	
	std::cout << "Using non-existent slot 4 (should do nothing):" << std::endl;
	character->use(4, *target);
	
	delete target;
	delete character;
	delete m5;
}

void test_unequip()
{
	std::cout << "\n=== TEST UNEQUIP ===" << std::endl;
	Character* character = new Character("test");
	
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	
	character->equip(ice);
	character->equip(cure);
	
	ICharacter* target = new Character("target");
	
	std::cout << "Before unequip:" << std::endl;
	character->use(0, *target);
	character->use(1, *target);
	
	std::cout << "Unequipping slot 0..." << std::endl;
	character->unequip(0);
	
	std::cout << "After unequip (slot 0 should do nothing):" << std::endl;
	character->use(0, *target);
	character->use(1, *target);
	
	std::cout << "Unequipping invalid slot -1 (should do nothing):" << std::endl;
	character->unequip(-1);
	
	std::cout << "Unequipping invalid slot 10 (should do nothing):" << std::endl;
	character->unequip(10);
	
	delete target;
	delete character;
	delete ice;
}

void test_materia_source()
{
	std::cout << "\n=== TEST MATERIA SOURCE ===" << std::endl;
	MateriaSource* src = new MateriaSource();
	
	std::cout << "Learning Ice and Cure..." << std::endl;
	AMateria* ice_template = new Ice();
	AMateria* cure_template = new Cure();
	src->learnMateria(ice_template);
	src->learnMateria(cure_template);
	delete ice_template;
	delete cure_template;
	
	std::cout << "Creating ice materia:" << std::endl;
	AMateria* ice = src->createMateria("ice");
	if (ice)
		std::cout << "Created: " << ice->getType() << std::endl;
	
	std::cout << "Creating cure materia:" << std::endl;
	AMateria* cure = src->createMateria("cure");
	if (cure)
		std::cout << "Created: " << cure->getType() << std::endl;
	
	std::cout << "Creating unknown materia (should return NULL):" << std::endl;
	AMateria* unknown = src->createMateria("fire");
	if (!unknown)
		std::cout << "Correctly returned NULL for unknown type" << std::endl;
	
	delete ice;
	delete cure;
	delete src;
}

void test_materia_source_limits()
{
	std::cout << "\n=== TEST MATERIA SOURCE LIMITS (4 templates) ===" << std::endl;
	MateriaSource* src = new MateriaSource();
	
	AMateria* m1 = new Ice();
	AMateria* m2 = new Cure();
	AMateria* m3 = new Ice();
	AMateria* m4 = new Cure();
	AMateria* m5 = new Ice();
	
	src->learnMateria(m1);
	src->learnMateria(m2);
	src->learnMateria(m3);
	src->learnMateria(m4);
	
	delete m1;
	delete m2;
	delete m3;
	delete m4;
	
	std::cout << "Trying to learn 5th materia (should be ignored):" << std::endl;
	src->learnMateria(m5);
	delete m5;
	
	delete src;
}

void test_assignment_operator()
{
	std::cout << "\n=== TEST ASSIGNMENT OPERATOR ===" << std::endl;
	Character* char1 = new Character("char1");
	Character* char2 = new Character("char2");
	
	char1->equip(new Ice());
	char1->equip(new Cure());
	
	ICharacter* target = new Character("target");
	
	std::cout << "char1 before assignment:" << std::endl;
	char1->use(0, *target);
	char1->use(1, *target);
	
	std::cout << "char2 before assignment:" << std::endl;
	char2->use(0, *target);
	char2->use(1, *target);
	
	*char2 = *char1;
	
	std::cout << "char2 after assignment (should have char1's materias):" << std::endl;
	char2->use(0, *target);
	char2->use(1, *target);
	
	delete target;
	delete char1;
	delete char2;
}

int main()
{
	test_basic();
	test_deep_copy();
	test_inventory_limits();
	test_unequip();
	test_materia_source();
	test_materia_source_limits();
	test_assignment_operator();
	
	std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
	return 0;
}
