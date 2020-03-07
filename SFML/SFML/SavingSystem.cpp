#include "SavingSystem.h"
#include <fstream>
SavingSystem::SavingSystem()
{
	
}

//Give player and file as parameter to save all the data 
void SavingSystem::SaveGame(Player & player)
{
	std::ofstream myfile;

	myfile.open("SaveFile.txt");

	myfile << player.getSprite().getPosition().x << std::endl;

	myfile << player.getSprite().getPosition().y << std::endl;

	myfile << player.getRoomId() << std::endl;

	myfile.close();
}

void SavingSystem::ChecIfPlayedBefore(Player & ent, sf::View &view)
{
	std::ifstream myfile("SaveFile.txt");

	bool fileFound = false;

	//Initialize screen variables
	const int imageSize = 64;
	const sf::Vector2f ScreenSize = { imageSize * 15, imageSize * 8 };

	std::vector<std::string> allInfo;
	std::string line;
	if (myfile.is_open())
	{
		while (std::getline(myfile, line))
		{
			allInfo.push_back(line);
		}
		fileFound = true;
	}
	myfile.close();

	if (fileFound == true)
	{

		float PosX = 0;
		float PosY = 0;
		int id = 0;
		for (int i = 0; i < allInfo.size(); ++i)
		{
			switch (i)
			{
				//Position X player
			case 0:
				PosX = std::stof(allInfo[i]);
				break;
			case 1:
				PosY = std::stof(allInfo[i]);
				break;
			case 2:
				ent.SetRoomId(std::stoi(allInfo[i]));
				break;
			}
		}

		ent.getSprite().setPosition(PosX, PosY);

		if (ent.getRoomId() == 0)
		{
			view.setCenter(ScreenSize.x / 2 + imageSize, ScreenSize.y / 2);
		}
		else if (ent.getRoomId() == 1)
		{
			view.setCenter(ScreenSize.x / 2 + imageSize, ScreenSize.y / 2 + imageSize);

		}
		else if (ent.getRoomId() == 2)
		{
			view.setCenter(ScreenSize.x / 2, ScreenSize.y / 2);
		}
		else if (ent.getRoomId() == 3)
		{
			view.setCenter(ScreenSize.x / 2 + imageSize, ScreenSize.y / 2);
		}
		else if (ent.getRoomId() == 4)
		{
			view.setCenter(ScreenSize.x / 2 + imageSize, ScreenSize.y / 2 + imageSize);
		}
		else if (ent.getRoomId() == 5)
		{
			view.setCenter(ScreenSize.x / 2, ScreenSize.y / 2 + imageSize);
		}
		else if (ent.getRoomId() == 6)
		{
			view.setCenter(ScreenSize.x / 2 + imageSize, ScreenSize.y / 2);
		}


	}
	else
	{
		ent.getSprite().setPosition(ScreenSize.x / 2, ScreenSize.y / 2);
	}

}
