//Room class: has title, description, items and map of exits  

#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include <map>

using namespace std;

Room::Room(char theTitle[50], char theDescription[200], vector<Item*> theItems) {
  title = new char[50];
  description = new char[200];
  strcpy(title, theTitle);
  strcpy(description, theDescription); //want to copy so I don't set two char* equal to each other (gave me errors in Classes project)
  items = theItems; 
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
map<char*, Room> Room::getExits() {
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
void Room::setExits(map<char*, Room> newExits){
  exits = newExits;
}
 
