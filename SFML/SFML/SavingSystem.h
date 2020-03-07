#pragma once
#include "Player.h"
#include <fstream>

class SavingSystem
{
public: 
	SavingSystem();
	static void SaveGame(Player & player);
	void ChecIfPlayedBefore(Player & ent, sf::View &view);

private: 
	const std::string fileAddress;

};

