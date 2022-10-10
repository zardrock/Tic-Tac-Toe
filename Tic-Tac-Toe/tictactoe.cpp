#include "tictactoe.h"

/*
The vector 'game'
 -(0)	-(1)	-(2)
 -(3)	-(4)	-(5)
 -(6)	-(7)	-(8)
*/

// Constructor
tictactoe::tictactoe() {
}

void tictactoe::prepGame() {
	game.clear();
	for (short i = 0; i < 9; ++i) {
		game.push_back('-');
	}
	turn = true;
	turns = 0;
}

// Function to show the current game state
void tictactoe::showGame() {
	system("cls");
	std::cout << "\n\n\n\n\n                 Tic - Tac - Toe\n\n\n";
	std::cout << "	" << game.at(0) << " (0)		" << game.at(1) << " (1)		" << game.at(2) << " (2)\n\n";
	std::cout << "	" << game.at(3) << " (3)    	" << game.at(4) << " (4)		" << game.at(5) << " (5)\n\n";
	std::cout << "	" << game.at(6) << " (6)		" << game.at(7) << " (7)		" << game.at(8) << " (8)\n\n\n\n\n\n\n";
}

// Function to get the move from player 1 / player 2 and keep track of whose turn it is
void tictactoe::getMove() {
	int move;
	bool foundMove = false;
	std::cout << "	What is your move? 0 - 8\n\n";
	do {
		std::cin >> move;
		if ((move >= 0) && (move < 9) && (game.at(move) == '-')) {
			foundMove = true;
			turns++;
			if (turn) {
				game.at(move) = 'X';
				turn = false;
			}
			else {
				game.at(move) = 'O';
				turn = true;
			}
		}
		if (!foundMove) {
			std::cout << "	Invalid move. Try again!\n\n";
		}
	} while (!foundMove);
}

// Function to check if someone has won; if it returns X X has won, if it returns O 0 has won, if it return 0, nobody has won yet.
char tictactoe::hasWon() {
	// Checking if X won
	if ((game.at(0) == 'X') && (game.at(1) == 'X') && (game.at(2) == 'X')) { xWins++; return 'X'; }
	if ((game.at(3) == 'X') && (game.at(4) == 'X') && (game.at(5) == 'X')) { xWins++; return 'X'; }
	if ((game.at(6) == 'X') && (game.at(7) == 'X') && (game.at(8) == 'X')) { xWins++; return 'X'; }
	if ((game.at(0) == 'X') && (game.at(3) == 'X') && (game.at(6) == 'X')) { xWins++; return 'X'; }
	if ((game.at(1) == 'X') && (game.at(4) == 'X') && (game.at(7) == 'X')) { xWins++; return 'X'; }
	if ((game.at(2) == 'X') && (game.at(5) == 'X') && (game.at(8) == 'X')) { xWins++; return 'X'; }
	if ((game.at(0) == 'X') && (game.at(4) == 'X') && (game.at(8) == 'X')) { xWins++; return 'X'; }
	if ((game.at(6) == 'X') && (game.at(4) == 'X') && (game.at(2) == 'X')) { xWins++; return 'X'; }

	if ((game.at(0) == 'O') && (game.at(1) == 'O') && (game.at(2) == 'O')) { oWins++; return 'O'; }
	if ((game.at(3) == 'O') && (game.at(4) == 'O') && (game.at(5) == 'O')) { oWins++; return 'O'; }
	if ((game.at(6) == 'O') && (game.at(7) == 'O') && (game.at(8) == 'O')) { oWins++; return 'O'; }
	if ((game.at(0) == 'O') && (game.at(3) == 'O') && (game.at(6) == 'O')) { oWins++; return 'O'; }
	if ((game.at(1) == 'O') && (game.at(4) == 'O') && (game.at(7) == 'O')) { oWins++; return 'O'; }
	if ((game.at(2) == 'O') && (game.at(5) == 'O') && (game.at(8) == 'O')) { oWins++; return 'O'; }
	if ((game.at(0) == 'O') && (game.at(4) == 'O') && (game.at(8) == 'O')) { oWins++; return 'O'; }
	if ((game.at(6) == 'O') && (game.at(4) == 'O') && (game.at(2) == 'O')) { oWins++; return 'O'; }

	return 0;
}

bool tictactoe::isDraw() {
	if (turns == 9) return true;
	return false;
}

bool tictactoe::playAgain() {
	system("cls");
	std::cout << "X has won " << xWins << " times!\n";
	std::cout << "0 has won " << oWins << " times!\n";
	while (1) {
		std::cout << "Do you want to play again?\nYes/No  (case sensitive)\n";
		std::string val;
		std::cin >> val;
		if (val == "Yes") return true;
		else if (val == "No") return false;
	}
}

// Deconstructor
tictactoe::~tictactoe() {
}
