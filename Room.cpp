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
}
char* Room::getDescription();{
}
vector<struct* item> Room::getItems(); {
}

//set methods:
void Room::setTitle(char[50] newTitle){
}
void Room::setDescription(char[200] newDescription){
}
void Room::setItems(vector<struct* item> newItems){
}
 
