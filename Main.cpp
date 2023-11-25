//Main class:

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"

using namespace std;

void createWorld(vector<Room*> &world);
void roomDescription(Room* &currentRoom);
void takeItem(Room* &currentRoom, vector<Item*> &inventory, char itemTitle[50]);
void placeItem(Room* &currentRoom, vector<Item*> &inventory, char itemTitle[50]);
void goTo(Room* &currentRoom, char direction[10]);

int main(){
  vector<Room*> world;
  vector<Item*> inventory;
  Room* currentRoom;
  cout << "1" << endl;
  createWorld(world);

  cout << "2" << endl;
  //starting area: learned that referencing value in vector is same as erray:
  //https://www.geeksforgeeks.org/vector-in-cpp-stl/
  currentRoom = world[0];
  cout << "3" << endl;
  roomDescription(currentRoom);
  cout << "4" << endl;
  return 0;
}

//this will create all the rooms
void createWorld(vector<Room*> &world) {

  //Room 1:
  char title1[50] = "Broken Cell [Home]";
  char des1[200] = "You are greeted with a familiar earthy scent. The bars of the cell are bent like fingers. They seem to point to the WEST."; 
  Room* cell = new Room(title1, des1);
  world.push_back(cell);
  
  //Room 2:
  char title2[50] = "Oldest Room";
  char des2[200] = "Your eyes are blinded by white light. It's pretty empty here. Fog rolls over the walls like hair";
  Room* oldest = new Room(title2, des2);
  world.push_back(oldest);
  
  //Room 3:
  char title3[50] = "Winter";
  char des3[200] = "You shiver as you enter the room. A blanket of snow from nowhere falls at your feet";
  Room* winter = new Room(title3, des3);
  world.push_back(winter);
  
  //Room 4:
  char title4[50] = "Spring";
  char des4[200] = "Tiny flowers sprout from cracks in the walls.";
  Room* spring = new Room(title4, des4);
  world.push_back(spring);
  
  //Room 5:
  char title5[50] = "Summer";
  char des5[200] = "Your heart beats faster and louder. At the center of the room is a throne.";
  Room* summer = new Room(title5, des5);
  world.push_back(summer);
  
  //Room 6:
  char title6[50] = "Fall";
  char des6[200] = "Invisible things crunch beneath your feet. At the center of the room, you feel almost judged by the walls";
  Room* fall = new Room(title6, des6);
  world.push_back(fall);
  
  //Room 7:
  char title7[50] = "Room of Books";
  char des7[200] = "Tiny tables are scattered all over the room. Paper lies suspended in the air";
  Room* books = new Room(title7, des7);
  world.push_back(books);

  
  //Room 8:
  char title8[50] = "Room of Birth";
  char des8[200] = "'The wooden cradle to your left swings unattended and unoccupied. Creaks resound through the room";
  Room* birth = new Room(title8,des8);
  world.push_back(birth);
  
  //Room 9:
  char title9[50] = "Room of Injury";
  char des9[200] = "Ouch! The floor surface is jagged and hungry, here. The walls curve inwards. It feels like  you are in a cave";
  Room* injury = new Room(title9, des9);
  world.push_back(injury);

  //Room 10:
  char title10[50] = "Room of Art";
  char des10[200] = "Stains of red, blue, and green dance on a single canvas at the center of the room."; 
  Room* art = new Room(title10, des10);
  world.push_back(art);
  
  //Room 11:
  char title11[50] = "Hallway 1 [Tampered Photos]";
  char des11[200] = "Photos cover either side of the hallway. Their faces are unrecognizable, burned away";
  Room* hall1 = new Room(title11, des11);
  world.push_back(hall1);
  
  //Room 12:
  char title12[50] = "Hallway 2";
  char des12[200] = "Vases and intricate pottery sit on the ceiling and ignore gravity. Wait...what was gravity again?";
  Room* hall2 = new Room(title12, des12);
  world.push_back(hall2);
  
  //Room 13:
  char title13[50] = "Hallway 3 [Tampered Mirrors]";
  char des13[200] = "Mirrors decorate every angle of this hall section. Alas, they all seem to reflect nothing.";
  Room* hall3 = new Room(title13, des13);
  world.push_back(hall3);
  
  //Room 14:
  char title14[50] = "Warden's Room";
  char des14[200] = "Your chest tightens and your breath comes out in small puffs. A desk full of paperwork sits in the middle of the room.";
  Room* warden = new Room(title14, des14);
  world.push_back(warden);
  
  //Room 15:
  char title15[50] = "Room of Song";
  char des15[200] = "There's something soothing about this room. A gentle lullaby washes over you as you sink deeper into the serene blue of the room walls";
  Room* song = new Room(title15, des15);
  world.push_back(song);

  //the 5 items:

  //name:
  Item* name = new Item;
  char n1[50] = "A Name";
  char itemDes1[200] = "______. Remember a name that once belonged to you";
  strcpy(name->itemTitle, n1);
  strcpy(name->itemDes,itemDes1);

  //knowledge:
  Item* knowledge = new Item;
  char n2[50] = "Knowledge";
  char itemDes2[200] = "1+1 = 2. Remember eyes to see the world with.";
  strcpy(knowledge -> itemTitle, n2);
  strcpy(knowledge -> itemDes, itemDes2);

  //true mirror:
  Item* mirror = new Item;
  char n3[50] = "A True Mirror?";
  char itemDes3[200] = "Unblemished and revealing. You see your eyes staring back. Remember your appearance.";
  strcpy(mirror -> itemTitle, n3);
  strcpy(mirror -> itemDes, itemDes3);

  //a crown:
  Item* crown = new Item;
  char n4[50] = "A Crown";
  char itemDes4[200] = "Remember your accomplishments";
  strcpy(crown -> itemTitle, n4);
  strcpy(crown -> itemDes, itemDes4);

  //rotten apple:
  Item* apple = new Item;
  char n5[50] = "Rotten Apple";
  char itemDes5[200] = "Get rid of it. Get rid of it. Get rid of it. Get rid of it.";
  strcpy(apple -> itemTitle, n5);
  strcpy(apple -> itemDes, itemDes5);

  //Adding room connections: referred to this for syntax of adding to map - https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
  char d1[10] = "NORTH";
  char d2[10] = "EAST";
  char d3[10] = "SOUTH";
  char d4[10] = "WEST";
  
  //Room 1:cell
  map<char*, Room*> e1;
  e1[d4] = oldest;
  e1[d2] = hall1;
  e1[d1] = fall;
  e1[d3] = spring;
  cell -> setExits(e1);
  
  //Room 2:oldest
  map<char*, Room*> e2;
  e2[d4] = cell;
  oldest -> setExits(e2);
  
  //Room 3: winter
  map<char*, Room*> e3;
  e3[d3] = fall;
  winter -> setExits(e3);
  
  winter -> addItem(apple);
		     
  //Room 4: spring
  map<char*, Room*> e4;
  e4[d1] = cell;
  e4[d3] = summer;
  spring -> setExits(e4);
  
  //Room 5:summer
  map<char*, Room*> e5;
  e5[d1] = spring;
  summer -> setExits(e5);
  summer -> addItem(crown);
  
  //Room 6:fall
  map<char*, Room*> e6;
  e6[d1] = winter;
  e6[d3] = cell;
  fall -> setExits(e6);
  
  //Room 7:books
  map<char*, Room*> e7;
  e7[d1] = hall2;
  e7[d2] = injury;
  books -> setExits(e7);
  books -> addItem(knowledge);
  
  //Room 8:birth
  map<char*, Room*> e8;
  e8[d1] = injury;
  birth -> setExits(e8);
  birth -> addItem(name);
  
  //Room 9:injury
  map<char*, Room*> e9;
  e9[d1] = hall3;
  e9[d3] = birth;
  e9[d4] = books;
  injury -> setExits(e9);
  
  //Room 10:art
  map<char*, Room*> e10;
  e10[d2] = song;
  e10[d3] = hall2;
  art -> setExits(e10);
  
  //Room 11:hall1
  map<char*, Room*> e11;
  e11[d2] = hall2;
  e11[d4] = cell;
  hall1 -> setExits(e11);
  
  //Room 12:hall2
  map<char*, Room*> e12;
  e12[d1] = art;
  e12[d2] = hall3;
  e12[d3] = books;
  e12[d4] = hall1;
  hall2 -> setExits(e12);
  
  //Room 13:hall3
  map<char*, Room*> e13;
  e13[d1] = song;
  e13[d2] = warden;
  e13[d3] = injury;
  e13[d4] = hall2;
  hall3 -> setExits(e13);
  
  //Room 14: warden
  map<char*, Room*> e14;
  e14[d4] = hall3;
  warden -> setExits(e14);
  warden -> addItem(mirror);
  
  //Room 15:song
  map<char*, Room*> e15;
  e15[d3] = hall3;
  e15[d4] = art;
  song -> setExits(e15);
  return;
}

