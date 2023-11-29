/*Main class:
C++ Programming: Zuul Project ("Dream Prison") - Main Class
by Akhil Baidya

Submission Deadline: 11/28/2023

Details: This is where the actual Zuul game runs. The main function creates and updates the interface (series of prompts) the user
interacts with during the game.

Instructions for Gameplay:

1. The user has a couple of commands they can use. They can type 'take' or 'place' and then will be prompted to name an item name.
The user will then take that item from the room they are currently in or place that item from their inventory into that room, if possible.

ex. take

    take what? (computer prompts user)
    
    Apple

2. The user can also type 'inventory' to see their inventory.

3. The user can also type 'go' to move to another room. After this, they will be prompted to specify where they want to go. They must
respond with 'NORTH', 'EAST', 'SOUTH', or 'WEST' (and then will move in the direction they specify).

ex. go

    go where? (computer prompts user)

    WEST
    
4. Finally, the user can quit the game by typing in 'quit'
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"

using namespace std;

//FUNCTION PROTOTYPES (their uses will be specified right behind the function definition):
void createWorld(vector<Room*> &world);
void roomDescription(Room* &currentRoom);
void takeItem(Room* &currentRoom, vector<Item*> &inventory, char itemName[50]);
void placeItem(Room* &currentRoom, vector<Item*> &inventory, char itemName[50]);
void goTo(Room* &currentRoom, char direction[10]);
void end(bool &commanding, bool &playing, int type);

//MAIN FUNCTION (this function forms the main gameplay, prompting the user for their commands):
int main(){

  //Variables:
  vector<Room*> world;
  vector<Item*> inventory;
  bool playing = true;
  bool commanding = true;
  bool ending = false;

  //Create all 15 rooms at the beginning of the game:
  createWorld(world);

  //The current room starts at the "cell" or the 1st room in the world vector: 
  Room* currentRoom = world[0];

  /*Note: Learned that referencing a value in a vector (with name[index]) is the same as for an array from GeeksforGeeks.org.
    Source at https://www.geeksforgeeks.org/vector-in-cpp-stl/ */

  //The main game loop: 
  while (playing) {

    //Print out the descriptions of the room the player is currently in:
    roomDescription(currentRoom);

    //Start the loop of prompting the user for commands (actions):
    commanding = true;
    while (commanding) {

      //Check for BAD ENDING:

      //Here are the rooms and their inventories that are important to the ending (whether they have certain items will trigger a certain ending):
      Room* cell = world[0];
      vector<Item*> cellItems = cell -> getItems();
      Room* oldest = world[1];
      vector<Item*> oldItems = oldest -> getItems();

      //Here are all the names of the Items in the game:
      char n1[50] = "Name[Mine?]";
      char n2[50] = "Knowledge";
      char n3[50] = "Mirror[True?]";
      char n4[50] = "Crown";
      char n5[50] = "Apple[Rotting]";

      //If all of the Items in the game are in the "oldest" room:
      if (oldest -> hasItem(n1) && oldest -> hasItem(n2) && oldest -> hasItem(n3) && oldest -> hasItem(n4) && oldest -> hasItem(n5))
	
	end(commanding, playing, 1); //commence the BAD ENDING
        ending = true; //prevents the game from asking the player for another command 
      }

      //Check for TRUE ENDING:

      //If all of the Items except the apple are in the "oldest" room and the apple is in the "cell":
      if (oldest -> hasItem(n1) && oldest -> hasItem(n2) && oldest -> hasItem(n3) && oldest -> hasItem(n4) && cell -> hasItem(n5)) {

	end(commanding, playing, 2); //commence the TRUE ENDING
	ending = true;
      }

      if (!ending) { //if an ending has not been triggered...

	//Prompt user for command (action):
	cout << "What would you like to do? (take, place, inventory, go, quit)" << endl;
	char command[20];
	cin >> command;

	
      //Print Inventory Command:
      if (!strcmp("inventory", command)) { //if user inputs 'inventory'...

	for (vector<Item*>::iterator item = inventory.begin(); item != inventory.end(); item++) {//for each item in their inventory...
	  cout << (*item) -> itemTitle << ", "; //print its name
	}

	cout << " " << endl;
      }

      //Take Item Command:
      if (!strcmp("take", command)) { //if user inputs 'take'

	//Ask the user to specify the name of the item they want to take:
	char whatItem[20];
	cout << "Take what?" << endl;
	cin >> whatItem;

	takeItem(currentRoom, inventory, whatItem); //run the takeItem function
      }

      //Place Item Command:
      if (!strcmp("place", command)) { //if user inputs 'place'

	//Ask user to specify the name of the item they want to place from their inventory:
	char whatItem[20];
	cout << "Place what?" << endl;
	cin >> whatItem;

	placeItem(currentRoom, inventory, whatItem); //run the placeItem function
      }

      //Go to Room Command:
      if (!strcmp("go", command)) { //if the user inputs 'go'

	//Ask user to specify the direction they want to travel:
	char whatDir[20];
	cout << "go where? (NORTH, EAST, SOUTH, WEST)" << endl;
	cin >> whatDir;

	goTo(currentRoom, whatDir); //run the goTo function
	commanding = false; //stop prompting the user for commands in the current room (as the current room will change)
      }

      //Quit Command:
      if (!strcmp("quit", command)) { //if the user inputs 'quit'

	cout << "quitting" << endl;
       
	commanding = false; //stop prompting the user for commands in the current room
	playing = false; //stop the main game loop
      }
     }
    }
  }

  //Delete all the Room pointers in the world vector at the end of the game: 
  for (vector<Room*>::iterator it = world.begin(); it != world.end(); it++){
    delete (*it);
  }

  cout << "Thanks for playing!" << endl;
  return 0;
}


