/*
C++ Programming: Zuul Project ("Dream Prison") - Room Class Definitions
by Akhil Baidya

Submission Deadline: 11/28/2023

Details:
The Room class methods are defined here. This includes the get and set methods that output or set the value of the class fields, such as the Room title, description, vector of Items, and map to other Rooms. This also includes the Constructor and Destructor of the class object.
*/

#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include <map>

using namespace std;

//Defining the Constructor:
Room::Room(char theTitle[50], char theDescription[200]) {

  //Create space for the room title and description:
  title = new char[50];
  description = new char[200];

  //Copy the input title and description into this space (want to avoid setting to char* equal to each other, which throws an error):
  strcpy(title, theTitle);
  strcpy(description, theDescription);
} 

//Defining the Destructor (delete all the pointers):
Room::~Room() {
  delete[] title;
  delete[] description;

  for (vector<Item*>::iterator it = items.begin(); it != items.end(); it++) {
    delete (*it); //delete all items
  }
  
}

//Get methods:
char* Room::getTitle(){ //give the title
  return title;
}
char* Room::getDescription() { //give the description
  return description;
}
vector<Item*> Room::getItems() { //give the vector of items
  return items;
}
map<int, Room*> Room::getExits() { //give the map to other rooms
  return exits;
}

//Set methods:
void Room::setTitle(char newTitle[50]){ //set the title
  strcpy(title, newTitle);
}
void Room::setDescription(char newDescription[200]){ //set the description
  strcpy(description, newDescription);
}
void Room::setItems(vector<Item*> newItems){ //set the vector of Items
  items = newItems;
}

void Room::setExits(map<int, Room*> newExits){ //set the map to other Rooms
  exits = newExits;
}


//Other methods:
void Room::addItem(Item* newItem) { //add an item to the vector of Items
  items.push_back(newItem);
}

void Room::remItem(char theItem[50]) { //remove an item from the vector of Items

  int index = 0;
  int pos = 0;
  
  for(vector<Item*>::iterator counter = items.begin(); counter != items.end(); counter++) {//Going through all Items in the room...

    if (!strcmp(theItem, (*counter) -> itemTitle)) { //if an Item has the same name as specified...
  
      pos = index; //save its index
   
     }
    
    index++;
  }

  items.erase(items.begin() + pos); //erase the Item at that index from the vector of Items in the room
  
  /*Note: Referred to GeeksforGeeks for syntax of .erase (name.erase()). Source at https://www.geeksforgeeks.org/vector-in-cpp-stl/*/
}

bool Room::hasItem(char itemTitle[50]) { //check if an item is in the vector of Items in the room
  
  for(vector<Item*>::iterator counter = items.begin(); counter != items.end(); counter++) {//Going through all Items in the room...

    if (!strcmp(itemTitle, (*counter) -> itemTitle)) { //if there is an Item with the same name as specified...
      return true; //the room has the item!
     }
  }
  return false; //else, it does not have the item
}
