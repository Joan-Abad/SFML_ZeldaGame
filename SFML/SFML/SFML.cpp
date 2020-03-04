#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"
#include <iostream>
#include "Entity.h"

int main()
{
	//Create the map
	Map map; 
	Player ent;
	//Entity enemy("Art/Soldier.png");
	//enemy.getSprite().setPosition(300.f, 300.f);

	const int imageSize = 64;
	const sf::Vector2f ScreenSize = { imageSize * 15, imageSize * 8 };
	ent.getSprite().setPosition(ScreenSize.x/ 2, ScreenSize.y / 2);

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
		ent.PlayerFunctionality(event,map);

		window.clear();
		map.DrawRooms(window);
		window.draw(ent.getSprite());
		window.display();
	}

	return 0;
}