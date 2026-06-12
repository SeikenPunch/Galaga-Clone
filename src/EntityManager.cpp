#include <cstdint>
#include <iostream> // Debug
#include "EntityManager.hpp"
#include "Collision.hpp"

void EntityManager::start(int VirtualScreenWidth, int VirtualScreenHeight){
	float leftBound = 25;
	float rightBound = VirtualScreenWidth - 25;
	float topBound = VirtualScreenHeight - 200;
	float bottomBound = VirtualScreenHeight - 25;

	player = std::make_unique<Player>();

	player->setPosition({VirtualScreenWidth/2.f, (bottomBound + topBound) / 2});
	player->setBounds(leftBound, rightBound, topBound, bottomBound);

	SetTextureFilter(player->getTexture(), TEXTURE_FILTER_POINT);
}

void EntityManager::addEntity(std::unique_ptr<Entity> entity){
	entities.push_back(std::move(entity));
}

void EntityManager::addBullet(std::unique_ptr<Entity> b){
	b->getSpeed();
	bullets.push_back(std::move(b));
}

void EntityManager::update(){
	handleMovement();
	handleCollision();
	player->update();
	
	for(uint32_t i = 0; i < entities.size(); i++){
		entities[i]->update();

		if(entities[i]->isDead()){
			entities.erase(entities.begin() + i);
		}
	}

	for(uint32_t i = 0; i < bullets.size(); i++){
		bullets[i]->update();

		if(bullets[i]->getPosition().y < 10){
			bullets[i]->kill();
		}
		if(bullets[i]->isDead()){
			bullets.erase(bullets.begin() + i);
		}
	}
}

bool EntityManager::isColliding(CollisionShape body_1, CollisionShape body_2){
	bool x_col = false;	// Collision along X axis
	bool y_col = false;	// Collision along Y axis

	// Get X collision
	if(body_1.originPosition.x + (body_1.width / 2) > body_2.originPosition.x - (body_2.width / 2) &&
		body_1.originPosition.x - (body_1.width / 2) < body_2.originPosition.x + (body_2.width / 2)){
		
		x_col = true;
	}

	// Get Y collision
	if(body_1.originPosition.y + (body_1.height / 2) > body_2.originPosition.y - (body_2.height / 2) && 
		body_1.originPosition.y - (body_1.height / 2) < body_2.originPosition.y + (body_2.height / 2)){
		
		y_col = true;
	}

	if(x_col && y_col){
		return true;
	}

	return false;
}

void EntityManager::draw(){

	// Draw entities
	for(uint32_t i = 0; i < entities.size(); i++){
		DrawTexturePro(
			// Texture
			entities[i]->getTexture(),

			// Rectangle Source
			{0, 0, (float)entities[i]->getTexture().width, (float)entities[i]->getTexture().height},

			// Rectangle Destination
			{
				entities[i]->getPosition().x, entities[i]->getPosition().y,
				(float)entities[i]->getTexture().width * spriteScale,
				(float)entities[i]->getTexture().height * spriteScale
			},

			// Vector2 Origin
			{
				((float)entities[i]->getTexture().width * spriteScale) / 2.f,
				((float)entities[i]->getTexture().height * spriteScale) / 2.f
			},

			// Rotation
			entities[i]->getRotation(),

			// Color 
			WHITE
		); 
	}

	// Draw Bullets
	for(uint32_t i = 0; i < bullets.size(); i++){

		DrawTexturePro(
			// Texture
			bullets[i]->getTexture(),

			// Rectangle Source
			{0, 0, (float)bullets[i]->getTexture().width, (float)bullets[i]->getTexture().height},

			// Rectangle Destination
			{
				bullets[i]->getPosition().x, bullets[i]->getPosition().y,
				(float)bullets[i]->getTexture().width * spriteScale,
				(float)bullets[i]->getTexture().height * spriteScale
			},

			// Vector2 Origin
			{
				((float)bullets[i]->getTexture().width * spriteScale) / 2.f,
				((float)bullets[i]->getTexture().height * spriteScale) / 2.f
			},

			// Rotation
			bullets[i]->getRotation(),

			// Color 
			WHITE
		); 
	}

	// Draw player
	DrawTexturePro(
		// Texture
		player->getTexture(), 

		// Rectangle Source
		{0, 0, (float)(player->getTexture().width), (float)(player->getTexture().height)},

		// Rectangle Destination
		{
			player->getPosition().x, player->getPosition().y, 
			(float)player->getTexture().width * spriteScale, 
			(float)player->getTexture().height * spriteScale
		},

		// Vector2 Origin
		{
			(player->getTexture().width * spriteScale) / 2.f, 
			(player->getTexture().height * spriteScale) /2.f
		},

		// Rotation
		player->getRotation(), 

		// Color
		WHITE
	);
}

