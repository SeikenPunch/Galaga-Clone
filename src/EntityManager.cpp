#include <cstdint>
#include "EntityManager.hpp"
#include "Collision.hpp"


void EntityManager::addEntity(std::unique_ptr<Entity> entity){
	entities.push_back(std::move(entity));
}

void EntityManager::update(){
	// Probably add player to EntityManager so that EM class has higher cohesion
	// Add a player component to EM class. Then create bullet vector in EM class as well
	// This will make EM class highly cohesive and loosely coupled
}

void EntityManager::handleCollision(Player p){
	for(uint32_t i = 0; i < entities.size(); i++){

		// Check collision range
		if(entities[i]->getPosition().x - p.getPosition().x < 50 && 
		entities[i]->getPosition().y - p.getPosition().y < 50){

			//Check collision
			CollisionShape entityBox = entities[i]->getCollisionShape();
			CollisionShape playerBox = p.getCollisionShape();
			p.hurt(entities[i]->getDamage());
			entities[i]->kill();
		}	
	}	
}

