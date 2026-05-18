#include "Bullet.hpp"
#include <iostream>

Bullet::Bullet(){
	texture = LoadTexture("assets/bullet.png");
}

void Bullet::update(){
	moveBullet();
	updateColShape();
}

void Bullet::moveBullet(){
	//movementVec = normalize(movementVec);
	position.x += movementVec.x * speed * GetFrameTime();
	position.y += movementVec.y * speed * GetFrameTime();
}
