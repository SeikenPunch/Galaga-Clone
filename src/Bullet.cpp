#include "Bullet.hpp"

Bullet::Bullet(){
	texture = LoadTexture("assets/bullet.png");
}

void Bullet::update(){
	moveBullet();
}

void Bullet::moveBullet(){
	movementVec = normalize(movementVec);
	position.x += movementVec.x * speed * GetFrameTime();
	position.y += movementVec.y * speed * GetFrameTime();
}
