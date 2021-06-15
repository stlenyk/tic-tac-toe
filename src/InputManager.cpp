#include "InputManager.h"

bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window) {
	if(sf::Mouse::isButtonPressed(button)) {
		sf::IntRect objBounds(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height );
		return objBounds.contains(sf::Mouse::getPosition(window));
	}
	return false;
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window) {
	return sf::Mouse::getPosition(window);
}
