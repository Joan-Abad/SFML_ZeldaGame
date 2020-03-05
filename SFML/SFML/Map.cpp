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

void Map::CheckPlayerCollisions(Player & player, sf::View &view)
{
	auto roomPlayerIsIn = rooms.at(player.getRoomId());

	//Initialize screen variables
	const int imageSize = 64;
	const sf::Vector2f ScreenSize = { imageSize * 15, imageSize * 8 };

	for (auto RoomPiece : roomPlayerIsIn->vecRoomPieces)
	{
		if( RoomPiece->getRoomPieceType() == Wall)
		{
			//IF COLIDES WITH WALL, CHECK WHICH PART COLLIDED
			if (RoomPiece->getSprite().getGlobalBounds().intersects(player.rectCollisionLeft.getGlobalBounds()))
			{
				player.canMoveLeft = false;
			}
			if (RoomPiece->getSprite().getGlobalBounds().intersects(player.rectCollisionRight.getGlobalBounds()))
			{
				player.canMoveRight = false;
			}
			if (RoomPiece->getSprite().getGlobalBounds().intersects(player.rectCollisionTop.getGlobalBounds()))
			{
				player.canMoveUp = false;
			}
			if (RoomPiece->getSprite().getGlobalBounds().intersects(player.rectCollisionBot.getGlobalBounds()))
			{
				player.canMoveDown = false;
			}
		}
		if (RoomPiece->getRoomPieceType() == Door)
		{
			//CHECK IF COLLIDED WITH A WALL
			if (RoomPiece->getSprite().getGlobalBounds().intersects(player.rectCollisionBot.getGlobalBounds()))
			{
				player.SetRoomId(RoomPiece->getRoomId());

				if (player.getRoomId() == 0)
				{
					view.setCenter(ScreenSize.x/2 + imageSize, ScreenSize.y/2);
				}
				else if (player.getRoomId() == 1)
				{
					view.setCenter(ScreenSize.x/2 + imageSize, ScreenSize.y/2 + imageSize);
				}
				else if (player.getRoomId() == 2)
				{
					view.setCenter(ScreenSize.x / 2, ScreenSize.y / 2);
				}
				else if (player.getRoomId() == 3)
				{
					view.setCenter(ScreenSize.x / 2 + imageSize, ScreenSize.y / 2);
				}
				else if (player.getRoomId() == 4)
				{
					view.setCenter(ScreenSize.x / 2 + imageSize, ScreenSize.y / 2 + imageSize);
				}
				else if (player.getRoomId() == 5)
				{
					view.setCenter(ScreenSize.x / 2, ScreenSize.y / 2 + imageSize);
				}
				else if (player.getRoomId() == 6)
				{
					view.setCenter(ScreenSize.x / 2 + imageSize, ScreenSize.y / 2);
				}
				player.getSprite().setPosition(250,250);
			}
		}
	}
}

void Map::CreateRooms()
{
	int roomCounter = 0;
	std::vector<std::string> roomsToRead;
	const int NumberOfRooms = 7;

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
