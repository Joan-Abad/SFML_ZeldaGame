#pragma once
#include "SFML/Graphics.hpp"

enum RoomPieceTypes
{
	Wall, 
	Floor, 
	Enemy, 
	none
};

class RoomPieces
{
public: 
	//Constructor
	RoomPieces(const std::string SpriteAddress);

	//Getters
	sf::Sprite &getSprite() { return spr_RoomPiece; };
	sf::Texture &getTexture() { return tex_RoomPiece; };
	RoomPieceTypes &getRoomPieceType (){ return roomPieceType; };

	//setters
	void setRoomPieceType(RoomPieceTypes roomPieceType);

private: 

	//Graphics
	sf::Sprite spr_RoomPiece;
	sf::Texture tex_RoomPiece;

	//Type
	RoomPieceTypes roomPieceType; 
};

