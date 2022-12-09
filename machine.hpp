#pragma once

#include "slot.hpp"

class Machine
{
	const char* machineName = "New Machine";
	unsigned short machineCapacity = 0;
	unsigned short machineLoad = 0;
	Slot* slotInMachine = nullptr; // Массив слотов
	
	friend class Slot; //Нужно для работы Machine::addSlot(Slot* slot)
	
	public:
		Machine(const char* name, unsigned short capacity);
		Machine(const Machine &other);
		Machine() = default;
		
		~Machine();
		
		void setName(const char* name);
		void setCapacity(unsigned short capacity);
		
		const char* getName() const;
		unsigned short getCapacity() const;
		unsigned short getLoad() const;
		unsigned short getEmptySlotsCount() const;
		Slot* getSlot(unsigned short number) const;
		
		void addSlot(Slot *slot);
		void removeSlot();

		friend std::ostream &operator<< (std::ostream &output, const Machine &machine);

};
