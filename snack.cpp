//Здесь всё просто и прозрачно

#include "snack.hpp"

#include <iostream>

Snack::Snack(const char* name, unsigned short price, unsigned short calories)
{
	snackName = name;
	snackPrice = price;
	snackCalories = calories;
}

Snack::Snack(const char* name)
{
	snackName = name;
}

Snack::Snack(const Snack &other)
{
	this->snackName = other.snackName;
	this->snackPrice = other.snackPrice;
	this->snackCalories = other.snackCalories;
}

void Snack::setName(const char* name)
{
	snackName = name;
}

void Snack::setPrice(unsigned short price)
{
	snackPrice = price;
}

void Snack::setCalories(unsigned short calories)
{
	snackCalories = calories;
}

const char* Snack::getName() const
{
	return snackName;
}

unsigned short Snack::getPrice() const
{
	return snackPrice;
}

unsigned short Snack::getCalories() const
{
	return snackCalories;
}

std::ostream &operator<<(std::ostream &output, const Snack &snack)
{
	output 	<< "Snack name:		" << snack.snackName << std::endl
		<< "Snack price		" << snack.snackPrice << std::endl
		<< "Snack calories:		" << snack.snackCalories << std::endl;
		
	return output;
}
