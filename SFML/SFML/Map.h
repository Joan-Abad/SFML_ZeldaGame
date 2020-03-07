#pragma once
#include "Room.h"
#include <map>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "SFML/Audio.hpp"
#include "VictoryItem.h"
#include "GlobalVariables.h"

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

	void CheckPlayerCollisions(Player &player, sf::View &view, VictoryItem & VI, E_GameState &gameState);
	std::map<int, Room*> rooms;

	void CheckAICollision(std::vector<Entity> &AIOnRoom, Player &player);

private: 

	void CreateRooms();

	sf::Sound TransitionSound;
	sf::SoundBuffer TransitionSoundBuffer;
};

