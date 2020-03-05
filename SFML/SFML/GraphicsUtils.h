#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
class GraphicsUtils
{
public: 
	static sf::Texture & InitializeSprite(sf::Texture &texture, const std::string &textureAddress);
	static const sf::Vector2f spriteSize(sf::Sprite &sprite);
	static void playSound(sf::Sound & sound, sf::SoundBuffer & SoundBuffer, const std::string SoundAddress, float volume, bool loop);
};

