#pragma once
#include "SFML/Graphics.hpp"
class RoomPieces
{
public: 
	RoomPieces(const std::string SpriteAddress);
	sf::Sprite &getSprite() { return spr_RoomPiece; };
	sf::Texture &getTexture() { return tex_RoomPiece; };
private: 
	sf::Sprite spr_RoomPiece;
	sf::Texture tex_RoomPiece;
};

