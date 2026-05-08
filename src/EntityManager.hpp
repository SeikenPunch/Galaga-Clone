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
		void handleCollision();

		// Need to create draw function that draws all entities correctly
		void draw();
		bool isColliding(CollisionShape, CollisionShape);
		std::vector<std::unique_ptr<Entity>> entities;
		std::vector<std::unique_ptr<Entity>> bullets;
		Player player;
};