#pragma once

#include <raylib.h>
#include "Utils.hpp"

class Bullet{
	public:
		Bullet();
		~Bullet() = default;
		float getSpeed();
		Vector2 getAngle();
		Texture2D getTexture();
		Vector2 getPosition();
		float getRotation();

		void update();

		void setSpeed(float speed);
		void setAngle(Vector2 angle);
		void setPosition(Vector2 newPosition);
		void setRotation(float newRot);
		bool killMe = false;
		
	private:
		float speed = 300;
		Vector2 angle = {0,-1};
		Vector2 position;
		Texture2D texture;
		float rotation = 0;

		void moveBall();
};
