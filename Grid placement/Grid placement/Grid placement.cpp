// Grid placement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "varibles.h"
#include <iostream>
#include <string>
using namespace std;

#define heightDef 10
#define widthDef 10
//int height = heightDef, width = widthDef;		Remove if not used

int board[heightDef][widthDef];

int correct = 0;
int gameEnd = 0;

int numberOfRoundsPlayed;
int numberOfRoundsToOver = 100;

//H = height W = Width | HI = Height Input WI = Width Input
int checkH, checkW, placeHI, placeWI;

int numberOfCorrect = 3;
int numberOfPlayer = 2;
int playerTurn = 1;

void settUpBoard() {

	playerTurn = 1;

	//Goes troue one line (in board array) (Board[this box][not this]) It loops the code to there are no more colloms (desided by heigth)
	for (int a = 0; a < heightDef; ++a) {
		//Goes troue a collom (in board array) (Board[not this][this box). It loops the code to there are no more colloms (desided by width)
		for (int b = 0; b < widthDef; ++b) {
			//adds the value 0 to the array
			board[a][b] = 0;

			//prints out the array
			cout << board[a][b] << " ";
		}
		cout << endl;
	}
}

void updateBoard() {

	for (int a = 0; a < heightDef; ++a) {
		for (int b = 0; b < widthDef; ++b) {
			cout << board[a][b] << " ";
		}
		cout << endl;
	}
}

//Tests show this to work...
void checkCorrectWin() {

	//Main loop
	while (correct < numberOfCorrect) {

		//Check H direction

		//Test if variables above (- Hight) is the same as the player (playerTurn)
		correct = 1;
		checkH = placeHI - 1;
		checkW = placeWI;

		while (board[placeHI][placeWI] && board[checkH][checkW] == playerTurn) {
			++correct;
			--checkH;
		}

		//Test if variables Below (+ Hight) is the same as the player (playerTurn)
		checkH = placeHI + 1;
		checkW = placeWI;

		while (board[placeHI][placeWI] && board[checkH][checkW] == playerTurn) {
			++correct;
			++checkH;
		}

		//Ends te loop if the numberOfCorrect is the same or bigger then correct
		if (correct >= numberOfCorrect) {
			break;
		}

		//Done cheking H direction

		//----------

		//Check W direction

		//Test if variables on the left (- Width) is the same as the player (playerTurn)
		correct = 1;
		checkH = placeHI;
		checkW = placeWI - 1;

		while (board[placeHI][placeWI] && board[checkH][checkW] == playerTurn) {
			++correct;
			--checkW;
		}

		//Test if variables on the right (+ Width) is the same as the player (playerTurn)
		checkH = placeHI;
		checkW = placeWI + 1;

		while (board[placeHI][placeWI] && board[checkH][checkW] == playerTurn) {
			++correct;
			++checkW;
		}

		//Ends te loop if the numberOfCorrect is the same or bigger then correct
		if (correct >= numberOfCorrect) {
			break;
		}

		//Done checking W directon

		//----------

		//Check diagonal top left to below right

		//Test if variables above and left (- Hight | - Width) is the same as the player (playerTurn)
		correct = 1;
		checkH = placeHI - 1;
		checkW = placeWI - 1;

		while (board[placeHI][placeWI] && board[checkH][checkW] == playerTurn) {
			++correct;
			--checkH;
			--checkW;
		}

		//Test if variables below and right (+ Hight | - Width) is the same as the player (playerTurn)
		checkH = placeHI + 1;
		checkW = placeWI - 1;

		while (board[placeHI][placeWI] && board[checkH][checkW] == playerTurn) {
			++correct;
			++checkH;
			--checkW;
		}

		//Ends te loop if the numberOfCorrect is the same or bigger then correct
		if (correct >= numberOfCorrect) {
			break;
		}

		// Done chekin diagonal above left to below right

		//----------

		//Check diagonal top right to below left

		//Test if variables above and right (- Hight | + Width) is the same as the player (playerTurn)
		correct = 1;
		checkH = placeHI - 1;
		checkW = placeWI + 1;

		while (board[placeHI][placeWI] && board[checkH][checkW] == playerTurn) {
			++correct;
			--checkH;
			++checkW;
		}

		//Test if variables above and right (+ Hight | + Width) is the same as the player (playerTurn)
		checkH = placeHI + 1;
		checkW = placeWI + 1;

		while (board[placeHI][placeWI] && board[checkH][checkW] == playerTurn) {
			++correct;
			++checkH;
			++checkW;
		}

		//Ends te loop if the numberOfCorrect is the same or bigger then correct
		if (correct >= numberOfCorrect) {
			break;
		}

		//Done checking top right to below left

		//----------

		break;
	}

}

void editValue() {
	
	cout << endl << "Place H and W (Hight and With):";
	cout << endl << "H= ";
	cin >> placeHI;
	cout << "W= ";
	cin >> placeWI;

	cout << "H=" << placeHI << "W=" << placeWI;

	//Place the writen walues in the correct place.
	board[placeHI][placeWI] = playerTurn;

	//Need to add support for multiple users...

}

void test() {
	//Just for testing.

	//Setts the board at the start of the games
	settUpBoard();

	cout << endl << "Edit" << endl;
	editValue();

	cout << endl << "Update" << endl;
	updateBoard();

	cout << endl << "Edit" << endl;
	editValue();

	cout << endl << "Update" << endl;
	updateBoard();

	cout << endl << "Edit" << endl;
	editValue();

	cout << endl << "Update" << endl;
	updateBoard();

	cout << endl << "Check" << endl;
	checkCorrectWin();
	cout << "Correct = " << correct << endl;

}

void changePlayer() {

	//Change the players turn
	if (playerTurn == numberOfPlayer) {

		playerTurn = 1;

	}
	else {

		++playerTurn;

	}
}

void winingMessage() {

	cout << endl << endl << "Game over!" << endl << "Player " << playerTurn << " has won the game!" << endl;

}

int main()
{
	
	//test();

	//Creates the board before the game begins
	settUpBoard();

	//Main game loop
	while (gameEnd == 0){

		//Makes the player place the values so the round can start
		editValue();

		//Clears the board
		system("cls");

		//Update the board
		updateBoard();

		//Check if player has won
		checkCorrectWin();

		//Check if the last move was a wining move
		if (correct >= numberOfCorrect){
			
			//Display the wining player
			winingMessage();

			//Ends the while loop
			++gameEnd;
		}
		else if (numberOfRoundsPlayed >= numberOfRoundsToOver) {

			//Display the wining player
			winingMessage();

			//Ends the while loop
			++gameEnd;

		}
		else {
			
			changePlayer();

		}

	}

	//Waits for input
	system("pause");
    return 0;
}