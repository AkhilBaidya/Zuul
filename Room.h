/*
C++ Programming: Zuul Project ("Dream Prison") - Room Class Header
by Akhil Baidya

Submission Deadline: 11/28/2023

Details: 
The Room class fields and methods are stated here. A Room class object will have a title, description, a vector of Items that it can possess (Item will be defined as a struct in this file), and a map that connects to other Room objects (representing exits in the room).  
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

//Defining what an "Item" is:
struct Item {

  //an Item has a title and a description:
  char itemTitle[50];
  char itemDes[200];

  /*Note: received advice from Kevin in recognizing that including a struct definition in this header will
also define the struct in all other files (such as Room.cpp) that include this header - I do not need to redefine
the struct*/
};

//Stating Aspects of the Room Class:
class Room {

public:

  //The Constructor:
  Room(char theTitle[50], char theDescription[200]); //constructs a Room object based on a title and description (cannot immediately define fields such as the map to other Rooms, since that would require the other Rooms to be instantiated already)

  //The Destructor:
  ~Room();

  //Get methods:
  char* getTitle(); //outputs the room title
  char* getDescription(); //outputs the room description
  vector<Item*> getItems(); //outputs the vector of items in the room
  map<int, Room*> getExits(); //outputs the map to other rooms

  //Set methods:
  void setTitle(char newTitle[50]); //sets the room title
  void setDescription(char newDescription[200]); //sets the room description
  void setItems(vector<Item*> newItems); //sets the vector of Items in the room
  void setExits(map<int, Room*> newExits); //sets the map to other rooms

  //Other methods:
  void addItem(Item* newItem); //adds an input Item to the vector of Items in the room
  void remItem(char theItem[50]); //removes an Item with the specified name from the vector in the room
  bool hasItem(char itemTitle[50]); //checks if an Item with the specified name is in the vector in the room (returns true if yes)

 protected:
  //The Fields:

  char* title;
  char* description;
  vector<Item*> items;
  map<int, Room*> exits;

  /*Notes: Referred to GeeksforGeeks.org for the syntax or instantiating a map object (map<type, type> name). Source is at https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/ 

Additionally, received help from Mr. Galbraith for the idea of incorporating a map to Room* in my code with the key in map corresponding to a specific direction - thus one can exit to another Room using a direction, accessing the value in the map based on the key
*/

};
