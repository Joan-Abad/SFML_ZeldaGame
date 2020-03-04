#include "RoomPiece.h"
#include "GraphicsUtils.h"
RoomPieces::RoomPieces(const std::string SpriteAddress)
{
	spr_RoomPiece.setTexture(GraphicsUtils::InitializeSprite(tex_RoomPiece, SpriteAddress));

}
