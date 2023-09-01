#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

/***********************************************
 *Function: print_board
 *Description: displays the board
 *Input: 2D dynamic array, rows, and cols
 *Output: Displays the array with contents
************************************************/
void print_board(char** arr, int rows, int cols){
	cout << "    ";
	for(int i = 0; i < cols; i++){
		if(i+1 < 9){
		cout << (i+1) << "   ";
		}
		else{
		cout << (i+1) << "  ";
		}
	}
	cout << endl;

	for(int i = 0; i < rows; i++){
		if(i+1 < 10){
		cout << i+1 << " ";
		}
		else{
			cout << i+1;
		}
		for(int j = 0; j < cols; j++){
			if(i % 2 == 0 && j % 2 == 0)
				cout << "|\033[30;47m " << arr[i][j] << " ";
			else if(i % 2 == 1 && j % 2 == 1)
				cout << "|\033[30;47m " << arr[i][j] << " ";
			else
				cout << "|\033[0m " << arr[i][j] << " ";
			cout << "\033[0m";
		}
		cout << endl;
	}
}

/*****************************************************************
 *Function: place_piece
 *Description: Places either X or O on the board at column 'test'
 *Input: array, rows, columns, given placement, type of piece
 *Output: Places piece in lowest empty row of given column
******************************************************************/
void place_piece(char **arr, int rows, int cols, int test, char piece){
	for(int i = (rows-1); i >= 0 ; i--){
		if(arr[i][test-1] == ' '){
			arr[i][test-1] = piece;
			break;
		}
	}
}

/*****************************************************
 *Function: full
 *Description: checks if the board is completely full
 *Input: array, rows, columns
 *Output: Returns boolean if board is filled
******************************************************/
bool full(char** arr, int rows, int cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(arr[i][j] == ' '){
				return true;
			}
		}
	}
	return false;
}

/******************************************************************************************************
 *Function: winner
 *Description: Looks through the array horizontally, vertically, and diagonally for a line of 4 pieces
 *Input: array, rows, columns, type of piece
 *Output: Returns boolean if there is a line of 4 pieces in any direction
********yy***********************************************************************************************/
bool winner(char** arr, int rows, int cols, char piece){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < (cols - 3); j++){
			if(arr[i][j] == piece && arr[i][j+1] == piece && arr[i][j+2] == piece && arr[i][j+3] == piece) //horiz
				return true;	
		}
	}
	for(int i = 0; i < (rows-3); i++){
		for(int j = 0; j < cols; j++){
			if(arr[i][j] == piece && arr[i+1][j] == piece && arr[i+2][j] == piece && arr[i+3][j] == piece) //vert
				return true;
		}
	}
	for(int i = 0; i < (rows-3); i++){
		for(int j = 0; j < (cols-3); j++){
			if(arr[i][j] == piece && arr[i+1][j+1] == piece && arr[i+2][j+2] == piece && arr[i+3][j+3] == piece) //diag down
				return true;
		}
	}
	for(int i = (rows-1); i >= 3; i--){
		for(int j = 0; j < (cols-3); j++){
			if(arr[i][j] == piece && arr[i-1][j+1] == piece && arr[i-2][j+2] == piece && arr[i-3][j+3] == piece) //diag up
				return true;
		}
	}

	return false;
}

/***************************************************************************
 *Function: col_full
 *Description: Checks if the given col has an empty space or if it is filled
 *Input: 2D array, rows, columns, test column
 *Output: boolean
****************************************************************************/
bool col_full(char** arr, int test){
	if(arr[0][test-1] == ' ')
		return false;	
	return true;
}

/***************************************************************
 *Function: is_int
 *Description: returns true or false if given string is integer
 *Input: string
 *Output: boolean
****************************************************************/
bool is_int(string num){
	for(int i = 0; i < num.length(); i++){
		if(num[i] >= '0' && num[i] <= '9'){
		} 
		else{
			return false;
		}
	}
	return true;
}

