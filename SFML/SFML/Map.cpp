#include "Map.h"
#include <string>
#include <fstream>
#include <iostream>
#include "GraphicsUtils.h"
#include "Entity.h"

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

void Map::CheckPlayerCollisions(Player & player, sf::View &view, VictoryItem & VI)
{
	auto roomPlayerIsIn = rooms.at(player.getRoomId());

	//Initialize screen variables
	const int imageSize = 64;
	const sf::Vector2f ScreenSize = { imageSize * 15, imageSize * 8 };

	//Check all RoomPieces
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
			//CHECK IF COLLIDED WITH A Door
			if (RoomPiece->getSprite().getGlobalBounds().intersects(player.rectCollisionBot.getGlobalBounds()))
			{
				int lastIdRoom = player.getRoomId();
				player.SetRoomId(RoomPiece->getRoomId());

				GraphicsUtils::playSound(TransitionSound, TransitionSoundBuffer,"Music/Transition.wav",70,false);

				//MOVE TO THE CORRESPONDING ROOM
				if (lastIdRoom == 0)
				{
					switch (RoomPiece->getRoomId())
					{
					case 1:
						player.getSprite().setPosition(987, 418);
						break;
					case 4:
						player.getSprite().setPosition(103, 415);
						break;
					}
				}
				else if (lastIdRoom == 1)
				{
					switch (RoomPiece->getRoomId())
					{
					case 0:
						player.getSprite().setPosition(103, 224);
						break;
					case 2:
						player.getSprite().setPosition(730, 478);
						break;
					case 3:
						player.getSprite().setPosition(104, 352);
						break;
					}
				}
				else if (lastIdRoom == 2)
				{
					switch (RoomPiece->getRoomId())
					{
					case 1:
						player.getSprite().setPosition(863, 101);
						break;
					case 3:
						player.getSprite().setPosition(90, 94);
						break;
					}
				}
				else if (lastIdRoom == 3)
				{
					switch (RoomPiece->getRoomId())
					{
					case 1:
						player.getSprite().setPosition(983, 227);
						break;
					case 2:
						player.getSprite().setPosition(927, 166);
						break;
					case 4:
						player.getSprite().setPosition(806, 100);
						break;
					}
				}
				else if (lastIdRoom == 4)
				{
					switch (RoomPiece->getRoomId())
					{
					case 0:
						player.getSprite().setPosition(985, 158);
						break;
					case 3:
						player.getSprite().setPosition(803, 480);
						break;
					case 5:
						player.getSprite().setPosition(739, 98);
						break;
					}
				}
				else if (lastIdRoom == 5)
				{
					switch (RoomPiece->getRoomId())
					{
					case 4:
						player.getSprite().setPosition(793, 536);
						break;
					case 6:
						player.getSprite().setPosition(100, 224);
						break;
					}
				}
				else if (lastIdRoom == 6)
				{
					if (player.getRoomId() == 5)
					{
						player.getSprite().setPosition(928, 285);
					}
				}
				
				//MOVE CAMERA IF NEEDED
				//MOVE TO THE CORRESPONDING ROOM
				if (player.getRoomId() == 0)
				{
					view.setCenter(ScreenSize.x / 2 + imageSize, ScreenSize.y / 2);
				}
				else if (player.getRoomId() == 1)
				{
					view.setCenter(ScreenSize.x / 2 + imageSize, ScreenSize.y / 2 + imageSize);

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

				//player.getSprite().setPosition(250, 250);
				
			}
		}
	}

	if (player.getSprite().getGlobalBounds().intersects(VI.getSprite().getGlobalBounds()) && player.getRoomId() == VI.getRoomSpawnedId())
	{
		player.PlayerWonTheGame = true; 
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
