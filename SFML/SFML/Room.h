#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Map.h"
#include "RoomPiece.h"
#include "SFML/Graphics.hpp"

class Map;

struct RoomSize
{
	int RoomLength;
	int RoomHeight;
};


class Room
{

public:
	//Constructor
	Room(std::ifstream &roomFile);

	//Getters
	std::vector <std::string> &getMapContent() { return mapContent;};
	RoomSize &getRoomSize() { return roomSize; };

	std::vector <RoomPieces*> vecRoomPieces;

private: 
	//Variables
	std::vector <std::string> mapContent;

	RoomSize roomSize;

	//Functions
	void GenerateMap();


};

