//room.cpp

#include "room.h"
#include <ctime>

using namespace std;

Room::Room(){
	event = ' ';
	size = 0;
	row = 0;
	col = 0;
	arrow_count = 3;
	alive = true;
	gold_collected = false;
}

void Room::extend_room_cave(int s, bool m){
	room_cave.resize(s);
	for(int i = 0; i < s; i++){
		room_cave[i].resize(s);
	}
	size = s;
	mode = m;
}

void Room::print_room_cave(){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout << "+-----";
		}
		cout << '+' << endl;
		for(int j = 0; j < size; j++){
			cout << "|     ";
		}
		cout << '|' << endl;
		for(int j = 0; j < size; j++){ //polymorphism
			char c = room_cave[i][j]->get_symbol();
			if(mode == false && c != '*'){
				c = ' ';
			}
			cout << "|  " << c << "  ";
		}
		cout << '|' << endl;
		for(int j = 0; j < size; j++){
			cout << "|     ";
		}
		cout << '|' << endl;	
	}
	for(int i = 0; i < size; i++){
		cout << "+-----";
	}
	cout << '+' << endl;
}

void Room::set_room_cave(){
srand(time(NULL));
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
				Empty E;
				Event * e1 = &E;
				room_cave[i][j] = e1;
				room_cave[i][j]->set_there(false);
		}
	}
	Player Pl;
	Pit P1;
	Pit P2;
	Bats B1;
	Bats B2;
	Wumpus W1;
	Gold G1;
	
	//set player
	row = rand() % size;
	col = rand() % size;
	player_row = row;
	player_col = col;
	escape_row = row;
	escape_col = col;
	room_cave[row][col] = &Pl;
	room_cave[row][col]->set_there(true);	
	
	//set bats
	do{
		row = rand() % size;
		col = rand() % size;
	}while(room_cave[row][col]->is_there());
	
	room_cave[row][col] = &B1;
	room_cave[row][col]->set_there(true);	

	do{
	row = rand() % size;
	col = rand() % size;
	}while(room_cave[row][col]->is_there());

	room_cave[row][col] = &B2;
	room_cave[row][col]->set_there(true);

	//set pits
	do{
	row = rand() % size;
	col = rand() % size;
	}while(room_cave[row][col]->is_there());
	
	room_cave[row][col] = &P1;
	room_cave[row][col]->set_there(true);

	do{
	row = rand() % size;
	col = rand() % size;
	}while(room_cave[row][col]->is_there());
	
	room_cave[row][col] = &P2;
	room_cave[row][col]->set_there(true);

	//set wumpus
	do{
	row = rand() % size;
	col = rand() % size;
	}while(room_cave[row][col]->is_there());
	wumpus_row = row;
	wumpus_col = col;	
	room_cave[row][col] = &W1;
	room_cave[row][col]->set_there(true);

	//set gold
	do{
	row = rand() % size;
	col = rand() % size;
	}while(room_cave[row][col]->is_there());
	
	room_cave[row][col] = &G1;
	room_cave[row][col]->set_there(true);

	do{ //START OF TURN
        print_room_cave();

	//Perceptions
	if(player_row != 0){
		//check above player
		room_cave[player_row-1][player_col]->get_percept();
	}
	if(player_row != size-1){
		//check below player
		room_cave[player_row+1][player_col]->get_percept();
	}
	if(player_col != 0){
		//check to left of player
		room_cave[player_row][player_col-1]->get_percept();
	}
	if(player_col != size-1){
		//check to right of player
		room_cave[player_row][player_col+1]->get_percept();
	}



	do{ //take input
        cout << "Shoot or Move? (S or M): ";
        cin >> choice;
        }while(!(choice == 'S' || choice == 's' || choice == 'M' || choice == 'm'));

        if(choice == 'S' || choice == 's'){
                do{
                cout << "Shoot in what direction: North, East, South, West? (W, A, S, D): ";
                cin >> direction;
                }while(!(direction == 'W' || direction == 'w' || direction == 'A' || direction == 'a' || direction == 'S' || direction == 's' || direction == 'D' || direction == 'd'));
        }
        if(choice == 'M' || choice == 'm'){
                do{
                cout << "Move in what direction: North, East, South, West? (W, A, S, D): ";
                cin >> direction;
                }while(!(direction == 'W' || direction == 'w' || direction == 'A' || direction == 'a' || direction == 'S' || direction == 's' || direction == 'D' || direction == 'd'));
        }
	//SHOOT ARROW
	if(choice == 's' || choice == 'S'){
		if(arrow_count > 0){
		if(direction == 'w' || direction == 'W'){
			//check north
			if(player_row > 2){
			if(room_cave[player_row-1][player_col]->is_shot() || room_cave[player_row-2][player_col]->is_shot() || room_cave[player_row-3][player_col]->is_shot()){
				cout << "Killed wumpus!" << endl;
				Empty E;
				room_cave[wumpus_row][wumpus_col] = &E;
			}
			else{
				cout << "arrow missed" << endl;
			}
			}
			else if(player_row > 1){
			if(room_cave[player_row-1][player_col]->is_shot() || room_cave[player_row-2][player_col]->is_shot()){
				cout << "Killed wumpus!" << endl;
				Empty E;
				room_cave[wumpus_row][wumpus_col] = &E;
			}
			else{
				cout << "arrow missed" << endl;
			}
			}	
			else if(player_row > 0){
			if(room_cave[player_row-1][player_col]->is_shot()){
				cout << "Killed wumpus!" << endl;
				Empty E;
				room_cave[wumpus_row][wumpus_col] = &E;
			}
			else{
				cout << "arrow missed" << endl;
			}
			}
			else {
				cout << "arrow missed" << endl;
			}	
		}
		else if(direction == 's' || direction == 'S'){
			//check south
			if(player_row < size-3){
			if(room_cave[player_row+1][player_col]->is_shot() || room_cave[player_row+2][player_col]->is_shot() || room_cave[player_row+3][player_col]->is_shot()){
				cout << "Killed wumpus!" << endl;
				Empty E;
				room_cave[wumpus_row][wumpus_col] = &E;
			}
			else{
				cout << "arrow missed" << endl;
			}
			}	
			else if(player_row < size-2){
			if(room_cave[player_row+1][player_col]->is_shot() || room_cave[player_row+2][player_col]->is_shot()){
				cout << "Killed wumpus!" << endl;
				Empty E;
				room_cave[wumpus_row][wumpus_col] = &E;
			}
			else{
				cout << "arrow missed" << endl;
			}
			}	
			else if(player_row < size-1){
			if(room_cave[player_row+1][player_col]->is_shot()){
				cout << "Killed wumpus!" << endl;
				Empty E;
				room_cave[wumpus_row][wumpus_col] = &E;
			}
			else{
				cout << "arrow missed" << endl;
			}
			}
			else {
				cout << "arrow missed" << endl;
			}
		}
		else if(direction == 'd' || direction == 'D'){
			//check east
			if(player_col < size-3){
			if(room_cave[player_row][player_col+1]->is_shot() || room_cave[player_row][player_col+2]->is_shot() || room_cave[player_row][player_col+3]->is_shot()){
				cout << "Killed wumpus!" << endl;
				Empty E;
				room_cave[wumpus_row][wumpus_col] = &E;
			}
			else{
				cout << "arrow missed" << endl;
			}
			}	
			else if(player_col < size-2){
			if(room_cave[player_row][player_col+1]->is_shot() || room_cave[player_row][player_col+2]->is_shot()){
				cout << "Killed wumpus!" << endl;
				Empty E;
				room_cave[wumpus_row][wumpus_col] = &E;
			}
			else{
				cout << "arrow missed" << endl;
			}
			}	
			else if(player_col < size-2){
			if(room_cave[player_row][player_col+1]->is_shot()){
				cout << "Killed wumpus!" << endl;
				Empty E;
				room_cave[wumpus_row][wumpus_col] = &E;
			}
			else{
				cout << "arrow missed" << endl;
			}
			}
			else {
				cout << "arrow missed" << endl;
			}
		}
		else{
			//check west
			if(player_col > 2){
			if(room_cave[player_row][player_col-1]->is_shot() || room_cave[player_row][player_col-2]->is_shot() || room_cave[player_row][player_col-3]->is_shot()){
				cout << "Killed wumpus!" << endl;
				Empty E;
				room_cave[wumpus_row][wumpus_col] = &E;
			}
			else{
				cout << "arrow missed" << endl;
			}
			}	
			else if(player_col > 1){
			if(room_cave[player_row][player_col-1]->is_shot() || room_cave[player_row][player_col-2]->is_shot()){
				cout << "Killed wumpus!" << endl;
				Empty E;
				room_cave[wumpus_row][wumpus_col] = &E;
			}
			else{
				cout << "arrow missed" << endl;
			}
			}	
			else if(player_col > 0){
			if(room_cave[player_row][player_col-1]->is_shot()){
				cout << "Killed wumpus!" << endl;
				Empty E;
				room_cave[wumpus_row][wumpus_col] = &E;
			}
			else{
				cout << "arrow missed" << endl;
			}
			}
			else {
				cout << "arrow missed" << endl;
			}
		}
		arrow_count--;
		cout << "Arrows Remaining: " << arrow_count << endl;
		}
		else{
			cout << "No arrows remaining" << endl;
		}

		int chance = rand() % 100;
		if(player_row > 1){
		if(room_cave[player_row-1][player_col]->get_event() == 'W'){		
			if (chance > 24){
				//move wumpus
				Wumpus W;
				Empty E;
				room_cave[wumpus_row][wumpus_col] = &E;
				room_cave[wumpus_row][wumpus_col]->set_there(false);
				do{
				wumpus_row = rand() % size;
				wumpus_col = rand() % size;
				}while(room_cave[wumpus_row][wumpus_col]->is_there());
				room_cave[wumpus_row][wumpus_col] = &W;
				room_cave[wumpus_row][wumpus_col]->set_there(true);
			cout << "Wumpus moved" << endl;
			}	
		}	
		}
		if(player_col > 1){
		if(room_cave[player_row][player_col-1]->get_event() == 'W'){		
			if (chance > 24){
				//move wumpus
				Wumpus W;
				Empty E;
				room_cave[wumpus_row][wumpus_col] = &E;
				room_cave[wumpus_row][wumpus_col]->set_there(false);
				do{
				wumpus_row = rand() % size;
				wumpus_col = rand() % size;
				}while(room_cave[wumpus_row][wumpus_col]->is_there());
				room_cave[wumpus_row][wumpus_col] = &W;
				room_cave[wumpus_row][wumpus_col]->set_there(true);
			cout << "Wumpus moved" << endl;
			}	
		}	
		}
		if(player_row < size-1){
		if(room_cave[player_row+1][player_col]->get_event() == 'W'){		
			if (chance > 24){
				//move wumpus
				Wumpus W;
				Empty E;
				room_cave[wumpus_row][wumpus_col] = &E;
				room_cave[wumpus_row][wumpus_col]->set_there(false);
				do{
				wumpus_row = rand() % size;
				wumpus_col = rand() % size;
				}while(room_cave[wumpus_row][wumpus_col]->is_there());
				room_cave[wumpus_row][wumpus_col] = &W;
				room_cave[wumpus_row][wumpus_col]->set_there(true);
			cout << "Wumpus moved" << endl;
			}	
		}	
		}
		if(player_col < size-1){
		if(room_cave[player_row][player_col+1]->get_event() == 'W'){		
			if (chance > 24){
				//move wumpus
				Wumpus W;
				Empty E;
				room_cave[wumpus_row][wumpus_col] = &E;
				room_cave[wumpus_row][wumpus_col]->set_there(false);
				do{
				wumpus_row = rand() % size;
				wumpus_col = rand() % size;
				}while(room_cave[wumpus_row][wumpus_col]->is_there());
				room_cave[wumpus_row][wumpus_col] = &W;
				room_cave[wumpus_row][wumpus_col]->set_there(true);
			cout << "Wumpus moved" << endl;
			}	
		}	
		}
	}

	//MOVE
	if(choice == 'm' || choice == 'M'){
		if(direction == 'w' || direction == 'W'){
			//move north
			if(player_row == 0){ //checks if on top row
				cout << "There's a wall there" << endl;
			}
			else{
				//move player
				if(!room_cave[player_row-1][player_col]->is_there()){
					Empty E;
					Player Pl;
					room_cave[player_row][player_col] = &E;
					room_cave[player_row-1][player_col] = &Pl;
					player_row --;
				}
				else{ //event
					event = room_cave[player_row-1][player_col]->get_event();
					if(event == 'G'){
						gold_collected = true;
						cout << "Gold Collected" << endl;
						Player Pl;
						Empty E;
						room_cave[player_row-1][player_col] = &Pl;
						room_cave[player_row][player_col] = &E;
						player_row--;
					}
					else if(event == 'W' || event == 'P'){
						cout << "OH NO!" << endl;
						cout << "You Died!" << endl;
						cout << "*********" << endl;
						cout << "GAME OVER" << endl;
						cout << "*********" << endl;
						alive = false;
					}
					else if(event == 'B'){
						Empty E;
						Player Pl;
						room_cave[player_row][player_col] = &E;
						player_row = rand() % size;
						player_col = rand() % size;
						room_cave[player_row][player_col] = &Pl;
					}
				}		
			}		
		}
		else if(direction == 's' || direction == 'S'){
			//move south
			if(player_row == size-1){ //check if on bottom row
				cout << "There's a wall there" << endl;
			}
			else{
				//move player
				if(!room_cave[player_row+1][player_col]->is_there()){
					Empty E;
					Player Pl;
					room_cave[player_row][player_col] = &E;
					room_cave[player_row+1][player_col] = &Pl;
					player_row ++;
				}
				else{ //event
					event = room_cave[player_row+1][player_col]->get_event();
					if(event == 'G'){
						gold_collected = true;
						cout << "Gold Collected" << endl;
						
						Player Pl;
						Empty E;
						room_cave[player_row+1][player_col] = &Pl;
						room_cave[player_row][player_col] = &E;
						player_row++;
					}
					else if(event == 'W' || event == 'P'){
						cout << "OH NO!" << endl;
						cout << "You Died!" << endl;
						cout << "*********" << endl;
						cout << "GAME OVER" << endl;
						cout << "*********" << endl;
						alive = false;
					}
					else if(event == 'B'){
						Empty E;
						Player Pl;
						room_cave[player_row][player_col] = &E;
						player_row = rand() % size;
						player_col = rand() % size;
						room_cave[player_row][player_col] = &Pl;
					}
				}
			}
		}
		else if(direction == 'd' || direction == 'D'){
			//move east
			if(player_col == size-1){ //check if on last col
				cout << "There's a wall there" << endl;
			}
			else{
				//move player
				if(!room_cave[player_row][player_col+1]->is_there()){
					Empty E;
					Player Pl;
					room_cave[player_row][player_col] = &E;
					room_cave[player_row][player_col+1] = &Pl;
					player_col ++;
				}
				else{ //event
					event = room_cave[player_row][player_col+1]->get_event();
					if(event == 'G'){
						gold_collected = true;
						cout << "Gold Collected" << endl; //AYY 420
						
						Player Pl;
						Empty E;
						room_cave[player_row][player_col+1] = &Pl;
						room_cave[player_row][player_col] = &E;
						player_col++;
					}
					else if(event == 'W' || event == 'P'){
						cout << "OH NO!" << endl;
						cout << "You Died!" << endl;
						cout << "*********" << endl;
						cout << "GAME OVER" << endl;
						cout << "*********" << endl;
						alive = false;
					}
					else if(event == 'B'){
						Empty E;
						Player Pl;
						room_cave[player_row][player_col] = &E;
						player_row = rand() % size;
						player_col = rand() % size;
						room_cave[player_row][player_col] = &Pl;
					}
				}
			}
		}
		else{
			//move west
			if(player_col == 0){ //checks if on first col
				cout << "There's a wall there" << endl;
			}
			else{
				if(!room_cave[player_row][player_col-1]->is_there()){
					Empty E;
					Player Pl;
					room_cave[player_row][player_col] = &E;
					room_cave[player_row][player_col-1] = &Pl;
					player_col --;
				}
				else{ //event
					event = room_cave[player_row][player_col-1]->get_event();
					if(event == 'G'){
						gold_collected = true;
						cout << "Gold Collected" << endl;
						
						Player Pl;
						Empty E;
						room_cave[player_row][player_col-1] = &Pl;
						room_cave[player_row][player_col] = &E;
						player_col--;
					}
					else if(event == 'W' || event == 'P'){
						cout << "OH NO!" << endl;
						cout << "You Died!" << endl;
						cout << "*********" << endl;
						cout << "GAME OVER" << endl;
						cout << "*********" << endl;
						alive = false;
					}
					else if(event == 'B'){
						Empty E;
						Player Pl;
						room_cave[player_row][player_col] = &E;
						player_row = rand() % size;
						player_col = rand() % size;
						room_cave[player_row][player_col] = &Pl;
					}
				}
			}				
		}
	}
	//check if won
	if(gold_collected && player_row == escape_row && player_col == escape_col){
		cout << endl;
		cout << "You escaped the cave with the gold!" << endl;
		cout << "      Thank you for playing        " << endl;
		cout << endl;
		cout << "        =================          " << endl;
		cout << "         HUNT THE WUMPUS           " << endl;
		cout << "        =================          " << endl;
		cout << endl;
	}
	
	}while(!(!alive || (gold_collected && player_row == escape_row && player_col == escape_col)));
}

void Room::check_nearby(){

}
