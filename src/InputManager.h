#ifndef TIC_TAC_TOE_SFML_INPUTMANAGER_H
#define TIC_TAC_TOE_SFML_INPUTMANAGER_H

#include <SFML/Graphics.hpp>

class InputManager {
public:
	InputManager() = default;
	~InputManager() = default;

	static bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
	static sf::Vector2i GetMousePosition(sf::RenderWindow &window);
};


#endif //TIC_TAC_TOE_SFML_INPUTMANAGER_H
