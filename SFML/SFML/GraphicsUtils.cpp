#include "GraphicsUtils.h"
#include <iostream>
sf::Texture & GraphicsUtils::InitializeSprite(sf::Texture & texture, const std::string & textureAddress)
{
	if (texture.loadFromFile(textureAddress))
	{
		std::cout << textureAddress << " worked correctly\n";
	}
	else
	{
		std::cerr << textureAddress << " didn't loaded correctly.";
	}
	return texture;
}
