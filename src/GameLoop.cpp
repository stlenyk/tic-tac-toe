#include "GameLoop.h"
#include "States/SplashState.h"
#include <algorithm>

GameLoop::GameLoop(int width, int height, const string& title) {
	_data->window.create(sf::VideoMode(width, height), title, sf::Style::Default);
	_data->machine.AddState(StateRef(new SplashState(_data)));
	Run();
}

void GameLoop::Run() {
	float currTime = _clock.getElapsedTime().asSeconds();
	float acc = 0;
	while(_data->window.isOpen()) {
		_data->machine.ProcessStateChanges();
		float newTime = _clock.getElapsedTime().asSeconds();
		float frameTime = newTime - currTime;
		frameTime = min(frameTime, MAX_FRAME_TIME);

		currTime = newTime;
		acc += frameTime;

		while(acc >= this->dt) {
			_data->machine.GetActiveState()->HandleInput();
			_data->machine.GetActiveState()->Update(dt);
			acc -= dt;
		}
		float interpolation = acc / dt;
		_data->machine.GetActiveState()->Draw(interpolation);
	}
}
