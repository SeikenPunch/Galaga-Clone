#include "Bullet.hpp"

Bullet::Bullet(){
	texture = LoadTexture("assets/bullet.png");
}

void Bullet::update(){
	moveBall();
	if(position.y < 0 - texture.height){
		killMe = true;
	}
}

void Bullet::moveBall(){
	angle = normalize(angle);
	position.x += angle.x * speed * GetFrameTime();
	position.y += angle.y * speed * GetFrameTime();
}

float Bullet::getSpeed(){
	return speed;
}

Vector2 Bullet::getAngle(){
	return angle;
}

Texture2D Bullet::getTexture(){
	return texture;
}

Vector2 Bullet::getPosition(){
	return position;
}

float Bullet::getRotation(){
	return rotation;
}

void Bullet::setSpeed(float newSpeed){
	speed = newSpeed;
}

void Bullet::setAngle(Vector2 newAngle){
	angle = newAngle;
}

void Bullet::setPosition(Vector2 newPos){
	position = newPos;
}

void Bullet::setRotation(float newRot){
	rotation = newRot;
}