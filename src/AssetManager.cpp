#include "AssetManager.h"

void AssetManager::LoadTexture(string name, string fileName) {
	sf::Texture texture;
	if(texture.loadFromFile(fileName)) {
		_textures[name] = texture;
	}
}

sf::Texture& AssetManager::GetTexture(string name) {
	return _textures.at(name);
}
