#include "Aliens.hpp"

/////////////////////////////// NORMAL ALIEN ///////////////////////////////

NormalAlien::NormalAlien(){
	texture = LoadTexture("assets/alien1.png");
	updateColShape();
	health = 1;
}

void NormalAlien::update(){
	updateColShape();
	if(health <= 0){
		dead = true;
	}
}

void NormalAlien::attack(Vector2 attackPosition){
	;
}


/////////////////////////////// SHOOTER ALIEN ///////////////////////////////

ShooterAlien::ShooterAlien(){
	texture = LoadTexture("assets/alien1.png");
	updateColShape();
	health = 1;
}

void ShooterAlien::update(){
	updateColShape();
	if(health <= 0){
		dead = true;
	}
}

void ShooterAlien::attack(Vector2 attackPosition){
	;
}


/////////////////////////////// CAPTURE ALIEN ///////////////////////////////

CaptureAlien::CaptureAlien(){
	texture = LoadTexture("assets/alien1.png");
	updateColShape();
	health = 1;
}

void CaptureAlien::update(){
	updateColShape();
	if(health <= 0){
		dead = true;
	}
}

void CaptureAlien::attack(Vector2 attackPosition){
	;
}
