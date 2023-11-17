//item class:

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Item {

 public:

  Item(char theTitle[50], char theDescription[200]); //constructor
  ~Item(); //destructor

  //get methods:
  char* getTitle();
  char* getDescription();

  //set methods:
  void setTitle(char newTitle[50]);
  void setDescription(char newDescription[200]);

 protected: //fields unique to an item
  char* title;
  char* description; 
};
