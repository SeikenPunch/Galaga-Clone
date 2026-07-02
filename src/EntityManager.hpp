#pragma once

#include <vector>
#include <memory>
#include "Player.hpp"
#include "Bullet.hpp"
#include "AlienInfo.hpp"
#include "Aliens.hpp"

const int spriteScale = 3;

class EntityManager{
	public:
		void start(int screenWidth, int screenHeight);
		void addEntity(std::unique_ptr<Entity>);
      void getEntities(std::vector<Entity> entities);
		void addBullet(std::unique_ptr<Entity>);
		void update();
		void draw();
		void handleMovement();
      void setPlacement(std::vector<GridInfo> newPlacement);

	private:
		void handleCollision();
		bool isColliding(CollisionShape, CollisionShape);
		std::vector<std::unique_ptr<Entity>> entities;
		std::vector<std::unique_ptr<Entity>> bullets;
		Texture2D bulletTexture;
		std::unique_ptr<Player> player;
      std::vector<GridInfo> alienPlacement;

      // Make a function called createGroup that takes a vector of entities and rows and columns of group and top left position of group. returns id?
};
