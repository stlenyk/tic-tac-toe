#ifndef TIC_TAC_TOE_SFML_GAMELOOP_H
#define TIC_TAC_TOE_SFML_GAMELOOP_H

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

using namespace std;

struct GameData {
	StateMachine machine;
	sf::RenderWindow window;
	AssetManager assets;
	InputManager input;
};

typedef std::shared_ptr<struct GameData> GameDataRef;

class GameLoop {
public:
	GameLoop(int width, int height, const string& title);

private:
	void Run();

private:
	const float dt = 1.0 / (float) FRAME_RATE;
	sf::Clock _clock;
	GameDataRef _data = make_shared<GameData>();

};


#endif //TIC_TAC_TOE_SFML_GAMELOOP_H
