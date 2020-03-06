#include "VictoryItem.h"

VictoryItem::VictoryItem(const sf::Vector2f PositionItem) : Entity("Art/RedCrystal.png")
{
	PositionToSpawn = { PositionItem.x / 1.14f,PositionItem.y / 2.4f };

	spr_entity.setPosition(PositionToSpawn);

	 roomSpawned = 6;
}
