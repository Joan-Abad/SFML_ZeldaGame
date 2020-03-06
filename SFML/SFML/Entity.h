#pragma once
#include "SFML/Graphics.hpp"

class Entity
{
public: 
	Entity(std::string imageAddress);

	//Getters
	sf::Sprite &getSprite() { return spr_entity; };

	int &getRoomSpawnedId() { return roomSpawned; };

private:

protected: 

	//Graphics
	sf::Texture tex_entity;
	sf::Sprite spr_entity;

	//Initi values
	float speed; 
	bool alive;

	int roomSpawned;


};

