#include "map.h"
#include "shipplacement.h"
#include <iostream>
using namespace std;

//to test whether the ship overlap and then place the ship 
//just a draft version, not yet finished and will make changes soon
//g++ setuptest.cpp shipplacement.cpp map.cpp -o test


int main(){
    int x, y, value, placementcout = 0, Shiplen, Shipwei, Shiprow, Shipcol;
    cin >> x >> y;
    Map m1(x, y);
    while (placementcout < 4){
        m1.printPMap();
        //we could create a list that stores the available choice of ship, and the list changes everytime after the user place a ship
        //like-> "{2*2, 2*3} here are the available shape of ship you can choose from, they can be placed in reversed order...etc."
        cout << "Please input the length and weight of the ship you want to place (e.g. 2 3 (length weight))." << endl;
        cin >> Shiplen >> Shipwei;
        cout << "Please enter the coordinates of the top-left position where you want to place the ship (e.g. 2 2 (row column))." << endl;
        cin >> Shiprow >> Shipcol;
        if (overlap(m1, Shiprow, Shipcol, Shiplen, Shipwei) == false){
            placeShip(m1, Shiprow, Shipcol, Shiplen, Shipwei, 1); //value 1 here may adjust to the no.of placement(ship) later, but should be differentiate from 2 and 0, need further consideration
            placementcout++;
        }
        //for else part, maybe print out the overlapped cells?
        else{
            cout << '\n' << "Sorry you cannot place here, please try in another cell." << '\n' << endl;
        }

    }
    cout << "Here is your final version of map: " << endl;
    m1.printPMap();

return 0;
}