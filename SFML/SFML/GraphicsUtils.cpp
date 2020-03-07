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

void GraphicsUtils::playSound(sf::Sound & sound, sf::SoundBuffer & SoundBuffer, const std::string SoundAddress, float volume = 100, bool loop = false)
{
	if (!SoundBuffer.loadFromFile(SoundAddress))
	{
		std::cout << SoundAddress << " not found." << std::endl;
	}

	sound.setBuffer(SoundBuffer);
	sound.setVolume(volume);
	sound.setLoop(loop);
	sound.play();
}

void GraphicsUtils::PrintVector2f(sf::Vector2f Vector2)
{
	std::cout << "\nX: " << Vector2.x;
	std::cout << "\nY: " << Vector2.y;
}

