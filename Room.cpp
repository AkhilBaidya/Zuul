//Room class: has title, description, inventory  

#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"

using namespace std;

Room::Room(char theTitle[50], char theDescription[200], vector<Item*> theItems, vector<char*> theExits) {
  strcpy(title, theTitle);
  strcpy(description, theDescription); //want to copy so I don't set two char* equal to each other (gave me errors in Classes project)
  items = theItems;
  exits = theExits;
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
vector<char*> Room::getExits() {
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
void Room::setExits(vector<char*> newExits){
  exits = newExits;
}
 