//OTHER FUNCTIONS:

/*This function creates all the Rooms and Items in the game. It then adds these Items to certain Rooms and also creates
exits in each Room (sets their maps to point to other Rooms). Finally, this function adds all the Rooms to some inputted vector.
 */
void createWorld(vector<Room*> &world) {

  //Creating the 15 Rooms:
  
  //Room 1:
  char title1[50] = "Broken Cell [Home]";
  char des1[200] = "You are greeted with a familiar earthy scent. The bars of the cell are bent like fingers. They seem to point to the WEST."; 
  Room* cell = new Room(title1, des1); //create the room out of the previous title and description
  world.push_back(cell); //add the room to the world vector (which will contain all of the rooms)
  
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

  
  //Create the 5 Items:

  //The Name Item:
  Item* name = new Item;
  char n1[50] = "Name[Mine?]";
  char itemDes1[200] = "______. Remember a name that once belonged to you";
  strcpy(name->itemTitle, n1);
  strcpy(name->itemDes,itemDes1); //set the title and description of the Item to the previously described char arrays

  //The Knowledge Item:
  Item* knowledge = new Item;
  char n2[50] = "Knowledge";
  char itemDes2[200] = "1+1 = 2. Remember eyes to see the world with.";
  strcpy(knowledge -> itemTitle, n2);
  strcpy(knowledge -> itemDes, itemDes2);

  //The Mirror Item:
  Item* mirror = new Item;
  char n3[50] = "Mirror[True?]";
  char itemDes3[200] = "Unblemished and revealing. You see your eyes staring back. Remember your appearance.";
  strcpy(mirror -> itemTitle, n3);
  strcpy(mirror -> itemDes, itemDes3);

  //The Crown Item:
  Item* crown = new Item;
  char n4[50] = "Crown";
  char itemDes4[200] = "Remember your accomplishments";
  strcpy(crown -> itemTitle, n4);
  strcpy(crown -> itemDes, itemDes4);

  //The Rotten Apple Item:
  Item* apple = new Item;
  char n5[50] = "Apple[Rotting]";
  char itemDes5[200] = "Get rid of it. Get rid of it. Get rid of it. Get rid of it.";
  strcpy(apple -> itemTitle, n5);
  strcpy(apple -> itemDes, itemDes5);

  //Adding Room Connections:

  /*Note: Referred to GeeksforGeeks.org for the syntax of adding objects to map (with name[key] = value)
    Source at https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/*/

  /*Note 2: Integer of 1, 2, 3, 4 represents NORTH, EAST, SOUTH, WEST respectively*/
  
  //Room 1: Cell
  map<int, Room*> e1;
  e1[4] = oldest;
  e1[2] = hall1;
  e1[1] = fall;
  e1[3] = spring;
  cell -> setExits(e1); //create a new map of directions (as integers) to Room pointers and add it inside of this Room

  //Room 2: Oldest
  map<int, Room*> e2;
  e2[2] = cell;
  oldest -> setExits(e2);

  //Room 3: Winter
  map<int, Room*> e3;
  e3[3] = fall;
  winter -> setExits(e3);
  winter -> addItem(apple);
  		     
  //Room 4: Spring
  map<int, Room*> e4;
  e4[1] = cell;
  e4[3] = summer;
  spring -> setExits(e4);
  
  //Room 5: Summer
  map<int, Room*> e5;
  e5[1] = spring;
  summer -> setExits(e5);
  summer -> addItem(crown);

  //Room 6: Fall
  map<int, Room*> e6;
  e6[1] = winter;
  e6[3] = cell;
  fall -> setExits(e6);
  
  //Room 7: Books
  map<int, Room*> e7;
  e7[1] = hall2;
  e7[2] = injury;
  books -> setExits(e7);
  books -> addItem(knowledge);

  //Room 8: Birth
  map<int, Room*> e8;
  e8[1] = injury;
  birth -> setExits(e8);
  birth -> addItem(name);

  //Room 9: Injury
  map<int, Room*> e9;
  e9[1] = hall3;
  e9[3] = birth;
  e9[4] = books;
  injury -> setExits(e9);

  //Room 10: Art
  map<int, Room*> e10;
  e10[2] = song;
  e10[3] = hall2;
  art -> setExits(e10);
  
  //Room 11: Hall1
  map<int, Room*> e11;
  e11[2] = hall2;
  e11[4] = cell;
  hall1 -> setExits(e11);

  //Room 12: Hall2
  map<int, Room*> e12;
  e12[1] = art;
  e12[2] = hall3;
  e12[3] = books;
  e12[4] = hall1;
  hall2 -> setExits(e12);

  //Room 13: Hall3
  map<int, Room*> e13;
  e13[1] = song;
  e13[2] = warden;
  e13[3] = injury;
  e13[4] = hall2;
  hall3 -> setExits(e13);

  //Room 14: Warden
  map<int, Room*> e14;
  e14[4] = hall3;
  warden -> setExits(e14);
  warden -> addItem(mirror);

  //Room 15: Song
  map<int, Room*> e15;
  e15[3] = hall3;
  e15[4] = art;
  song -> setExits(e15);

  return;
}


