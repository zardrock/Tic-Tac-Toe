#include "tictactoe.h"

int main(void) {
	tictactoe Game;
	do {
		Game.prepGame();
		do {
			Game.showGame();
			Game.getMove();
		} while (!(Game.hasWon()) && !(Game.isDraw()));
	} while (Game.playAgain());
}