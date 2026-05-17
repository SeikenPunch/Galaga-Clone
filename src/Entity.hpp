#pragma once

#include <raylib.h>
#include "Collision.hpp"

class Entity{
	public:
		virtual ~Entity() = default;
		Texture2D getTexture();
		Vector2 getPosition();
		float getRotation();
		Vector2 getMovmentVec();
		CollisionShape getCollisionShape();
		int getDamage();

		void setTexture(Texture2D texture);
		void setPosition(Vector2 newPos);
		void setRotation(float newRot);
		void setMovementVec(Vector2 movementVec);
		void setSpeed(float speed);
		void move(Vector2);
		void hurt(int);		
		void kill();
		bool isDead();

		virtual void update() = 0;
		
	protected:

		int SPRITE_SCALE = 3;
		void updateColShape();

		Texture2D texture;
		float rotation = {0};
		Vector2 movementVec = {0,0};
		Vector2 position = {0,0};
		float speed = 0;
		int damage = 0;
		int health = 0;
		bool dead = false;
		CollisionShape colShape;
};