#ifndef TIC_TAC_TOE_SFML_GAMESTATE_H
#define TIC_TAC_TOE_SFML_GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "../GameLoop.h"
#include "../State.h"

class GameState : public State {
public:
	explicit GameState(GameDataRef data) : _data(data) {}

	void Init() override;
	void HandleInput() override;
	void Update(float dt) override;
	void Draw(float dt) override;

private:
	GameDataRef _data;

	bool isGameOver = false;

	int boardStateArr[3][3];
	sf::Sprite _boardBg;
	sf::Sprite _boardPieces[3][3];
	sf::Sprite _replayButton;

	int currPlayer;

	void InitBoardSquares();
	void placePiece();
	void checkWinCon();
	void changeGameOver(size_t x1, size_t x2, size_t x3, size_t y1, size_t y2, size_t y3);
};


#endif //TIC_TAC_TOE_SFML_GAMESTATE_H
