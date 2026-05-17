#pragma once

#include <raylib.h>
#include "Clock.hpp"
#include "Bullet.hpp"
#include "Entity.hpp"

class Player : public Entity{
	public:
		Player();
		~Player() override = default;
		void update();
		void setBounds(float leftBound, float rightBound, float topBound, float bottomBound);
		bool canShoot();
		Bullet shoot();

	private:
		Clock clock;
		float shootTime = 500;
		float leftBound, rightBound, topBound, bottomBound = 0;
};