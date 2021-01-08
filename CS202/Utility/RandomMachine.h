#pragma once

#include <time.h>
#include <random>

int random()
{
	std::random_device rd;
	std::uniform_int_distribution<int> dist(0, RAND_MAX);
	return dist(rd);
}

int random(int minN, int maxN) {
	std::random_device rd;
	std::uniform_int_distribution<int> dist(minN, maxN);
	return dist(rd);
}

float randomSpeed(int level)
{
	return static_cast<float>(5000 + level * 2000 + random(0, 5000)) / RAND_MAX;
}

float randomDist(int level)
{
	int mod = std::max(500 - level * 40, 100);
	return static_cast<float>(random() % mod);
}

