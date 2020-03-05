#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"
#include <iostream>
#include "Entity.h"
#include "Bullet.h"

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
	

	//While window is open
	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
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