//item class:

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Item {

 public:

  Item(char[50] theTitle, char[200] theDescription); //constructor
  ~Item(); //destructor

  //get methods:
  char* getTitle();
  char* getDescription();

  //set methods:
  void setTitle(char[50] newTitle);
  void setDescription(char[200] newDescription);

 protected: //fields unique to an item
  char* title;
  char* description; 

};
