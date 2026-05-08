#include <cstdint>
#include "EntityManager.hpp"
#include "Collision.hpp"


void EntityManager::addEntity(std::unique_ptr<Entity> entity){
	entities.push_back(std::move(entity));
}

void EntityManager::update(){
	handleCollision();
}

bool EntityManager::isColliding(CollisionShape body_1, CollisionShape body_2){
	bool x_col = false;	// Collision along X axis
	bool y_col = false;	// Collision along Y axis

	// Get X collision
	if(body_1.originPosition.x + (body_1.width / 2) > body_2.originPosition.x - (body_2.width / 2) ||
		body_1.originPosition.x - (body_1.width / 2) < body_2.originPosition.x + (body_2.width / 2)){
		
		x_col = true;
	}

	// Get Y collision
	if(body_1.originPosition.y + (body_1.height / 2) > body_2.originPosition.y - (body_2.height / 2) || 
		body_1.originPosition.y - (body_1.height / 2) < body_2.originPosition.y + (body_2.height / 2)){
		
		y_col = true;
	}

	if(x_col && y_col){
		return true;
	}

	return false;
}

void EntityManager::handleCollision(){
	for(uint32_t i = 0; i < entities.size(); i++){
		if(entities[i]->isDead()){
			continue;
		}
		// PLAYER COLLISION
		// Check collision range
		if(entities[i]->getPosition().x - player.getPosition().x < 50 && 
		entities[i]->getPosition().y - player.getPosition().y < 50){

			// Check collision
			CollisionShape entityBox = entities[i]->getCollisionShape();
			CollisionShape playerBox = player.getCollisionShape();

			if(isColliding(entityBox, playerBox)){
				player.hurt(entities[i]->getDamage());
				entities[i]->kill();
			}
		}

		// BULLET COLLISION
		for(uint32_t j = 0; j < bullets.size(); j++){
			if(bullets[j]->isDead()){
				continue;
			}

			if(entities[i]->getPosition().x - bullets[j]->getPosition().x < 50 &&
				entities[i]->getPosition().y - bullets[j]->getPosition().y < 50){
				
				// Check Collision
				CollisionShape entityBox = entities[i]->getCollisionShape();
				CollisionShape bulletBox = bullets[j]->getCollisionShape();

				if(isColliding(entityBox, bulletBox)){
					entities[i]->hurt(bullets[j]->getDamage());
				}

			}
		}
	}	
}

