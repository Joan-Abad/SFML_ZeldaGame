#include "Entity.h"
#include "GraphicsUtils.h"

Entity::Entity(std::string imageAddress)
{
	spr_entity.setTexture(GraphicsUtils::InitializeSprite(tex_entity, imageAddress));
}