//This function prints out the title, description, items, and exits of a room:
void roomDescription(Room* &currentRoom) {
  
  //Print the Room title:
  cout << "Welcome to " << currentRoom -> getTitle() << endl;

  //PRint the Room description:
  cout << currentRoom -> getDescription() << endl;

  //Print the Room items:
  cout << "In the room, there are items: " << endl;
  vector<Item*> curItems = currentRoom -> getItems();

  for (vector<Item*>::iterator item = curItems.begin(); item != curItems.end(); item++) { //loop through the vector of items in the room
    cout << (*item) -> itemTitle << ", "; //print out the title of each item
  }

  cout << " " << endl;

  
  //Print the Room exits:
  
  /*Note: Referred to GeeksforGeeks.org (source at https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/) to understand that maps also need iterators and also that one can get the key of each object in the map using iteratorName -> first*/
  
  cout << "There are exits:" << endl;

  map<int, Room*> curMap = currentRoom -> getExits();

  for (map<int, Room*>::iterator pair = curMap.begin(); pair != curMap.end(); pair++) { //convert the integer keys in the map to their respective directions

    if (1 == (pair -> first)) {//a direction of 1 represents North
      char dir[6] = "NORTH";
      cout << dir << ", ";
    }
    else if (2 == (pair->first)) {//a direction of 2 represents East
      char dir[5] = "EAST";
      cout << dir << ", ";
    }
    else if (3 == (pair -> first)) {//a direction of 3 represents South
      char dir[6] = "SOUTH";
      cout << dir << ", ";
    }
    else if (4 == (pair -> first)) {//a direction of 4 represents West
      char dir[5] = "WEST";
      cout << dir << ", ";
    }
    
  }
  cout << " " << endl; 
}


