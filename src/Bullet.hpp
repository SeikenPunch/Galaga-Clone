#pragma once

#include <raylib.h>
#include "Utils.hpp"
#include "Entity.hpp"

class Bullet : public Entity{
	public:
		Bullet();
		void update();
		
	private:
		Vector2 movementVec = {0,-1};
		void moveBullet();
};
