#include "Map.h"
#include <string>
#include <fstream>
#include <iostream>
Map::Map()
{
	CreateRooms();
}

void Map::DrawRooms(sf::RenderWindow & window)
{
	for (auto room : rooms)
	{
		for (auto roomPiece : room.second->vecRoomPieces)
		{
			window.draw(roomPiece->getSprite());
		}
		std::cout << "Drawing\n";
	}
}

void Map::CreateRooms()
{
	bool CreateRoom = true;
	int roomCounter = 0;
	std::string str_room = "room_02.txt";

	while (CreateRoom == true)
	{
		//Open file
		std::ifstream roomFile(str_room);

		//If file could be open
		if (roomFile.is_open())
		{
			//Create new room
			Room * room = new Room(roomFile);

			//add room to rooms map
			rooms.insert(std::make_pair(roomCounter, room));
			std::cout << std::endl;

			//iterator of the room
			auto a = rooms.find(roomCounter);

			int counterMapLength = 1;

			roomFile.close();
			CreateRoom = false;
			
		}
		//If file wasn't found
		else
		{
			//Stop creating rooms
			CreateRoom = false;
		}
	}


	
}
