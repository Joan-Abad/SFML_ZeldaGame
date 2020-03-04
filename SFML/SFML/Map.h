#pragma once
#include "Room.h"
#include <map>
#include "SFML/Graphics.hpp"
class Room;

class Map
{

public: 
	Map();
	
	//Draws
	void DrawRooms(sf::RenderWindow &window);

	//Getters
	std::map<int, Room*> &getRoomsOnMap() { return rooms; };


private: 

	void CreateRooms();
	std::map<int, Room*> rooms;
};

