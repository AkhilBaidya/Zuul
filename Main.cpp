//Main class:

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"

using namespace std;

void createWorld(vector<Room*> world);
void roomDescription(Room* &currentRoom);

int main(){

  vector<Room*> world;
  vector<Item*> inventory;
  createWorld(world);
  
  /*
  char title[50] = "Home";
  char description[200] = "Pretty nice here";

  vector<Item*> items;
  Item* Bob = new Item;
  strcpy(Bob -> itemTitle, "Cool orb");
  strcpy(Bob -> itemDes, "Shines brilliantly");
  items.push_back(Bob);

  /*vector<char*> exits;
  char* north = new char[10];
  strcpy(north, "NORTH");
  exits.push_back(north);
  
  Room* bob = new Room(title, description, items);
  cout << bob -> getDescription() << endl;
  return 0; */
}

//this will create all the rooms
void createWorld(vector<Room*> &world) {

  //Room 1:
  char title1[50] = "Broken Cell [Home]";
  char des1[200] = "You are greeted with a familiar earthy scent. The bars of the cell are bent like fingers. They seem to point to the WEST."; 
  Room* cell = new Room(title1, des1);
  
  //Room 2:
  char title2[50] = "Oldest Room";
  char des2[200] = "Your eyes are blinded by white light. It's pretty empty here. Fog rolls over the walls like hair";
  Room* oldest = new Room(title2, des2);

  //Room 3:
  char title3[50] = "Winter";
  char des3[200] = "You shiver as you enter the room. A blanket of snow from nowhere falls at your feet";
  Room* winter = new Room(title3, des3);

  //Room 4:
  char title4[50] = "Spring";
  char des4[200] = "Tiny flowers sprout from cracks in the walls.";
  Room* spring = new Room(title4, des4);

  //Room 5:
  char title5[50] = "Summer";
  char des5[200] = "Your heart beats faster and louder. At the center of the room is a throne.";
  Room* summer = new Room(title5, des5);

  //Room 6:
  char title6[50] = "Fall";
  char des6[200] = "Invisible things crunch beneath your feet. At the center of the room, you feel almost judged by the walls";
  Room* fall = new Room(title6, des6);

  //Room 7:
  char title7[50] = "Room of Books";
  char des7[200] = "Tiny tables are scattered all over the room. Paper lies suspended in the air";
  Room* books = new Room(title7, des7);

  //Room 8:
  char title8[50] = "Room of Birth";
  char des8[200] = "'The wooden cradle to your left swings unattended and unoccupied. Creaks resound through the room";
  Room* birth = new Room(title8,des8);

  //Room 9:
  char title9[50] = "Room of Injury";
  char des9[200] = "Ouch! The floor surface is jagged and hungry, here. The walls curve inwards. It feels like  you are in a cave";
  Room* injury = new Room(title9, des9);

  //Room 10:
  char title10[50] = "Room of Art";
  char des10[200] = "Stains of red, blue, and green dance on a single canvas at the center of the room."; 
  Room* room10 = new Room(title10, des10);

  Room* room11 = new Room("title", "description");
  Room* room12 = new Room("title", "description");
  Room* room13 = new Room("title", "description");
  Room* room14 = new Room("title", "description");
  Room* room15 = new Room("title", "description");
}

void roomDescription(Room* &currentRoom) {
}
