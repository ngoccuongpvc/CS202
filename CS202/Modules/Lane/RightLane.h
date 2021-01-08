#pragma once
#include "LaneInterface.h"

class RightLane : public LaneInterface
{
public:
	RightLane(int x);
	void initialize();
	void update();
	void playStreetSound(People& p);
};
