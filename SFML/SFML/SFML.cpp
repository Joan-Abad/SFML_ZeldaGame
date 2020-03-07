#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include "MainMenu.h"
#include "GraphicsUtils.h"
#include "VictoryItem.h"
#include "VictoryScreen.h"
#include "SavingSystem.h"
#include "Enemy_BluePig.h"

void CreateEnemies();

//Global variables
const int imageSize = 64;
const sf::Vector2f ScreenSize = { imageSize * 15, imageSize * 8 };
const std::string saveFileName = "SaveFile.txt";
E_GameState gameState = E_InGame; 

std::vector<Enemy_BluePig*> BluePigsInMap;

int main()
{

	//INITIALIZE

	//UI STUFF
	MainMenu mainMenuObj(ScreenSize, saveFileName);
	VictoryScreen victorySreen(ScreenSize);
	sf::Text lifes; 
	sf::Font font;
	if (!font.loadFromFile("Fonts/VisualMagnets.ttf"))
		std::cout << "\nFormalart.ttf cauldn't load corretly";
	else
		lifes.setFont(font);

	lifes.setFillColor(sf::Color::White);
	//lifes.setStyle(sf::Text::Bold | sf::Text::Underlined);
	lifes.setCharacterSize(24);
	
	//MAP
	Map map;

	//View
	sf::View view(sf::Vector2f((ScreenSize.x / 2) + imageSize, ScreenSize.y / 2), sf::Vector2f(ScreenSize.x, ScreenSize.y));

	//SOUND
	sf::SoundBuffer soundBuffer;

	sf::Sound MainMenuSound;
	sf::Sound DungeonsSound;
	sf::Sound VictorySound;

	//Create the player
	Player player(ScreenSize);
	std::string lifesS = "Lifes " + std::to_string(player.getLifes());
	
	lifes.setString(std::to_string(player.getLifes()));
	lifes.setPosition(ScreenSize.x - ScreenSize.x/20, ScreenSize.y/20);

	//Create Winning Item
	VictoryItem victoryItem(ScreenSize);

	//Create the window
	sf::RenderWindow window(sf::VideoMode(ScreenSize.x, ScreenSize.y), "SFML Game!");

	//SAVING SYSTEM
	SavingSystem SaveFile;

	CreateEnemies();

	//While window is open
	while (window.isOpen())
	{
		switch (gameState)
		{
			//InMainMenu
		case E_MainMenu:

			if (MainMenuSound.getStatus() != MainMenuSound.Playing)
			{
				GraphicsUtils::playSound(MainMenuSound, soundBuffer, "Music/MainMenu.wav", 50, true);
			}
			//Handle all input mouse could do
			mainMenuObj.MouseInput(window, player, view, gameState);

			window.clear();
			mainMenuObj.DrawMainMenu(window);
			window.display();
			break;

			//InGame
		case E_InGame:

			//Player ingame logic
			if (MainMenuSound.getStatus() == MainMenuSound.Playing)
			{
				MainMenuSound.stop();
				GraphicsUtils::playSound(DungeonsSound, soundBuffer, "Music/Dungeon.wav", 50, true);
			}

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					SaveFile.SaveGame(player);
					window.close();
				}
			}

			//Player functionality
			player.PlayerFunctionality(event, map);

			//Map check collisions
			map.CheckPlayerCollisions(player, view, victoryItem, gameState);

			
			{
				sf::Vector2f lifePositionText = { player.getSprite().getPosition().x,player.getSprite().getPosition().y - (GraphicsUtils::spriteSize(player.getSprite()).y) };
				lifes.setPosition(lifePositionText);
			}

			//Window draw stuff
			window.clear();
			map.DrawRooms(window, player);
			window.setView(view);

			//If have the same id
			if (player.getRoomId() == victoryItem.getRoomSpawnedId())
				window.draw(victoryItem.getSprite());
			
			//Draw BluePigs
			for(auto &BluePig : BluePigsInMap)
			{
				if (BluePig->getRoomSpawnedId() == player.getRoomId())
				{
					BluePig->EnemyMovement(map, player);
					window.draw(BluePig->getSprite());
				}
			}

			player.drawPlayer(window);
			window.draw(lifes);
			window.display();
			break;
		
			//If player wins the game
		case E_Victory:
		{
			sf::View viewa(sf::Vector2f((ScreenSize.x / 2), ScreenSize.y / 2), sf::Vector2f(ScreenSize.x, ScreenSize.y));
			window.setView(viewa);
		}
		while (window.pollEvent(event))
		{
			if (DungeonsSound.getStatus() == DungeonsSound.Playing)
			{
				DungeonsSound.stop();
				GraphicsUtils::playSound(VictorySound, soundBuffer, "Music/Victory.wav", 70, false);
			}

			if (event.type == sf::Event::Closed)
			{
				player.PlayerWonTheGame = false;
				window.close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				SaveFile.SaveGame(player);
				gameState = E_MainMenu;
			}
		}
		window.clear();
		victorySreen.DrawVictoryScreen(window);

		window.display();
		break;

		case E_GameOver:
			break;
		}
	}
	return 0;
}

