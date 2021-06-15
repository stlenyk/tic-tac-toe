#include "GameState.h"
#include <iostream>

#define REPLAY_ASSET "replay_asset"
#define BOARD_ASSET "board_asset"
#define X_ASSET "x_asset"
#define O_ASSET "o_asset"
#define HUMAN_PIECE_ASSET X_ASSET
#define AI_PIECE_ASSET O_ASSET

void GameState::Init() {
	_data->assets.LoadTexture(REPLAY_ASSET, REPLAY_PATH);
	_data->assets.LoadTexture(BOARD_ASSET, BOARD_PATH);
	_data->assets.LoadTexture(X_ASSET, X_PATH);
	_data->assets.LoadTexture(O_ASSET, O_PATH);

	_replayButton.setTexture(_data->assets.GetTexture(REPLAY_ASSET));
	_replayButton.setPosition(0.95*_data->window.getSize().x - _replayButton.getLocalBounds().width, 0.05*_data->window.getSize().y);

	_boardBg.setTexture(_data->assets.GetTexture(BOARD_ASSET));
	_boardBg.setPosition((_data->window.getSize().x - _boardBg.getGlobalBounds().width) / 2, (_data->window.getSize().y - _boardBg.getGlobalBounds().height) / 2);

	currPlayer = HUMAN_PIECE;

	InitBoardSquares();

}

void GameState::HandleInput() {
	sf::Event event;
	while(_data->window.pollEvent(event)) {
		if(event.type == sf::Event::Closed)
			_data->window.close();
		else if(_data->input.IsSpriteClicked(_replayButton, sf::Mouse::Left, _data->window))
			_data->machine.AddState(StateRef(new GameState(_data)), true);
		else if(_data->input.IsSpriteClicked(_boardBg, sf::Mouse::Left, _data->window)) {
			placePiece();
		}
	}
}

void GameState::Update(float dt) {

}

void GameState::Draw(float dt) {
	_data->window.clear(sf::Color::White);
	_data->window.draw(_boardBg);

	for(size_t i=0; i<3; i++) {
		for(size_t j=0; j<3; j++) {
			_data->window.draw(_boardPieces[i][j]);
		}
	}

	_data->window.draw(_replayButton);

	_data->window.display();
}

void GameState::InitBoardSquares() {
	for(size_t i = 0; i < 3; i++) {
		for(size_t j = 0; j < 3; j++) {
			boardStateArr[i][j] = BLANK_PIECE;
		}
	}

	sf::Texture &samplePiece = _data->assets.GetTexture(X_ASSET);
	sf::Vector2u pieceSize = samplePiece.getSize();
	for(size_t i=0; i<3; i++) {
		for(size_t j=0; j<3; j++) {
			_boardPieces[i][j].setTexture(samplePiece);
			_boardPieces[i][j].setPosition(_boardBg.getPosition().x + 20 + (pieceSize.x+55) * i, _boardBg.getPosition().y + 30 + (pieceSize.y+50) * j);
			_boardPieces[i][j].setColor(sf::Color(255,255,255,0));
		}
	}
}

void GameState::placePiece() {
	if(isGameOver) return;

	sf::Vector2i clickLocation = _data->input.GetMousePosition(_data->window);
	sf::FloatRect boardSize = _boardBg.getGlobalBounds();
	sf::Vector2f shiftGap ((_data->window.getSize().x - boardSize.width)/2, (_data->window.getSize().y - boardSize.height)/2);
	sf::Vector2i localClickLocation (clickLocation.x - (int)shiftGap.x, clickLocation.y - (int)shiftGap.y);

	sf::Vector2i boardSquareSize ((int)boardSize.width/3, (int)boardSize.height/3);
	int posX, posY;

	if(localClickLocation.x < boardSquareSize.x)
		posX = 0;
	else if(localClickLocation.x < boardSquareSize.x * 2)
		posX = 1;
	else posX = 2;

	if(localClickLocation.y < boardSquareSize.y) posY = 0;
	else if(localClickLocation.y < boardSquareSize.x * 2) posY = 1;
	else posY = 2;

	if(boardStateArr[posX][posY] == BLANK_PIECE) {
		boardStateArr[posX][posY] = currPlayer;
		if(currPlayer == HUMAN_PIECE) {
			_boardPieces[posX][posY].setTexture(_data->assets.GetTexture(HUMAN_PIECE_ASSET));
			currPlayer = AI_PIECE;
		}
		else {
			_boardPieces[posX][posY].setTexture(_data->assets.GetTexture(AI_PIECE_ASSET));
			currPlayer = HUMAN_PIECE;
		}
		_boardPieces[posX][posY].setColor(sf::Color(255,255,255,255));
		checkWinCon();
	}
}

void GameState::checkWinCon() {
	int winSumX, winSumO;
	for(size_t i=0; i<3; i++) {
		winSumX=0;
		winSumO=0;
		for(size_t j=0; j<3; j++) {
			if(boardStateArr[i][j] == X_PIECE) winSumX++;
			if(boardStateArr[i][j] == O_PIECE) winSumO++;
		}
		if(winSumX == 3 || winSumO == 3) {
			changeGameOver(i, i, i, 0, 1, 2);
			return;
		}
	}
	for(size_t j=0; j<3; j++) {
		winSumX=0;
		winSumO=0;
		for(size_t i=0; i<3; i++) {
			if(boardStateArr[i][j] == X_PIECE) winSumX++;
			if(boardStateArr[i][j] == O_PIECE) winSumO++;
		}
		if(winSumX == 3 || winSumO == 3) {
			changeGameOver(0, 1, 2, j, j, j);
			return;
		}
	}
	if(boardStateArr[1][1] != BLANK_PIECE) {
		if(boardStateArr[0][0] == boardStateArr[1][1] && boardStateArr[1][1] == boardStateArr[2][2]) {
			changeGameOver(0, 1, 2, 0, 1, 2);
			return;
		}
		if(boardStateArr[0][2] == boardStateArr[1][1] && boardStateArr[1][1] == boardStateArr[2][0]) {
			changeGameOver(0, 1, 2, 2, 1, 0);
			return;
		}
	}
}

void GameState::changeGameOver(size_t x1, size_t x2, size_t x3, size_t y1, size_t y2, size_t y3) {
	isGameOver = true;
	int winner = boardStateArr[x1][y1];
	const std::string WINNER_ASSET = "winner asset";
	if(winner == X_PIECE) {
		_data->assets.LoadTexture(WINNER_ASSET, X_WIN_PATH);
	}
	else {
		_data->assets.LoadTexture(WINNER_ASSET, O_WIN_PATH);
	}

	sf::Texture &winTex = _data->assets.GetTexture(WINNER_ASSET);
	_boardPieces[x1][y1].setTexture(winTex);
	_boardPieces[x2][y2].setTexture(winTex);
	_boardPieces[x3][y3].setTexture(winTex);
}










