#include <SFML/Graphics.hpp>
#include "RoomPiece.h"
#include "Map.h"
#include <iostream>
int main()
{
	Map map; 

	RoomPieces rp("Art/Floor.jpg");

	sf::RenderWindow window(sf::VideoMode(960, 512), "SFML Game!");


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		map.DrawRooms(window);
		//window.draw(rp.getSprite());
		window.display();
	}

	return 0;
}