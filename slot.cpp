#include "slot.hpp"

Slot::Slot(const char* name, unsigned short capacity)
{
	this->slotName = name;
	this->slotCapacity = capacity;
	
	if (this->slotCapacity && (this->snackInSlot == nullptr)) //проверки на существование массива снеков  и выделение/удаление масссива снеков
	{
		this->snackInSlot = new Snack[slotCapacity];      //на сколько я понимаю "this->" избыточно, если переменная объекта и аргумент функции имеют разные имена ?
	}
		else if (this->slotCapacity && this->snackInSlot)
	{
		delete[] this->snackInSlot;
		this->snackInSlot = new Snack[this->slotCapacity];
	}
	else if ((this->slotCapacity == 0) && (this->snackInSlot != nullptr))
	{
		delete[] this->snackInSlot;
	}
	else
	{
		; //do nothing
	}
}


Slot::Slot(const Slot &other)  //Конструктор копирования
{
	this->slotName = other.slotName;
	this->slotCapacity = other.slotCapacity;
	this->slotLoad = 0;

	if (this->slotCapacity && (this->snackInSlot == nullptr))
	{
		this->snackInSlot = new Snack[slotCapacity];
	}
		else if (this->slotCapacity && this->snackInSlot)
	{
		delete[] snackInSlot;
		this->snackInSlot = new Snack[slotCapacity];
	}
	else if ((this->slotCapacity == 0) && (this->snackInSlot != nullptr))
	{
		delete[] snackInSlot;
	}
	else
	{
		; //do nothing
	}



}


Slot& Slot::operator=(const Slot &other)	//Для копирования существующего объекта  https://www.learncpp.com/cpp-tutorial/shallow-vs-deep-copying/
{
	if (this != &other)
	{
		slotName = other.slotName;
		slotCapacity = other.slotCapacity;
		slotLoad = 0;
		delete[] snackInSlot;
		this->snackInSlot = new Snack[slotCapacity];
	}
	return *this;
}
	
	
Slot::~Slot()
{
	if (snackInSlot != nullptr)
	{
		delete[] snackInSlot;
	}
}


void Slot::setName(const char* name)
{
	slotName = name;
}


void Slot::setCapacity(unsigned short capacity)
{
	slotCapacity = capacity;
	
	if (capacity && (snackInSlot == nullptr))	//новый объём - новый размер массива
	{
		snackInSlot = new Snack[slotCapacity];
	}
		else if (capacity && snackInSlot)
	{
		delete[] snackInSlot;
		snackInSlot = new Snack[slotCapacity];
	}
	else if ((capacity == 0) && (snackInSlot != nullptr))
	{
		delete[] snackInSlot;
	}
	else
	{
		; //do nothing
	}
	
	slotLoad = 0;
}


void Slot::setLoad(unsigned short load)
{
	slotLoad = load;
}


const char* Slot::getName() const
{
	return slotName;
}


unsigned short Slot::getCapacity() const
{
	return slotCapacity;
}


unsigned short Slot::getLoad() const
{
	return slotLoad;
}

Snack Slot::getSnack(unsigned short number) const
{
	return snackInSlot[number];
}


void Slot::addSnack(Snack *snack) //Добавляет снек в массив
{
	if (slotLoad < slotCapacity)
	{
		snackInSlot[slotLoad] = *snack;
		++slotLoad;
	}
	else
	{
		std::cout << "Slot is already full" << std::endl;
	}
}

void Slot::removeSnack() //Вроде как должен убрать снек из массива и сдвинуть массив влево на 1. Не пробовал.
{
	if (slotLoad)
	{
		snackInSlot[0].~Snack();
		
		for (int i = 0; i < (slotLoad - 1); ++i)
		{
			snackInSlot[i] = snackInSlot[i+1];
		}
		snackInSlot[slotLoad].~Snack();
		--slotLoad;
	}
}

std::ostream &operator<< (std::ostream &output, const Slot &slot)
{
	output	<< "Slot name: " << slot.slotName << std::endl
		<< "Slot load: " << slot.slotLoad << " / " << slot.slotCapacity << std::endl
		<< "Slot contains:" << std::endl << "--------------" << std::endl;
			for (int i = 0; i < slot.slotLoad; ++i)
			{
				output << slot.snackInSlot[i].getName() << std::endl;
			}
	output	<< "--------------" << std::endl;
			
	return output;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

