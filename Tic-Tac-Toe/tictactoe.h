#pragma once
#include <vector>
#include <iostream>
#include <windows.h>
#include <string>

class tictactoe
{
private:
	std::vector <char> game;
	// Whose turn it is | true - x | false - 0
	bool turn = true;
	// Variable to store amount of moves done: If there's 9 moves and there's no winner, it's a draw.
	short turns = 0;
	// Variables to store amount of wins by X / O.
	short xWins = 0, oWins = 0;
public:
	// Constructor
	tictactoe();
	// Function to prepare game
	void prepGame();
	// Function to show the current game state
	void showGame();
	// Function to get the move from player 1 / player 2 and keep track of whose turn it is
	void getMove();
	// Function to check if someone has won
	char hasWon();
	// Function to check if it's a draw
	bool isDraw();
	// Function to check if player wants to play again
	bool playAgain();
	// Deconstructor
	~tictactoe();
};