#pragma once
#include "Room.h"
#include <map>
#include "SFML/Graphics.hpp"
class Room;

class Map
{

public: 
	Map();
	std::map<int, Room*> rooms;	
	void DrawRooms(sf::RenderWindow &window);

private: 
	void CreateRooms();
};

