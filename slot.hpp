#pragma once

#include "snack.hpp"

class Slot
{
	const char* slotName = "NEW SLOT";
	unsigned short slotCapacity = 0;
	unsigned short slotLoad = 0;
	Snack* snackInSlot = nullptr; //массив снеков
	
	friend class Machine; //Нужно для работы Machine::addSlot(Slot* slot)
	
	public:
		Slot(const char* name, unsigned short capacity);
		Slot(const Slot &other);
		
		Slot& operator=(const Slot &other); // deep copy. Для копирования существующих объектов. https://www.learncpp.com/cpp-tutorial/shallow-vs-deep-copying/
		
		Slot() = default;
		
		~Slot(); // Не дефоолтный, т.к надо освобождать динамическую память
		
		void setName(const char* name);
		void setCapacity(unsigned short capacity);
		void setLoad(unsigned short load);
		
		const char* getName() const;
		unsigned short getCapacity() const;
		unsigned short getLoad() const;
		Snack getSnack(unsigned short number) const; //вернет снек из массива
		
		void addSnack(Snack *snack);
		void removeSnack(); //не использовал
		
		friend std::ostream &operator<< (std::ostream &output, const Slot &slot);
};
