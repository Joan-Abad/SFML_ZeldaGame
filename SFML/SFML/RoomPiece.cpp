#include "RoomPiece.h"
#include "GraphicsUtils.h"
RoomPieces::RoomPieces(const std::string SpriteAddress)
{
	spr_RoomPiece.setTexture(GraphicsUtils::InitializeSprite(tex_RoomPiece, SpriteAddress));
	roomPieceType = RoomPieceTypes::none;
}

void RoomPieces::setRoomPieceType(RoomPieceTypes roomPieceType)
{
	this->roomPieceType = roomPieceType;
}
//-1 means no room to tp
void RoomPieces::setRoomId(int newIDRoom)
{
	idRoom = newIDRoom;
}
