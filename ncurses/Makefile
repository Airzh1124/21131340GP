map.o: map.cpp map.h
	g++ -pedantic-errors -std=c++11 -c map.cpp

shipplacement.o: shipplacement.cpp shipplacement.h
	g++ -pedantic-errors -std=c++11 -c shipplacement.cpp

robotplacement.o: map.o shipplacement.o robotplacement.cpp
	g++ -pedantic-errors -std=c++11 -c robotplacement.cpp

test: test.cpp map.cpp playeractions.cpp
	g++ -pedantic-errors -std=c++11 map.cpp test.cpp playeractions.cpp shipplacement.cpp -o test -l ncurses

clean:
	rm -f test map.o shipplacement.o robotplacement.o
