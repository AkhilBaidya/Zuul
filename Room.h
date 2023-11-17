//Room class: has title, description, inventory  

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Room {

  //advice from Kevin in recognizing that including a struct defintion in this header will also
  //define the struct in all files that include this header

  struct Item {

    char itemTitle[50];
    char itemDes[200];
    
  };

public:

  //constructor:
  Room(char theTitle[50], char theDescription[200], vector<> theItems);

  //deconstructor:
  ~Room();

  //get methods:
  char* getTitle();
  char* getDescription();
  vector<struct* item> getItems();

  //set methods:
  void setTitle(char newTitle[50]);
  void setDescription(char newDescription[200]);
  void setItems(vector<struct* item> newItems);
  
 protected: //the fields

  char* title;
  char* description;
  vector<struct* item> items;

};
