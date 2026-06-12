#pragma once

#include "raylib.h"
#include "Entity.hpp"

class NormalAlien : public Entity{
	public:
		NormalAlien();
		void update() override;
		void attack(Vector2 position);
};

class ShooterAlien : public Entity{
   public:
      ShooterAlien();
      void update() override;
      void attack(Vector2 position);
};

class CaptureAlien : public Entity{
   public:
      CaptureAlien();
      void update() override;
      void attack(Vector2 position);
};