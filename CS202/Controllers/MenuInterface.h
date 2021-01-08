#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "../Modules/Button/ButtonInterface.h"
#include "../Modules/Button/NewGameButton.h"
#include "../Modules/Button/LoadGameButton.h"
#include "../Modules/Button/ExitGameButton.h"
#include "../Modules/Button/SaveGameButton.h"
#include "../Modules/Button/ContinueGameButton.h"



class MenuInterface
{
protected:
	std::vector<ButtonInterface*> buttons;
public:
	virtual void showMenu() = 0;
};