void roomDescription(Room* &currentRoom) {
  //title:
  cout << "Welcome to " << currentRoom -> getTitle() << endl;

  //description:
  cout << currentRoom -> getDescription() << endl;

  //items:
  cout << "In the room, there are items: " << endl;
  vector<Item*> curItems = currentRoom -> getItems();
  for (vector<Item*>::iterator item = curItems.begin(); item != curItems.end(); item++) {
    cout << (*item) << ", ";
  }

  cout << " " << endl;
  
  //exits: referred to this https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/ for how to iterate through a map and get key values
  
  cout << "There are exits:" << endl;

  map<char*, Room*> curMap = currentRoom -> getExits();

  for (map<char*, Room*>::iterator pair = curMap.begin(); pair != curMap.end(); pair++) {
    cout << pair -> first << ", ";
  }
  cout << " " << endl; 
}

void takeItem(Room* &currentRoom, vector<Item*> &inventory, char itemName[50]){
  vector<Item*> roomItems = currentRoom -> getItems();
  Item* theItem = new Item;
  int thereis = 0;
  
  for (vector<Item*>::iterator item = roomItems.begin(); item != roomItems.end(); item++) {
    if (!strcmp((*item) -> itemTitle, itemName)) {
      theItem = (*item);
      thereis = 1;
    }
  }

  if (thereis == 0) {
    cout << "That item is not in the room" << endl;
    return
  }
  else {
    currentRoom -> remItem(theItem);
    inventory.push_back(theItem);
  }
  return;
}
void placeItem(Room* &currentRoom, vector<Item*> &inventory, char itemTitle[50]){

}
void goTo(Room* &currentRoom, char direction[10]){

}
