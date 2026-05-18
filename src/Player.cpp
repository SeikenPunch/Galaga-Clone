#include "Player.hpp"
#include <iostream> //debug

Player::Player(){ // fix placement using virtual screen
	texture = LoadTexture("assets/Asteroids.png");
	SetTextureFilter(texture, TEXTURE_FILTER_POINT);
	position = {0, 0};
	speed = 450;
	damage = 1;

	clock.restart();
}

void Player::update(){
	// Left bound
	if(position.x < leftBound + texture.width/2){
		position.x = leftBound + texture.width/2;
	}

	// Right Bound
	if(position.x > rightBound - texture.width/2){
		position.x = rightBound - texture.width/2;
	}

	// Top Bound
	if(position.y < topBound + texture.height/2){
		position.y = topBound + texture.height/2;
	}

	// Bottom Bound
	if(position.y > bottomBound - texture.height/2){
		position.y = bottomBound - texture.height/2;
	}

}

Bullet Player::shoot(){
	Bullet b;
	b.setDamage(damage);
	b.setSpeed(900);
	b.setPosition({position.x, position.y - 50});
	std::cout << b.getSpeed() << std::endl;
	std::cout << "Called bullet" << std::endl;
	return b;
}

bool Player::canShoot(){
	if(clock.getElapsedMiliseconds() >= shootTime){
		clock.restart();
		return true;
	}
	return false;
}

void Player::setBounds(float leftBound, float rightBound, float topBound, float bottomBound){
	this->leftBound = leftBound;
	this->rightBound = rightBound;
	this->topBound = topBound;
	this->bottomBound = bottomBound;	
}
