#include "MainMenu.h"
#include "GraphicsUtils.h"
#include <fstream>
#include "Player.h"
#include <iostream>
#include "SavingSystem.h"

MainMenu::MainMenu(const sf::Vector2f ScreenSize, const std::string SaveFileName)
{
	spr_Background.setTexture(GraphicsUtils::InitializeSprite(tex_Background,"Art/background.jpg"));
	spr_Play.setTexture(GraphicsUtils::InitializeSprite(tex_Play, "Art/New Game.png"));
	spr_Continue.setTexture(GraphicsUtils::InitializeSprite(tex_Continue, "Art/Continue.png"));
	spr_Exit.setTexture(GraphicsUtils::InitializeSprite(tex_Exit, "Art/Exit.png"));

	spr_Play.setPosition(ScreenSize.x/2 - GraphicsUtils::spriteSize(spr_Play).x/2,ScreenSize.y/5);
	spr_Continue.setPosition(ScreenSize.x / 2 - GraphicsUtils::spriteSize(spr_Play).x / 2, ScreenSize.y / 2.5f);
	spr_Exit.setPosition(ScreenSize.x / 2 - GraphicsUtils::spriteSize(spr_Play).x / 2, ScreenSize.y / 1.65f);

	std::fstream file(SaveFileName);
	if (file.fail())
	{
		spr_Continue.setColor(sf::Color(255, 255, 255, 125));
		fileSaved = false;
	}
	else
	{
		spr_Continue.setColor(sf::Color(255, 255, 255, 255));
		fileSaved = true; 
	}
}

void MainMenu::DrawMainMenu(sf::RenderWindow & window)
{
	window.draw(spr_Background);
	window.draw(spr_Play);
	window.draw(spr_Continue);
	window.draw(spr_Exit);
}


void MainMenu::MouseInput(sf::RenderWindow & window, Player & player,sf::View &view, E_GameState &gameState)
{
	const float imageSize = 64;

	//Create mouse cursor for collision (Hidden)
	sf::RectangleShape rect(sf::Vector2f(10, 10));
	rect.setFillColor(sf::Color::Transparent);

	SavingSystem saveGame;

	sf::Event event;
	while (window.pollEvent(event))
	{
		//Save the game if player closes the game
		if (event.type == sf::Event::Closed)
		{
			saveGame.SaveGame(player);
			window.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//Move rect on mouse click for checking button pressed
			sf::Vector2i getMousePosition = sf::Mouse::getPosition(window);
			rect.setPosition(sf::Vector2f(getMousePosition));


			//Play Button
			if (rect.getGlobalBounds().intersects(spr_Play.getGlobalBounds()))
			{
				std::cout << "\New Game Btn Pressed";
				
				player.SetRoomId(0);
				player.getSprite().setPosition(window.getSize().x / 2, window.getSize().y / 2);
				view.setCenter(window.getSize().x / 2 + imageSize, window.getSize().y / 2);
				gameState = E_GameState::E_InGame;
				GraphicsUtils::playSound(buttonSound,buttonBuffer, "Music/ButtonPressed.wav",100,false);
			}
			//CONTINUE
			if (rect.getGlobalBounds().intersects(spr_Continue.getGlobalBounds()))
			{
				if (fileSaved == true)
				{
					gameState = E_GameState::E_InGame;
					GraphicsUtils::playSound(buttonSound, buttonBuffer, "Music/ButtonPressed.wav", 100, false);

					//Check if game was played before
					saveGame.ChecIfPlayedBefore(player, view);
					//change music ingame
					//changeMusicMenu = true;
					std::cout << "\nFile exists";
				}
			}
			if (rect.getGlobalBounds().intersects(spr_Exit.getGlobalBounds()))
			{
				std::cout << "\Exit Btn Pressed";
				//mainMenu = false;
				//stop music
				//sound.stop();
				window.close();
			}

		}
	}
}
