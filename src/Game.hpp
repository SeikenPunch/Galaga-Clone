#pragma once

#include <raylib.h>
#include <algorithm>
#include <vector>
#include "Player.hpp"
#include "Bullet.hpp"
#include "EntityManager.hpp"

enum class GameState{
	MAIN_MENU,
	SETTINGS,
	IN_GAME,
	PAUSED
};

class Game {
	public:
		void start();
		void run();
	private:
		const int VirtualScreenHeight = 1080; //360
		const int VirtualScreenWidth = 1920; //640
		const int spriteScale = 3;

		RenderTexture2D target;
		void update();
		void getInput();
		EntityManager em;
};
