#include "map.h"
#include "shipplacement.h"
#include <iostream>
#include <list>

using namespace std;

int main(){
    int x, y, value, placementcout = 0, Shiplen, Shipwei, Shiprow, Shipcol;
    cout << "Please enter the size of the map (row column)." << endl;
    cin >> x >> y;
    Map m1(x, y);
    while (Shipshape.empty() == false){
        m1.printPMap();
        getAndplaceShape(m1);
    }
    cout << "Here is your final version of map: " << endl;
    m1.printPMap();

return 0;
}