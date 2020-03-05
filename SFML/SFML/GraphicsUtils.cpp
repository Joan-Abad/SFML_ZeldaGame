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

const sf::Vector2f GraphicsUtils::spriteSize(sf::Sprite & sprite)
{
	return { sprite.getTexture()->getSize().x * sprite.getScale().x,sprite.getTexture()->getSize().y * sprite.getScale().y };
}