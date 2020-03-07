#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include <functional>
#include "GlobalVariables.h"
#include "Sfml/Audio.hpp"


class MainMenu
{
public:
	MainMenu(const sf::Vector2f ScreenSize, const std::string SaveFileName);

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

	sf::SoundBuffer buttonBuffer;
	sf::Sound buttonSound;
	
	bool fileSaved; 

public: 
	sf::Sprite &getBackground() { return spr_Background; };
	sf::Sprite &getPlayBtn() { return spr_Play; };
	sf::Sprite &getContinueBtn() { return spr_Continue; };
	sf::Sprite &getExitBtn() { return spr_Exit; };

	void DrawMainMenu(sf::RenderWindow &window);
	void MouseInput(sf::RenderWindow & window, Player & player, sf::View &view, E_GameState &gameState);
};

