#pragma once

#include "VehicleInterface.h"
#include "Car.h"
#include "Car2.h"
#include "Police_car.h"
#include "Dog.h"
#include "Dinosaur.h"
#include "Tree.h"
enum class VehicleCateglory
{
	car,
	car2,
	tree,
	police_car,
	dinosaur,
	dog,
	last
};

class CarFactory
{
public:
	static VehicleInterface* getRandom() {
		VehicleCateglory type = static_cast<VehicleCateglory>(rand() % static_cast<int>(VehicleCateglory::last));

		switch (type) {
		case VehicleCateglory::car:
			return new Car();
		case VehicleCateglory::car2:
			return new Car2();
		case VehicleCateglory::tree:
			return new Tree();
		case VehicleCateglory::police_car:
			return new Police_car();
		case VehicleCateglory::dinosaur:
			return new Dinosaur();
		case VehicleCateglory::dog:
			return new Dog();
		default:
			throw "Undefined vehicle";
		}
	}
};