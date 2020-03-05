#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"
#include <iostream>
#include "Entity.h"
#include "Bullet.h"
#include <fstream>
#include <iostream>

void SaveFile(Player &ent);
void ChecIfPlayedBefore(Player &ent, sf::View &view);

int main()
{

	//Create the map
	Map map; 


	//Initialize screen variables
	const int imageSize = 64;
	const sf::Vector2f ScreenSize = { imageSize * 15, imageSize * 8 };

	sf::View view(sf::Vector2f((ScreenSize.x/2) + imageSize,ScreenSize.y/2), sf::Vector2f(ScreenSize.x, ScreenSize.y));

	//Create the player
	Player ent(ScreenSize);

	//Create the window
	sf::RenderWindow window(sf::VideoMode(ScreenSize.x,ScreenSize.y), "SFML Game!");
	
	//Check if game was played before
	ChecIfPlayedBefore(ent,view);

	//While window is open
	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				SaveFile(ent);

				window.close();
			}
		}

		//Player functionality
		ent.PlayerFunctionality(event,map);

		map.CheckPlayerCollisions(ent,view);

		//Window draw stuff
		window.clear();
		map.DrawRooms(window,ent);
		window.setView(view);
		ent.drawPlayer(window);
		window.display();
	}

	return 0;
}

void SaveFile(Player &ent)
{
	std::ofstream myfile;
	myfile.open("SaveFile.txt");

	myfile << ent.getSprite().getPosition().x << std::endl;

	myfile << ent.getSprite().getPosition().y << std::endl;

	myfile << ent.getRoomId() << std::endl;

	myfile.close();
}

void ChecIfPlayedBefore(Player & ent, sf::View &view)
{
	std::ifstream myfile("SaveFile.txt");
	
	std::vector<std::string> allInfo;
	std::string line;
	if (myfile.is_open())
	{
		while (std::getline(myfile, line))
		{
			allInfo.push_back(line);
		}
	}

	float PosX = 0;
	float PosY = 0;
	int id = 0;
	for (int i = 0; i < allInfo.size(); ++i)
	{
		switch (i)
		{
			//Position X player
		case 0: 
			PosX = std::stof(allInfo[i]);
			break;
		case 1: 
			PosY = std::stof(allInfo[i]);
			break;
		case 2: 
			ent.SetRoomId(std::stoi(allInfo[i]));
			break;
		}
	}

	ent.getSprite().setPosition(PosX,PosY);

	//Initialize screen variables
	const int imageSize = 64;
	const sf::Vector2f ScreenSize = { imageSize * 15, imageSize * 8 };


	if (ent.getRoomId() == 0)
	{
		view.setCenter(ScreenSize.x / 2 + imageSize, ScreenSize.y / 2);
	}
	else if (ent.getRoomId() == 1)
	{
		view.setCenter(ScreenSize.x / 2 + imageSize, ScreenSize.y / 2 + imageSize);

	}
	else if (ent.getRoomId() == 2)
	{
		view.setCenter(ScreenSize.x / 2, ScreenSize.y / 2);
	}
	else if (ent.getRoomId() == 3)
	{
		view.setCenter(ScreenSize.x / 2 + imageSize, ScreenSize.y / 2);
	}
	else if (ent.getRoomId() == 4)
	{
		view.setCenter(ScreenSize.x / 2 + imageSize, ScreenSize.y / 2 + imageSize);
	}
	else if (ent.getRoomId() == 5)
	{
		view.setCenter(ScreenSize.x / 2, ScreenSize.y / 2 + imageSize);
	}
	else if (ent.getRoomId() == 6)
	{
		view.setCenter(ScreenSize.x / 2 + imageSize, ScreenSize.y / 2);
	}

	std::cout << "sda";
}
