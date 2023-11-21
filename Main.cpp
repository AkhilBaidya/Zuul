//Main class:

#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"

using namespace std;

int main(){

  char title[50] = "Home";
  char description[200] = "Pretty nice here";

  vector<Item*> items;
  Item* Bob = new Item;
  strcpy(Bob -> itemTitle, "Cool orb");
  strcpy(Bob -> itemDes, "Shines brilliantly");
  items.push_back(Bob);

  /*vector<char*> exits;
  char* north = new char[10];
  strcpy(north, "NORTH");
  exits.push_back(north);
  */
  
  Room* bob = new Room(title, description, items);
  cout << bob -> getDescription() << endl;
  return 0;
}
