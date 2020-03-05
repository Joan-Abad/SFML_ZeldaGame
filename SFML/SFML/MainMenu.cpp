#include "MainMenu.h"
#include "GraphicsUtils.h"
MainMenu::MainMenu(const sf::Vector2f ScreenSize)
{
	spr_Background.setTexture(GraphicsUtils::InitializeSprite(tex_Background,"Art/background.jpg"));
	spr_Play.setTexture(GraphicsUtils::InitializeSprite(tex_Play, "Art/New Game.png"));
	spr_Continue.setTexture(GraphicsUtils::InitializeSprite(tex_Continue, "Art/Continue.png"));
	spr_Exit.setTexture(GraphicsUtils::InitializeSprite(tex_Exit, "Art/Exit.png"));

	spr_Play.setPosition(ScreenSize.x/2 - GraphicsUtils::spriteSize(spr_Play).x/2,ScreenSize.y/5);
	spr_Continue.setPosition(ScreenSize.x / 2 - GraphicsUtils::spriteSize(spr_Play).x / 2, ScreenSize.y / 2.5f);
	spr_Exit.setPosition(ScreenSize.x / 2 - GraphicsUtils::spriteSize(spr_Play).x / 2, ScreenSize.y / 1.65f);
}

void MainMenu::DrawMainMenu(sf::RenderWindow & window)
{
	window.draw(spr_Background);
	window.draw(spr_Play);
	window.draw(spr_Continue);
	window.draw(spr_Exit);
}
