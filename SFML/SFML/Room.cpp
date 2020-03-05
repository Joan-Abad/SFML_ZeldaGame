#include "Room.h"
#include <iostream>
#include "GraphicsUtils.h"
Room::Room(std::ifstream &roomFile)
{
	sf::Vector2f RoomPiecePosition = { 0,0 };
	//If file opens
	if (roomFile.is_open())
	{
		
		std::string line;
		int counterHeight = 0;

		//read file
		while (std::getline(roomFile, line))
		{
			// Get Room length
			roomSize.RoomLength = line.length();

			counterHeight++;

			// Go all over the line get from the file
			for(std::string::iterator it = line.begin(); it != line.end(); ++it)
			{
				//String necessary for adding to vector and register all map content
				std::string letter; 
				letter = *it;
				
				//string address for getting the art
				std::string spriteAddress;

				//Map content
				mapContent.push_back(letter);

				//Set art
				if (letter == "#")
				{
					spriteAddress = "Art/Wall.jpg";
				}
				else
				{
					spriteAddress = "Art/Floor.jpg";
				}

				//Set new Room Piece
				RoomPieces *roomPiece = new RoomPieces(spriteAddress);
				roomPiece->getSprite().setPosition(RoomPiecePosition);

				//Set room piece type
				if (letter == "#")
				{
					roomPiece->setRoomPieceType(RoomPieceTypes::Wall);
				}
				else if (letter == "0")
				{
					roomPiece->setRoomId(0);
					roomPiece->setRoomPieceType(RoomPieceTypes::Door);
				}
				else if(letter == "1")
				{
					roomPiece->setRoomId(1);
					roomPiece->setRoomPieceType(RoomPieceTypes::Door);
				}
				else if (letter == "2")
				{
					roomPiece->setRoomPieceType(RoomPieceTypes::Door);
					roomPiece->setRoomId(2);
				}
				else if (letter == "3")
				{
					roomPiece->setRoomPieceType(RoomPieceTypes::Door);
					roomPiece->setRoomId(3);
				}
				else if (letter == "4")
				{
					roomPiece->setRoomPieceType(RoomPieceTypes::Door);
					roomPiece->setRoomId(4);
				}
				else if (letter == "5")
				{
					roomPiece->setRoomPieceType(RoomPieceTypes::Door);
					roomPiece->setRoomId(5);
				}
				else if (letter == "6")
				{
					roomPiece->setRoomPieceType(RoomPieceTypes::Door);
					roomPiece->setRoomId(6);
				}
				else if (letter == ".")
				{
					roomPiece->setRoomPieceType(RoomPieceTypes::Floor);
				}
				else
				{
					roomPiece->setRoomPieceType(RoomPieceTypes::none);
				}
				
				vecRoomPieces.push_back(roomPiece);	
				

				//Move next Room piece to the right
				RoomPiecePosition.x += 64;
			}

			//Set new lane Room piece position
			RoomPiecePosition.y += 64;
			RoomPiecePosition.x = 0;
		}

		// Get Room Height
		roomSize.RoomHeight = counterHeight;

		roomFile.close();
	}
}

void Room::GenerateMap()
{
	
}
