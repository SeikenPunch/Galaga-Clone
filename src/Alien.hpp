#pragma once

#include "raylib.h"
#include "Entity.hpp"

class Alien : public Entity{
	public:
		Alien();
		~Alien() = default;
		void update() override;
		void attack(Vector2 position);
};
