#pragma once
#include "SFML/Graphics.hpp"
class MainMenu
{
public:
	MainMenu(const sf::Vector2f ScreenSize);

private: 
	//Background
	sf::Texture tex_Background;
	sf::Sprite spr_Background;

	//Play
	sf::Texture tex_Play;
	sf::Sprite spr_Play;

	//Continue
	sf::Texture tex_Continue;
	sf::Sprite spr_Continue;

	//Exit
	sf::Texture tex_Exit;
	sf::Sprite spr_Exit;

public: 
	sf::Sprite &getBackground() { return spr_Background; };
	sf::Sprite &getPlayBtn() { return spr_Play; };
	sf::Sprite &getContinueBtn() { return spr_Continue; };
	sf::Sprite &getExitBtn() { return spr_Exit; };

	void DrawMainMenu(sf::RenderWindow &window);
};

