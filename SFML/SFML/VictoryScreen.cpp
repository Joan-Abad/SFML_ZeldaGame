#include "VictoryScreen.h"
#include "GraphicsUtils.h"

VictoryScreen::VictoryScreen(const sf::Vector2f &ScreenSize)
{
	spr_Background.setTexture(GraphicsUtils::InitializeSprite(tex_Background,"Art/bacgrkoundVictory.jpg"));
	spr_Background.setPosition(0,0);
	spr_Victory.setTexture(GraphicsUtils::InitializeSprite(tex_Victory, "Art/Win.png"));
	spr_Victory.setPosition(ScreenSize.x /2.75f, ScreenSize.y / 4);
}

void VictoryScreen::DrawVictoryScreen(sf::RenderWindow & window)
{
	window.draw(spr_Background);
	window.draw(spr_Victory);
}
