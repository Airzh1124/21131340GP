map.o: map.cpp map.h
	g++ -pedantic-errors -std=c++11 -c map.cpp

shipplacement.o: shipplacement.cpp shipplacement.h
	g++ -pedantic-errors -std=c++11 -c shipplacement.cpp

robotplacement.o: map.o shipplacement.o robotplacement.cpp
	g++ -pedantic-errors -std=c++11 -c robotplacement.cpp

main.o: map.o shipplacement.o main.cpp
	g++ -pedantic-errors -std=c++11 -c main.cpp

main: map.o shipplacement.o main.o
	g++ -pedantic-errors -std=c++11 map.o shipplacement.o main.o -o main -l ncurses

test: map.o shipplacement.o robotplacement.o
	g++ -pedantic-errors -std=c++11 map.o shipplacement.o robotplacement.o -o test -l ncurses

clean:
	rm -f test map.o shipplacement.o robotplacement.o
