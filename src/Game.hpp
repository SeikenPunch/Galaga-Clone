#pragma once

#include <raylib.h>
#include <algorithm>
#include <vector>
#include "Player.hpp"
#include "Bullet.hpp"
#include "EntityManager.hpp"
#include "AlienInfo.hpp"
#include "Level.hpp"

// For button testing
#include "Button.hpp"
// For button testing

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

      //----------------- FOR TESTING LEVELS -----------------//
      void setPositions();
      void drawLines();
         
      //----------------- FOR TESTING LEVELS -----------------//


      
      //----------------- FOR TESTING BUTTONS -----------------//
      void setupButtons();
      Button testButton;
      //----------------- FOR TESTING BUTTONS -----------------//
		RenderTexture2D target;
		void update();
		void getInput();
      void getLevel(int level);
      GameState currentState = GameState::MAIN_MENU;
		EntityManager em;
      Level levelManager;
      int level = 0; 
      bool inLevel = true;
      std::vector<GridInfo> alienPlacement;
};
