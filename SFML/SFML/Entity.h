#pragma once
#include "SFML/Graphics.hpp"
class Entity
{
public: 
	Entity();

private:

protected: 

	//Graphics
	sf::Texture tex_entity;
	sf::Sprite spr_entity;

	//Initi values
	float speed; 
	bool alive;
};

