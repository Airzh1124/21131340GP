main: map.cpp playeractions.cpp shipplacement.cpp robotactions.cpp masterMode.cpp Starting_screen.cpp modes.cpp main.cpp
	g++ -pedantic-errors -std=c++11 map.cpp playeractions.cpp shipplacement.cpp robotactions.cpp Starting_screen.cpp modes.cpp masterMode.cpp main.cpp -o main -l ncurses

test: map.cpp playeractions.cpp shipplacement.cpp robotactions.cpp masterMode.cpp Starting_screen.cpp modes.cpp test.cpp
	g++ -pedantic-errors -std=c++11 map.cpp playeractions.cpp shipplacement.cpp robotactions.cpp Starting_screen.cpp modes.cpp masterMode.cpp test.cpp -o test -l ncurses

clean:
	rm -f main
