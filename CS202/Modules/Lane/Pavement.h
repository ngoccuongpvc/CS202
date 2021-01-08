#pragma once
#include "LaneInterface.h"

class Pavement : public LaneInterface {
public:
	void initialize();
	Pavement(int x);
	void update();
	void playStreetSound(People& p);
};
