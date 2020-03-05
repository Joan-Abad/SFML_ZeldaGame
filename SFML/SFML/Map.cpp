#include "Map.h"
#include <string>
#include <fstream>
#include <iostream>
Map::Map()
{
	CreateRooms();
}

void Map::DrawRooms(sf::RenderWindow & window,Player &player)
{

	for (auto actualRoom : rooms.at(player.getRoomId())->vecRoomPieces)
	{
		window.draw(actualRoom->getSprite());
	}
}

void Map::CheckPlayerCollisions(Player & player)
{
	auto roomPlayerIsIn = rooms.at(player.getRoomId());

	for (auto RoomPiece : roomPlayerIsIn->vecRoomPieces)
	{
		if (RoomPiece->getSprite().getGlobalBounds().intersects(player.rectCollisionLeft.getGlobalBounds()) && RoomPiece->getRoomPieceType() == Wall)
		{
			player.canMoveLeft = false;
			std::cout << "\nToching Wall";
		}
		if (RoomPiece->getSprite().getGlobalBounds().intersects(player.rectCollisionRight.getGlobalBounds()) && RoomPiece->getRoomPieceType() == Wall)
		{
			player.canMoveRight = false;
			std::cout << "\nToching Wall";
		}
		if (RoomPiece->getSprite().getGlobalBounds().intersects(player.rectCollisionTop.getGlobalBounds()) && RoomPiece->getRoomPieceType() == Wall)
		{
			player.canMoveUp = false;
			std::cout << "\nToching Wall";
		}
		if (RoomPiece->getSprite().getGlobalBounds().intersects(player.rectCollisionBot.getGlobalBounds()) && RoomPiece->getRoomPieceType() == Wall)
		{
			player.canMoveDown = false;
			std::cout << "\nToching Wall";
		}
	}
}

void Map::CreateRooms()
{
	int roomCounter = 0;
	std::vector<std::string> roomsToRead;
	const int NumberOfRooms = 2;

	//Create all the texts for opening the files
	for (int i = 0; i < NumberOfRooms; i++)
	{
		std::string rooms = "room_0";
		std::string number = std::to_string(i);
		rooms += number;
		rooms += ".txt";
		roomsToRead.push_back(rooms);
	}
	//Open the files
	for (int i = 0; i < roomsToRead.size(); ++i)
	{
		std::cout << "Room: " << i << "\n\n\n\n\n";
		//Open file
		std::ifstream roomFile(roomsToRead[i]);

		//If file was found and could be open
		if (roomFile.is_open())
		{
			//Create new room
			Room * room = new Room(roomFile);

			//add room to rooms map
			rooms.insert(std::make_pair(roomCounter, room));
			std::cout << std::endl;

			//close file and sum id room counter. 
			roomFile.close();
			roomCounter++;
		}
	}

	


	
}
