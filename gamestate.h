#ifndef PROJEKT_GAMESTATE_H
#define PROJEKT_GAMESTATE_H

#include <stdlib.h>
using namespace std;

enum SquareState {
	BLANK,
	X,
	O,
	Count
};

class GameState {
private:
	static const size_t boardSize = 3;
	int board[boardSize][boardSize];
	GameState() = default;

public:
	bool changeState(size_t i, size_t j, SquareState newState);
	SquareState checkWinCond();

};


#endif //PROJEKT_GAMESTATE_H
