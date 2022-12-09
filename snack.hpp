#pragma once

#include <iostream>

class Snack
{
	const char* snackName = "NEW SNACK";	//чтобы были хоть какие-то значения
	unsigned short snackPrice = 0;
	unsigned short snackCalories = 0;
	
	public:
		Snack(const char* name, unsigned short price, unsigned short calories);
		Snack(const char* name); // Если не хочется вводить цену и каллории
		Snack() = default;
		
		Snack(const Snack &other);
		
		~Snack() = default;
		
		void setName(const char* name);
		void setPrice(unsigned short price);
		void setCalories(unsigned short calories);
		
		const char* getName() const;
		unsigned short getPrice() const;
		unsigned short getCalories() const;
		
		friend std::ostream &operator<<(std::ostream &output, const Snack &snack);
};
