#include <iostream>

#include "machine.hpp"

int main()
{
	// Ну что, прогоним для начала минимальные требования
	//Хотя, пожалуй, только их и выполним
	
	Snack *bounty = new Snack("bounty");
	Snack *snickers = new Snack("snickers");
	
	Slot *slot = new Slot("Snack Slot", 10);
	Slot *testSlot = new Slot("Test slot", 5);
	
	slot->addSnack(bounty);
	slot->addSnack(snickers);
	
	Machine *machine = new Machine("My Machine", 10);
	machine->addSlot(slot); 
	machine->addSlot(testSlot);
	
	std::cout << std::endl;
	std::cout << *machine << std::endl; 
	
	std::cout << *machine->getSlot(0) << std::endl; // Провверка работы функций
	std::cout << *machine->getSlot(1) << std::endl;
	std::cout << *machine->getSlot(2) << std::endl;
	
	std::cout << "Empty slots in \"" << machine->getName() << "\" = " << machine->getEmptySlotsCount() << std::endl;
	
	*testSlot = *slot; // проверка адекватности копирования
	std::cout << std::endl;
	std::cout << *testSlot << std::endl; 
	
	delete machine;
	delete slot;
	delete testSlot; // раз удаляется, значит копирование сработало как надо
	delete snickers;
	delete bounty;
	
	return 0;
} 
