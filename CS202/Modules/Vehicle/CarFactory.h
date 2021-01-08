#pragma once

#include "VehicleInterface.h"
#include "Car.h"
#include "Car2.h"
#include "Police_car.h"
#include "Dog.h"
#include "Dinosaur.h"
#include "Tree.h"
#include "Truck.h"
enum class VehicleCateglory
{
	car,
	car2,
	police_car,
	dinosaur,
	dog,
	truck,
	last
};

class CarFactory
{
public:
	static VehicleInterface *getRandom();
};