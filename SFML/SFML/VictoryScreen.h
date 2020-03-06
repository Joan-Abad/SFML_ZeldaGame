#pragma once
#include "SFML/Graphics.hpp"
class VictoryScreen
{
public:
	VictoryScreen(const sf::Vector2f &ScreenSize);

	void DrawVictoryScreen(sf::RenderWindow &window);

private: 
	sf::Sprite spr_Victory;
	sf::Texture tex_Victory;

	sf::Sprite spr_Background;
	sf::Texture tex_Background;
};