/*******************************************************************
 *Function: get_int
 *Description: takes in a string and returns the integer equivalent
 *Input: string
 *Output: integer of string
********************************************************************/
int get_int(string str, string type){
	int j = 0; int p = 1; int f = 0; int power = 10;
	string test_string;

	if(is_int(str)){
		power = pow(power, str.length() - 1);
		
		for(int i = 0; i < str.length(); i++){
			j += (str[i] - '0')*power;
			power /= 10;
		}
		f = 1;
	}
	else{
		cout << "Not a valid input, please enter an integer for the " << type << ": ";
		cin >> test_string;
		return get_int(test_string, type);
	}
	return j;
}
/****************************************************************************************
 *Function: computer_col
 *Description: looks at opponent's pieces and tries to block them by returning the column
 *Input: 2D array, rows, columns, and opponent's piece type
 *Output: column number to stop opponent
*****************************************************************************************/
int computer_col(char** arr, int rows, int cols, char piece){
	//3 IN A ROW
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < (cols - 3); j++){
			if(arr[i][j] == piece && arr[i][j+1] == piece && arr[i][j+2] == piece) //horiz
				return j+4;	
		}
	}
	for(int i = 0; i < (rows-3); i++){
		for(int j = 0; j < cols; j++){
			if(arr[i][j] == piece && arr[i+1][j] == piece && arr[i+2][j] == piece) //vert
				return j+1;
		}
	}
	for(int i = 0; i < (rows-3); i++){
		for(int j = 0; j < (cols-3); j++){
			if(arr[i][j] == piece && arr[i+1][j+1] == piece && arr[i+2][j+2] == piece) //diag down
				return j+4;
		}
	}
	for(int i = (rows-1); i >= 3; i--){
		for(int j = 0; j < (cols-3); j++){
			if(arr[i][j] == piece && arr[i-1][j+1] == piece && arr[i-2][j+2] == piece) //diag up
				return j+4;
		}
	}
	//2 IN A ROW
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < (cols - 3); j++){
			if(arr[i][j] == piece && arr[i][j+1] == piece) //horiz
				return j+3;	
		}
	}
	for(int i = 0; i < (rows-3); i++){
		for(int j = 0; j < cols; j++){
			if(arr[i][j] == piece && arr[i+1][j] == piece) //vert
				return j+1;
		}
	}
	for(int i = 0; i < (rows-3); i++){
		for(int j = 0; j < (cols-3); j++){
			if(arr[i][j] == piece && arr[i+1][j+1] == piece) //diag down
				return j+3;
		}
	}
	for(int i = (rows-1); i >= 3; i--){
		for(int j = 0; j < (cols-3); j++){
			if(arr[i][j] == piece && arr[i-1][j+1] == piece) //diag up
				return j+3;
		}
	}
	//ELSE
	return (rand() % cols + 1);
	

}

