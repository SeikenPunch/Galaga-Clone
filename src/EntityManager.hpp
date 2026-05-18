#pragma once

#include <vector>
#include <memory>
#include "Player.hpp"
#include "Bullet.hpp"

#include "Alien.hpp"


const int spriteScale = 3;


class EntityManager{
	public:
		void start(int screenWidth, int screenHeight);
		void addEntity(std::unique_ptr<Entity>);
		void addBullet(std::unique_ptr<Entity>);
		void update();
		void draw();
		void handleMovement();

	private:
		void handleCollision();
		bool isColliding(CollisionShape, CollisionShape);
		std::vector<std::unique_ptr<Entity>> entities;
		std::vector<std::unique_ptr<Entity>> bullets;

		void setupGrid();
		std::vector<Vector2> grid;
		int gridSize = 10;
		Texture2D bulletTexture;
		std::unique_ptr<Player> player;
};

// CELL METHOD
// Have grid of aliens
// Have aliens assigned to grid x,y
// Have aliens go to there location
// Have grid move around when aliens that can be assigned are
