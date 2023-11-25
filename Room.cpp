//Room class: has title, description, items and map of exits  

#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include <map>

using namespace std;

Room::Room(char theTitle[50], char theDescription[200]) {
  title = new char[50];
  description = new char[200];
  
  strcpy(title, theTitle);
  strcpy(description, theDescription); //want to copy so I don't set two char* equal to each other (gave me errors in Classes project) 
} //constructor

Room::~Room() {
  delete[] title;
  delete[] description; //delete all the pointers
  
} //destructor

//get methods:
char* Room::getTitle(){
  return title;
}
char* Room::getDescription() {
  return description;
}
vector<Item*> Room::getItems() {
  return items;
}
map<char*, Room*> Room::getExits() {
  return exits;
}

//set methods:
void Room::setTitle(char newTitle[50]){
  strcpy(title, newTitle); //remember to use strcpy! not = (that caused me errors in Classes, with char* = char*)
}
void Room::setDescription(char newDescription[200]){
  strcpy(description, newDescription);
}
void Room::setItems(vector<Item*> newItems){
  items = newItems; //?
}

void Room::addItem(Item* newItem) {
  items.push_back(newItem);
}

Item* Room::remItem(Item* theItem) {

  int index = 0;
  
  for(vector<Item*>::iterator counter = items.begin(); counter != items.end(); counter++) {
    
    if (theItem == (*counter)) {
      items.erase(items.begin() + index);
    }
    index++;
  }
  return theItem;
  //referred to this for syntax of .erase - https://www.geeksforgeeks.org/vector-in-cpp-stl/
}

void Room::setExits(map<char*, Room*> newExits){
  exits = newExits;
}
 
