#include "Alien.hpp"

Alien::Alien(){
	texture = LoadTexture("assets/alien1.png");
	updateColShape();
	health = 1;
}

void Alien::update(){
	updateColShape();
	if(health <= 0){
		dead = true;
	}
}

void Alien::attack(Vector2 attackPosition){
	;
}