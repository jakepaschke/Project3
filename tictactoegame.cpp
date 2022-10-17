#include <iostream>
#include <stdlib.h>
using namespace std;

char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };

int choice;
int row, column;
char turn = 'X';
bool draw = false;

//Function to show the gaming board

void display_board() {
	
	cout << "     |     |     \n";
	cout << "  " << board[0][0] << "  | " << board[0][1] << "   |  " << board[0][2] << "\n";
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
	cout << "  " << board[1][0] << "  | " << board[1][1] << "   |  " << board[1][2] << "\n";
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
	cout << "  " << board[2][0] << "  | " << board[2][1] << "   |  " << board[2][2] << "\n";
	cout << "     |     |     \n";
}

//Function to get the player input

void player_turn() {
	if (turn == 'X') {
		cout << "\nPlayer - 1 [X] turn : ";
	}
	else if (turn == 'O') {
		cout << "\nPlayer - 2 [O] turn : ";
	}

	cin >> choice;

	switch (choice) {
	case 1: row = 0; column = 0; break;
	case 2: row = 0; column = 1; break;
	case 3: row = 0; column = 2; break;
	case 4: row = 1; column = 0; break;
	case 5: row = 1; column = 1; break;
	case 6: row = 1; column = 2; break;
	case 7: row = 2; column = 0; break;
	case 8: row = 2; column = 1; break;
	case 9: row = 2; column = 2; break;
	default:
		cout << "Invalid Move";
	}

	if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
		//updating the position for 'X' symbol
		board[row][column] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
		//updating the position for 'O' symbol
		board[row][column] = 'O';
		turn = 'X';
	}
	else {
		//if input position already filled
		cout << "Box already filled!\n Please choose another!!\n";
		player_turn();
	}
	

}

bool gameover() {
	//checking the win for rows/cols
	for (int i = 0; i < 3; i++)
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
			return true;

	//checking the win for diagonal

	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
		return true;

	//Checking the game is in continue mode
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] != 'X' && board[i][j] != 'O')
				return false;

	//Checking the if game is a draw
	draw = true;
	return false;
}

int main()
{
	cout << "PLAYER - 1 [X]t PLAYER - 2 [O]\n";
	while (!gameover()) {
		display_board();
		player_turn();
		gameover();
	}
	//turn changes after player wins
	//it will be the opposite turn of the player who wins
	if (turn == 'O' && draw == false) {
		display_board();
		cout << "Player with X has won the game";
	}
	else if (turn == 'X' && draw == false) {
		display_board();
		cout << "Player with O has won the game";
	}
	else
		cout << "Game Draw!";
}
