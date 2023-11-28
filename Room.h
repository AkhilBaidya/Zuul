//Room class: has title, description, items, and map of exits   

#include <iostream>
#include <cstring>
#include <vector>
#include <map>


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
  Room(char theTitle[50], char theDescription[200]); //cannot construct room with map of other rooms immediately (setting items will also not be done in construction of object)

  //deconstructor:
  ~Room();

  //get methods:
  char* getTitle();
  char* getDescription();
  vector<Item*> getItems();
  map<int, Room*> getExits(); //help from Mr. Galbraith for idea of making two inputs into the map a char (the direction) and another Room

  //set methods:
  void setTitle(char newTitle[50]);
  void setDescription(char newDescription[200]);
  void setItems(vector<Item*> newItems);
  void addItem(Item* newItem);
  void remItem(char theItem[50]);
  void setExits(map<int, Room*> newExits);
  
 protected: //the fields

  char* title;
  char* description;
  vector<Item*> items;
  map<int, Room*> exits; //https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/ (used this source for syntax for instantiating a map object, from GeeksforGeeks.org

};
