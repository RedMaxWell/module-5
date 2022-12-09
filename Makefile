main: snack.o slot.o machine.o main.o
	g++ -Wall -o main snack.o slot.o machine.o main.o
	
main.o: main.cpp
	g++ -Wall -c main.cpp

machine.o: machine.cpp
	g++ -Wall -c machine.cpp
	
slot.o: slot.cpp
	g++ -Wall -c slot.cpp
	
snack.o: snack.cpp
	g++ -Wall -c snack.cpp
