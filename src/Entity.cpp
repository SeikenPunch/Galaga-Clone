#include "Entity.hpp"

Texture2D Entity::getTexture(){
	SetTextureFilter(texture, TEXTURE_FILTER_POINT);
	return texture;
}

Vector2 Entity::getPosition(){
	return position;
}

Vector2 Entity::getMovmentVec(){
	return movementVec;
}

float Entity::getRotation(){
	return rotation;
}

CollisionShape Entity::getCollisionShape(){
	return colShape;
}

int Entity::getDamage(){
	return damage;
}

void Entity::setTexture(Texture2D texture){
	this->texture = texture;
}

void Entity::setPosition(Vector2 position){
	this->position = position;
}

void Entity::setRotation(float rotation){
	this->rotation = rotation;
}

void Entity::setMovementVec(Vector2 movementVec){
	this->movementVec = movementVec;
}

void Entity::setSpeed(float speed){
	this->speed = speed;
}

void Entity::move(Vector2 moveBy){
	position.x += moveBy.x * speed * GetFrameTime();
	position.y += moveBy.y * speed * GetFrameTime();
}

void Entity::hurt(int damage){
	health -= damage;
}

void Entity::kill(){
	dead = true;
}

bool Entity::isDead(){
	return dead;
}

void Entity::updateColShape(){

	colShape.width = texture.width * SPRITE_SCALE;
	colShape.height = texture.height * SPRITE_SCALE;
	colShape.originPosition.x = position.x + (texture.width / 2.f);
	colShape.originPosition.y = position.y + (texture.height / 2.f);
}