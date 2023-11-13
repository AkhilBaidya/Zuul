//Room class: has title, description, inventory  

#include <iostream>
#include <cstring>
#include <vector>

using namespace std:

class Room {

 public:

  //constructor:
  Room(char[50] theTitle, char[200] theDescription, vector<struct* item> theItems);

  //deconstructor:
  ~Room();


 protected: //the fields

  char* title;
  char* description;
  vector<struct* item> items;

};
