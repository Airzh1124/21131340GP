map.o: map.cpp map.h
	g++ -pedantic-errors -std=c++11 -c map.cpp

shipplacement.o: shipplacement.cpp shipplacement.h
	g++ -pedantic-errors -std=c++11 -c shipplacement.cpp

robotplacement.o: map.o shipplacement.o robotplacement.cpp
	g++ -pedantic-errors -std=c++11 -c robotplacement.cpp

test: test.cpp map.cpp playeractions.cpp shipplacement.cpp robotactions.cpp
	g++ -pedantic-errors -std=c++11 map.cpp test.cpp playeractions.cpp robotactions.cpp shipplacement.cpp -o test -l ncurses

robot: map.cpp playeractions.cpp shipplacement.cpp robotactions.cpp robottest.cpp
	g++ -pedantic-errors -std=c++11 map.cpp playeractions.cpp shipplacement.cpp robotactions.cpp robottest.cpp -o robot -l ncurses

exrobot: map.cpp playeractions.cpp shipplacement.cpp robotactions.cpp expertMode.cpp experttest.cpp
	g++ -pedantic-errors -std=c++11 map.cpp playeractions.cpp shipplacement.cpp robotactions.cpp expertMode.cpp experttest.cpp -o exrobot -l ncurses

clean:
	rm -f test map.o shipplacement.o robotplacement.o robot exrobot test
