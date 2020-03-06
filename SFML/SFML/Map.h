#pragma once
#include "Room.h"
#include <map>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "SFML/Audio.hpp"
#include "VictoryItem.h"

class Room;
class Player;

class Map
{

public: 
	Map();
	
	//Draws
	void DrawRooms(sf::RenderWindow &window,Player &player);

	//Getters
	std::map<int, Room*> &getRoomsOnMap() { return rooms; };

	void CheckPlayerCollisions(Player &player, sf::View &view, VictoryItem & VI);

private: 

	void CreateRooms();
	std::map<int, Room*> rooms;

	sf::Sound TransitionSound;
	sf::SoundBuffer TransitionSoundBuffer;
};

