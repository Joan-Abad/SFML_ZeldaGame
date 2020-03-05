#pragma once
#include "Room.h"
#include <map>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "sfml/Audio.hpp"
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

	void CheckPlayerCollisions(Player &player, sf::View &view);

	void RememberPlayerStuffWhenDisconect();


private: 

	void CreateRooms();
	std::map<int, Room*> rooms;

	sf::Sound TransitionSound;
	sf::SoundBuffer TransitionSoundBuffer;
};

