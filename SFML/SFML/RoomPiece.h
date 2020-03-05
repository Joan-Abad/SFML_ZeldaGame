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
	void setRoomId(int newIDRoom);

private: 

	//Graphics
	sf::Sprite spr_RoomPiece;
	sf::Texture tex_RoomPiece;

	//Type
	RoomPieceTypes roomPieceType; 
	
	//-1 means it doesn't move you to another room
	int idRoom = -1; 
};