/**********************************
 *Function: main
 *Description: holds all the shtuff
***********************************/
int main (int argc, char* argv[]){
	string players1;
	string rows1;
	string cols1;

	int players = 0;
	int rows = 0;
	int cols = 0;

	if(argc != 4){
		cout << "Invalid number of arguments, please enter 3 integers" << endl;
		cout << "Enter number of players: ";
		cin >> players1;
		cout << "Enter number of rows: ";
		cin >> rows1;
		cout << "Enter number of cols: ";
		cin >> cols1;

		players = get_int(players1, "players");
		rows = get_int(rows1, "rows");
		cols = get_int(cols1, "columns");
		
	}
	else{
	string players1 = argv[1];
	string rows1 = argv[2];
	string cols1 = argv[3];
	
	players = get_int(players1, "players");
	rows = get_int(rows1, "rows");
	cols = get_int(cols1, "columns");
	}

	do{	
		if(players < 1 || players > 2){
			cout << "Enter 1 or 2 for players: " << endl;
			cin >> players1;
			players = get_int(players1, "players");
		}
		if(rows < 4 || rows > 20){
			cout << "Enter rows between 4 and 20: " << endl;
			cin >> rows1;
			rows = get_int(rows1, "rows");
		}
		if(cols < 4 || cols > 20){
			cout << "Enter cols between 4 and 20: " << endl; 
			cin >> cols1;
			cols = get_int(cols1, "columns");
		}
	}while(!is_int(players1) || !is_int(rows1) || !is_int(cols1));

	srand(time(NULL));
	int again;
do{
	char** board = new char*[rows];
	for(int i = 0; i < rows; i++){
		board[i] = new char[cols];
	}	

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			board[i][j] = ' ';
		}
	}


	string test_col;
	char player1 = 'X';
	char player2 = 'O';

	print_board(board, rows, cols);
	int test = 0;
	int test_int;

	if(players == 2){
		int j = 0;
	while(j == 0){
		do{
			//PLAYER 1
			cout << "Player 1, enter a column: ";
			cin >> test_col;
			test_int = get_int(test_col, "column");
			if(!is_int(test_col) || test_int < 1 || test_int > cols || col_full(board, test_int)){
				cout << "Invalid Entry" << endl;
				cout << "Please enter a number from 1 to " << cols << endl;
				j = 1;
			}
			else{
				j = 0;
			}		
		}while(j == 1);	

		place_piece(board, rows, cols, get_int(test_col, "column"), player1);
		print_board(board, rows, cols);		

		if(winner(board, rows, cols, player1)){ 
			cout << "**************" << endl;
			cout << "Player 1 Wins!" << endl;
			cout << "**************" << endl;
			break;
		}

		do{
			//PLAYER 2
			cout << "Player 2, enter a column: ";
			cin >> test_col;
			test_int = get_int(test_col, "column");
			if(!is_int(test_col) || test_int < 1 || test_int > cols || col_full(board, test_int)){
				cout << "Invalid Entry" << endl;
				cout << "Please enter a number from 1 to " << cols << endl;
				j = 1;
			}
			else{
				j = 0;
			}
		}while(j == 1);


		place_piece(board, rows, cols, get_int(test_col, "column"), player2);
		print_board(board, rows, cols);		
	
		if(winner(board, rows, cols, player2)){  //checks if player 2 wins
			cout << "**************" << endl;
			cout << "Player 2 Wins!" << endl;
			cout << "**************" << endl;
			break;
		}
		if(full(board, rows, cols) == false){
			break;
		}
	}
	}

	if(players == 1){
		string order;
		int j = 0;
		do{
			cout << "Do you want the computer to play first? 1-yes 0-no: ";
			cin >> order;
		
			if(!is_int(order) || !(get_int(order, "order") >= 0 && get_int(order, "order") <= 1)){
				cout << "Invalid Entry" << endl;
				j = 1;
			}
			else{
				j = 0;
			}
		}while(j == 1);
		
	while(j == 0){
		if(get_int(order, "order") == 0){
			int j = 0;
			do{
				//PLAYER 1
				cout << "Player 1, enter a column: ";
				cin >> test_col;
				test_int = get_int(test_col, "column");
				if(!is_int(test_col) || test_int < 1 || test_int > cols || col_full(board, test_int)){
					cout << "Invalid Entry" << endl;
					cout << "Please enter a number from 1 to " << cols << endl;
					j = 1;
				}
				else{
					j = 0;
				}
					
			}while(j == 1);
				
			place_piece(board, rows, cols, get_int(test_col, "column"), player1);
			print_board(board, rows, cols);	
		
			if(winner(board, rows, cols, player1)){   //checks if player 1 wins
				cout << "********************" << endl;
				cout << "You beat a computer!" << endl;
				cout << "********************" << endl;
				break;
			}
	
			//COMPUTER INPUT
			int com_col = computer_col(board, rows, cols, player1);
	
				if(col_full(board, com_col)){   //gives back different random input if column is full
					com_col = rand() % cols + 1;
				}
	 
			cout << "Computer chose column: " << com_col << endl;
	
			place_piece(board, rows, cols, com_col, player2);
			print_board(board, rows, cols);
		
			if(winner(board, rows, cols, player2)){  //checks if player 2 wins
				cout << "*************************" << endl;
				cout << "You lost to a computer :(" << endl;
				cout << "*************************" << endl;
				break;
			}
			if(full(board, rows, cols) == false){
				break;
			}
		}
		else{
			//COMPUTER INPUT
			int com_col = computer_col(board, rows, cols, player1);
	
				if(col_full(board, com_col)){   //gives back different random input if column is full
					com_col = rand() % cols + 1;
				}
	 
			cout << "Computer chose column: " << com_col << endl;
	
			place_piece(board, rows, cols, com_col, player2);
			print_board(board, rows, cols);
		
			if(winner(board, rows, cols, player2)){  //checks if player 2 wins
				cout << "*************************" << endl;
				cout << "You lost to a computer :(" << endl;
				cout << "*************************" << endl;
				break;
			}
	
			do{
				//PLAYER 1
				cout << "Player 1, enter a column: ";
				cin >> test_col;
				test_int = get_int(test_col, "column");
				if(!is_int(test_col) || test_int < 1 || test_int > cols || col_full(board, test_int)){
					cout << "Invalid entry" << endl;
					cout << "Please enter a number from 1 to " << cols << endl;
					j = 1;
				}
				else{
					j = 0;
				}
					
			}while(j == 1);
				
			place_piece(board, rows, cols, get_int(test_col, "column"), player1);
			print_board(board, rows, cols);	
		
			if(winner(board, rows, cols, player1)){   //checks if player 1 wins
				cout << "********************" << endl;
				cout << "You beat a computer!" << endl;
				cout << "********************" << endl;
				break;
			}
			if(full(board, rows, cols) == false){
				break;
			}
		}
	}
	}
	if(full(board, rows, cols) == false){
		cout << "***********" << endl;
		cout << "It's a tie!" << endl;
		cout << "***********" << endl;
	}
	
	cout << "Want to play again? yes-1 no-0: ";
	cin >> again;	


	for(int i = 0; i < rows; i++){  //deletes memory
		delete [] board[i];
	}
	delete [] board;
	board = NULL;

}while(again == 1);

	return 0;
}
