#include "SplashState.h"
#include "GameState.h"
#include <iostream>

#define SPLASH_BG_ASSET "splash bg"

void SplashState::Init() {
	_data->assets.LoadTexture(SPLASH_BG_ASSET, SPLASH_BG_PATH);
	sf::Texture& bgTexture = _data->assets.GetTexture(SPLASH_BG_ASSET);
	_background.setTexture(bgTexture);
	_background.setPosition((SCREEN_WIDTH - _background.getGlobalBounds().width)/2, (SCREEN_HEIGHT - _background.getGlobalBounds().height)/2);
}

void SplashState::HandleInput() {
	sf::Event event;
	while(_data->window.pollEvent(event)) {
		if(event.type == sf::Event::Closed)
			_data->window.close();
	}
}

void SplashState::Update(float dt) {
	if(_clock.getElapsedTime().asSeconds() > SPLASH_SHOW_TIME) {
		_data->machine.AddState(StateRef(new GameState(_data)), true);
	}
}

void SplashState::Draw(float dt) {
	_data->window.clear(sf::Color::White);
	_data->window.draw(_background);
	_data->window.display();
}