void CreateEnemies()
{
//CREATE BLUE PIGS

	//ROOM ID 1
	Enemy_BluePig *Pig1 = new Enemy_BluePig(0, 1, sf::Vector2f(ScreenSize.x / 1.3f, 250), 1);
	Enemy_BluePig *Pig2 = new Enemy_BluePig(0, 1, sf::Vector2f(ScreenSize.x / 2.2f, 150), 1);
	Enemy_BluePig *Pig3 = new Enemy_BluePig(1, 0, sf::Vector2f(ScreenSize.x / 2.2f, 280), 1);

	//ROOM ID 2
	Enemy_BluePig *Pig4 = new Enemy_BluePig(-1, 0, sf::Vector2f(570, 330), 2);
	Enemy_BluePig *Pig13 = new Enemy_BluePig(0, 1, sf::Vector2f(460, 220), 2);
	Enemy_BluePig *Pig14 = new Enemy_BluePig(0, 1, sf::Vector2f(265, 380), 2);

	//ROOM ID 3
	Enemy_BluePig *Pig5 = new Enemy_BluePig(1, 0, sf::Vector2f(260, 140), 3);
	Enemy_BluePig *Pig6 = new Enemy_BluePig(0, -1, sf::Vector2f(520, 150), 3);
	Enemy_BluePig *Pig7 = new Enemy_BluePig(0, -1, sf::Vector2f(720, 400), 3);

	//ROOM ID 4
	Enemy_BluePig *Pig8 = new Enemy_BluePig(1, 0, sf::Vector2f(755, 200), 4);
	Enemy_BluePig *Pig9 = new Enemy_BluePig(0, 1, sf::Vector2f(650, 300), 4);
	Enemy_BluePig *Pig10 = new Enemy_BluePig(0, -1, sf::Vector2f(265, 350), 4);

	//ROOM ID 6
	Enemy_BluePig *Pig15 = new Enemy_BluePig(0, 1, sf::Vector2f(270, 410), 5);
	Enemy_BluePig *Pig16 = new Enemy_BluePig(0, 1, sf::Vector2f(270, 150), 5);
	Enemy_BluePig *Pig17 = new Enemy_BluePig(0, 1, sf::Vector2f(650, 310), 5);
	Enemy_BluePig *Pig18 = new Enemy_BluePig(0, 1, sf::Vector2f(270, 150), 5);

	//ROOM ID 6
	Enemy_BluePig *Pig11 = new Enemy_BluePig(1, 1, sf::Vector2f(610, 225), 6);
	Enemy_BluePig *Pig12 = new Enemy_BluePig(1, 1, sf::Vector2f(410, 225), 6);

	BluePigsInMap.push_back(Pig1);
	BluePigsInMap.push_back(Pig2);
	BluePigsInMap.push_back(Pig3);
	BluePigsInMap.push_back(Pig4);
	BluePigsInMap.push_back(Pig5);
	BluePigsInMap.push_back(Pig6);
	BluePigsInMap.push_back(Pig7);
	BluePigsInMap.push_back(Pig8);
	BluePigsInMap.push_back(Pig9);
	BluePigsInMap.push_back(Pig10);
	BluePigsInMap.push_back(Pig11);
	BluePigsInMap.push_back(Pig12);
	BluePigsInMap.push_back(Pig13);
	BluePigsInMap.push_back(Pig14);
	BluePigsInMap.push_back(Pig15);
	BluePigsInMap.push_back(Pig16);
	BluePigsInMap.push_back(Pig17);
}
