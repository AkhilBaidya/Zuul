//Room class: has title, description, inventory  

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


  struct Item {

    char itemTitle[50];
    char itemDes[200];
    
  };

class Room {

  //advice from Kevin in recognizing that including a struct defintion in this header will also
  //define the struct in all files that include this header

public:

  //constructor:
  Room(char theTitle[50], char theDescription[200], vector<Item*> theItems, vector<char*> theExits);

  //deconstructor:
  ~Room();

  //get methods:
  char* getTitle();
  char* getDescription();
  vector<Item*> getItems();
  vector<char*> getExits();

  //set methods:
  void setTitle(char newTitle[50]);
  void setDescription(char newDescription[200]);
  void setItems(vector<Item*> newItems);
  void setExits(vector<char*> newExits);
  
 protected: //the fields

  char* title;
  char* description;
  vector<Item*> items;
  vector<char*> exits;

};
