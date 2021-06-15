#ifndef TIC_TAC_TOE_SFML_SPLASHSTATE_H
#define TIC_TAC_TOE_SFML_SPLASHSTATE_H

#include <SFML/Graphics.hpp>
#include "../GameLoop.h"
#include "../State.h"

class SplashState : public State {
public:
	explicit SplashState(GameDataRef data) : _data(data) {}

	void Init() override;
	void HandleInput() override;
	void Update(float dt) override;
	void Draw(float dt) override;

private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Clock _clock;

};


#endif //TIC_TAC_TOE_SFML_SPLASHSTATE_H
