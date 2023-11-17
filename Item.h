//item class:

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Item {

 public:

  Item(char[50] theTitle, char[200] theDescription); //constructor
  ~Item(); //destructor

 protected: //fields unique to an item
  char* title;
  char* description; 

};
