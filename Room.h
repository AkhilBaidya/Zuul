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

  //get methods:
  char* getTitle();
  char* getDescription();
  vector<struct* item> getItems();

  //set methods:
  void setTitle(char[50] newTitle);
  void setDescription(char[200] newDescription);
  void setItems(vector<struct* item> newItems);
  
 protected: //the fields

  char* title;
  char* description;
  vector<struct* item> items;

};