//This function removes a specified item from the current room and adds it to the player's inventory: 
void takeItem(Room* &currentRoom, vector<Item*> &inventory, char itemName[50]){
  
  vector<Item*> roomItems = currentRoom -> getItems();
  int thereis = 0;
  Item* theITem = new Item
  
  //First check if the specified item is in the room:
  for (vector<Item*>::iterator item = roomItems.begin(); item != roomItems.end(); item++) {

    if (!strcmp((*item) -> itemTitle, itemName)) { //if an item in the room shares the name the player inputs...

      theItem = (*item); //save the found item
      thereis = 1; //the specified item is there!
    }
  }

  //If item is not there, notify the player:
  if (thereis == 0) {
    cout << "That item is not in the room" << endl;
  }

  //If the item is there, take it:
  else {
    currentRoom -> remItem(itemName); //remove the item from the room
    inventory.push_back(theItem); //add it to the player's inventory 

    cout << "Took " << itemName << endl; //notify the player
    cout << theItem -> itemDes << endl; //read item description
  }
}


//This function places a specified item in the player inventory in the current room (in the room vector of Items): 
void placeItem(Room* &currentRoom, vector<Item*> &inventory, char itemName[50]){
  
  vector<Item*> roomItems = currentRoom -> getItems(); //this is the current vector of Items in the current room
  Item* theItem = new Item;
  int thereis = 0;
  int index = 0;
  int pos = 0;
  
  for (vector<Item*>::iterator item = inventory.begin(); item != inventory.end(); item++) {

    if (!strcmp((*item) -> itemTitle, itemName)) { //if an item in the inventory matches the name inputted...

      theItem = (*item); //save the item
      thereis = 1; //it is present!
      pos = index; //save the item's position
    }
    index++;
  }

  //If there the item cannot be found in the inventory, notify player:
  if (thereis == 0) {
    cout << "You don't have that item" << endl;
  }

  //Else, place item:
  else {
    inventory.erase(inventory.begin() + pos); //erase the item from the inventory
    currentRoom -> addItem(theItem); //add the item to the current room
    cout << "Placed " << itemName << endl; //notify the player
  }
}


//This function changes the current room based on the direction (the exit) the player wants to travel:
void goTo(Room* &currentRoom, char direction[10]){
  
  map<int, Room*> roomExits = currentRoom -> getExits();

  int isThere = 0;
  int dir = 0;

  //Convert the inputted direction to its corresponding integer (as these directions are represented as int in the map of exits in each room)
  if (!strcmp("NORTH", direction)) {
    dir = 1;
  }
  else if (!strcmp("EAST", direction)) {
    dir = 2;
  }
  else if (!strcmp("SOUTH", direction)) {
    dir = 3;
  }
  else if (!strcmp("WEST", direction)) {
    dir = 4;
  }

  
  for (map<int, Room*>::iterator object = roomExits.begin(); object != roomExits.end(); object++) {

    if (dir == (object -> first)) { //if the inputted direction (as an int) matches a key in the map of the current room...
      isThere = 1; //the desired exit is there!
    }
  }

  //If no exit was found, notify the player:
  if (isThere == 0) {
    cout << "There is no such exit here" << endl;
  }

  //Else, change the current room:
  else {
    cout << "You move " << direction << endl; //notify the player
    currentRoom = roomExits[dir]; //change the current room based on the value (which is a Room*) corresponding to the integer direction desired in the current room's map
  }
}


//This function prints out the ending scenes for the game (there are two endings):
void end(bool &commanding, bool &playing, int type) {


  //Play ending 1 if the type == 1 (BAD END):

  //This plays when the player places all items in the "oldest" room:
  if (type == 1) {
    cout << "You feel a gust of wind from the Warden's Room" << endl;
    cout << "No..." << endl;
    cout << " " << endl;
    cout << "You reach in your pockets and feel the outline of an apple." << endl;
    cout << "Your surroundings morph and you once again find yourself in the cell" << endl;
    cout << " " << endl;
    cout << "You couldn't escape. Will you ever find yourself? [BAD END]" << endl;
  }

  //Play ending 2 if the type == 2 (TRUE END):

  //This plays when the player places all items but the apple in the oldest room and places the apple in the cell:
  if (type == 2) {
    cout << "Ah..." << endl;
    cout << "Suddenly a weight seems to lift off your shoulders" << endl;
    cout << "" << endl;
    cout << "Your surroundings softly fade away, like the fog in the oldest room" << endl;
    cout << "You are freed...[TRUE ENDING]" << endl;
  }

  //Stop the main game loops to end the game:
  commanding = false;
  playing = false;
}
