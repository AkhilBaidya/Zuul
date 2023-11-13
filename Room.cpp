//Room class: has title, description, inventory  

#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"

using namespace std:

Room::Room(char[50] theTitle, char[200] theDescription, vector<struct* item> theItems) {
  strcpy(title, theTitle);
  strcpy(description, theDescription); //want to copy so I don't set two char* equal to each other (gave me errors in Classes project)
  items = theItems;
} //constructor

Room::~Room() {
  delete[] title;
  delete[] description; //delete all the pointers
  delete theItems;//not too sure about this structure

} //destructor

//get methods:
char* Room::getTitle(){
  return title;
}
char* Room::getDescription();{
  return description;
}
vector<struct* item> Room::getItems(); {
  return items;
}

//set methods:
void Room::setTitle(char[50] newTitle){
  strcpy(title, newTitle); //remember to use strcpy! not = (that caused me errors in Classes, with char* = char*)
}
void Room::setDescription(char[200] newDescription){
  strcpy(description, newDescription);
}
void Room::setItems(vector<struct* item> newItems){
  items = newItems; //?
}
 
