//
// Created by stlen on 15.06.2021.
//

#include "gamestate.h"

bool GameState::changeState(size_t i, size_t j, SquareState newState) {
	if(board[i][j] != BLANK) return false;
	board[i][j] = newState;
	return true;
}

SquareState GameState::checkWinCond() {
	int winSumX, winSumO;
	for(int i=0; i<boardSize; i++) {
		winSumX = 0;
		winSumO = 0;
		for(int j=0; j<boardSize; j++) {
			if(board[i][j] == SquareState::X) winSumX++;
			if(board[i][j] == SquareState::O) winSumO++;
		}
		if(winSumX == boardSize) return X;
		if(winSumO == boardSize) return O;
	}
	for(int j=0; j<boardSize; j++) {
		winSumX = 0;
		winSumO = 0;
		for(int i=0; i<boardSize; i++) {
			if(board[i][j] == SquareState::X) winSumX++;
			if(board[i][j] == SquareState::O) winSumO++;
		}
		if(winSumX == boardSize) return X;
		if(winSumO == boardSize) return O;
	}
	return BLANK;
}
