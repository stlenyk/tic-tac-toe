
#ifndef TIC_TAC_TOE_SFML_ASSETMANAGER_H
#define TIC_TAC_TOE_SFML_ASSETMANAGER_H


#include <SFML/Graphics.hpp>
#include <string>
#include <map>

using namespace std;

class AssetManager {
public:
	AssetManager() = default;
	~AssetManager() = default;

	void LoadTexture(string name, string fileName);
	sf::Texture &GetTexture(string name);

private:
	map<string, sf::Texture> _textures;
};


#endif //TIC_TAC_TOE_SFML_ASSETMANAGER_H
