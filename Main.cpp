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

  //Room 11:
  char title11[50] = "Hallway 1 [Tampered Photos]";
  char des11[200] = "Photos cover either side of the hallway. Their faces are unrecognizable, burned away";
  Room* hall1 = new Room(title11, des11);

  //Room 12:
  char title12[50] = "Hallway 2";
  char des12[200] = "Vases and intricate pottery sit on the ceiling and ignore gravity. Wait...what was gravity again?";
  Room* hall2 = new Room(title12, des12);

  //Room 13:
  char title13[50] = "Hallway 3 [Tampered Mirrors]";
  char des13[200] = "Mirrors decorate every angle of this hall section. Alas, they all seem to reflect nothing.";
  Room* hall3 = new Room(title13, des13);

  //Room 14:
  char title14[50] = "Warden's Room";
  char des14[200] = "Your chest tightens and your breath comes out in small puffs. A desk full of paperwork sits in the middle of the room.";
  Room* warden = new Room(title14, des14);

  //Room 15:
  char title15[50] = "Room of Song";
  char des15[200] = "There's something soothing about this room. A gentle lullaby washes over you as you sink deeper into the serene blue of the room walls";
  Room* song = new Room(title15, des15);
}

void roomDescription(Room* &currentRoom) {
}
