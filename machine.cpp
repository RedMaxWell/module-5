#include "machine.hpp"

Machine::Machine(const char* name, unsigned short capacity)
{
	machineName = name;
	machineCapacity = capacity;
	
	if (machineCapacity && (slotInMachine == nullptr))
	{
		slotInMachine = new Slot[machineCapacity];
	}
	else if (machineCapacity && (slotInMachine != nullptr))
	{
		delete[] slotInMachine;
		slotInMachine = new Slot[machineCapacity];
	}
	else if ((machineCapacity == 0) && (slotInMachine != nullptr))
	{
		delete[] slotInMachine;
	}
	else
	{
		; //do nothing
	}
}

Machine::Machine(const Machine &other)
{
	this->machineName = other.machineName;
	this->machineCapacity = other.machineCapacity;
	
	if (this->machineCapacity && (this->slotInMachine == nullptr))
	{
		this->slotInMachine = new Slot[this->machineCapacity];
	}
	else if (this->machineCapacity && (this->slotInMachine != nullptr))
	{
		delete[] this->slotInMachine;
		this->slotInMachine = new Slot[this->machineCapacity];
	}
	else if ((this->machineCapacity == 0) && (this->slotInMachine != nullptr))
	{
		delete[] this->slotInMachine;
	}
	else
	{
		; //do nothing
	}
}

Machine::~Machine()
{
	if(slotInMachine)
	{
		delete[] slotInMachine;
	}
}

void Machine::setName(const char* name)
{
	machineName = name;
}

void Machine::setCapacity(unsigned short capacity)
{
	machineCapacity = capacity;
	
	if (this->machineCapacity && (this->slotInMachine == nullptr))
	{
		this->slotInMachine = new Slot[this->machineCapacity];
	}
	else if (this->machineCapacity && (this->slotInMachine != nullptr))
	{
		delete[] this->slotInMachine;
		this->slotInMachine = new Slot[this->machineCapacity];
	}
	else if ((this->machineCapacity == 0) && (this->slotInMachine != nullptr))
	{
		delete[] this->slotInMachine;
	}
	else
	{
		; //do nothing
	}
	machineLoad = 0;
}

const char* Machine::getName() const
{
	return machineName;
}

unsigned short Machine::getCapacity() const
{
	return machineCapacity;
}

unsigned short Machine::getLoad() const
{
	return machineLoad;
}

unsigned short Machine::getEmptySlotsCount() const
{
	unsigned short emptySlotsCount = 0;
	for (int i = 0; i < machineCapacity; ++i)
	{
		if (this->slotInMachine[i].getLoad() == 0)
		{
			++emptySlotsCount;
		}
	}
	return emptySlotsCount;
}

Slot* Machine::getSlot(unsigned short number) const
{
	return &slotInMachine[number]; // & вернет адрес
}
	
void Machine::addSlot(Slot *slot) // В начале в каестве аргумента посылал объект, а не адрес. Долго не мог понять почему не копируется)
{
	if (machineLoad < machineCapacity)
	{
		slotInMachine[machineLoad] = *slot;
		for(int i = 0; i < slot->getLoad(); ++i)
		{
			slotInMachine[machineLoad].addSnack(&slot->snackInSlot[i]);	//Ради этой строчки пришлось зафрендить Machine и Slot
			
		}
		++machineLoad;
		std::cout << machineLoad << " slots in machine" << std::endl;
	}
	else
	{
		std::cout << "Machine is already full" << std::endl;
	}
}

void Machine::removeSlot() //Не пробовал
{
	if (machineLoad > 0)
	{
		slotInMachine[machineLoad] = Slot();
		--machineLoad;
		std::cout << machineLoad << " slots remaining" << std::endl;
	}
	else
	{
		std::cout << "No slots in this machine" << std::endl;
	}
}

std::ostream &operator<< (std::ostream &output, const Machine &machine)
{
	output	<< "Machine name: " << machine.machineName << std::endl
		<< "Machine load: " << machine.machineLoad << " / " << machine.machineCapacity << std::endl << std::endl;
		
	return output;
 }






































