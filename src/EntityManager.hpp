#pragma once

#include <vector>
#include <memory>
#include "Player.hpp"

#include "Alien.hpp"


class EntityManager{
	public:
		void addEntity(std::unique_ptr<Entity>);
		void update();

	private:
		void handleCollision(Player p);
		void handleCollision(Bullet b);
		std::vector<std::unique_ptr<Entity>> entities;
};