void EntityManager::handleMovement(){
	// Movement
	Vector2 newMovement = {0,0};
	if(IsKeyDown(KEY_W)){
		newMovement.y = -1;
	}
	if(IsKeyDown(KEY_A)){
		newMovement.x = -1;
	}
	if(IsKeyDown(KEY_D)){
		newMovement.x = 1;
	}
	if(IsKeyDown(KEY_S)){
		newMovement.y = 1;
	}

	// Shoot
	if(IsKeyDown(KEY_SPACE)){
		if(player->canShoot()){
			addBullet(std::make_unique<Bullet>(player->shoot()));
			bullets[bullets.size()-1]->getSpeed();
		}
	}

	//newMovement = normalize(newMovement);  // Dont want normalized movement. Feels weird in bounding box
	player->move(newMovement);
}

void EntityManager::handleCollision(){
	for(uint32_t i = 0; i < entities.size(); i++){
		if(entities[i]->isDead()){
			continue;
		}
		// PLAYER COLLISION
		// Check collision range
		if(std::abs(entities[i]->getPosition().x - player->getPosition().x) < 50 && 
		std::abs(entities[i]->getPosition().y - player->getPosition().y) < 50){

			// Check collision
			CollisionShape entityBox = entities[i]->getCollisionShape();
			CollisionShape playerBox = player->getCollisionShape();

			if(isColliding(entityBox, playerBox)){
				player->hurt(entities[i]->getDamage());
				entities[i]->kill();
			}
		}

		// BULLET COLLISION
		for(uint32_t j = 0; j < bullets.size(); j++){
			if(bullets[j]->isDead()){
				continue;
			}

			if(std::abs(entities[i]->getPosition().x - bullets[j]->getPosition().x) < 50 &&
				std::abs(entities[i]->getPosition().y - bullets[j]->getPosition().y) < 50){
				
				// Check Collision
				CollisionShape entityBox = entities[i]->getCollisionShape();
				CollisionShape bulletBox = bullets[j]->getCollisionShape();

				if(isColliding(entityBox, bulletBox)){
					entities[i]->hurt(bullets[j]->getDamage());
					bullets[j]->kill();
					std::cout << "Collision Detected\n";
				}

			}
		}
	}	
}

void EntityManager::setPlacement(std::vector<GridInfo> newPlacement){
   alienPlacement = newPlacement;
   entities.clear();
   entities.resize(alienPlacement.size());
   Vector2 position;
   
   for(auto placement : alienPlacement){
      position = placement.position;
      std::unique_ptr<NormalAlien> normalAlien = std::make_unique<NormalAlien>();
      std::unique_ptr<ShooterAlien> shooterAlien = std::make_unique<ShooterAlien>();
      std::unique_ptr<CaptureAlien> captureAlien = std::make_unique<CaptureAlien>();
      switch(placement.alienType){
         case ALIEN_TYPE::NORMAL:
            normalAlien->setPosition(position);
            entities.push_back(std::move(normalAlien));
         break;
         case ALIEN_TYPE::SHOOTER:
            shooterAlien->setPosition(position);
            entities.push_back(std::move(shooterAlien));
         break;
         case ALIEN_TYPE::CAPTURE:
            captureAlien->setPosition(position);
            entities.push_back(std::move(captureAlien));
         break;
      }
   }
}