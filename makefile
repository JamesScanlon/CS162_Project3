
output: main.o Character.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o Game.o Menu.o Queue.o Validation.o
	g++ main.o Character.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o Game.o Menu.o Queue.o Validation.o -o output

main.o: main.cpp
	g++ -c main.cpp -std=c++11

Character.o: Character.cpp
	g++ -c Character.cpp

Barbarian.o: Barbarian.cpp
	g++ -c Barbarian.cpp

Vampire.o: Vampire.cpp
	g++ -c Vampire.cpp

BlueMen.o: BlueMen.cpp
	g++ -c BlueMen.cpp

Medusa.o: Medusa.cpp
	g++ -c Medusa.cpp

HarryPotter.o: HarryPotter.cpp
	g++ -c HarryPotter.cpp

Game.o: Game.cpp
	g++ -c Game.cpp -std=c++11

Menu.o: Menu.cpp
	g++ -c Menu.cpp -std=c++11

Queue.o: Queue.cpp
	g++ -c Queue.cpp -std=c++11

Validation.o: Validation.cpp
	g++ -c Validation.cpp -std=c++11

clean:
	rm *.o output
