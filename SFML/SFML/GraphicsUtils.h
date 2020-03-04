#pragma once
#include "SFML/Graphics.hpp"
class GraphicsUtils
{
public: 
	static sf::Texture & InitializeSprite(sf::Texture &texture, const std::string &textureAddress);
};

