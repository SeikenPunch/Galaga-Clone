#include "Game.hpp"
#include "Utils.hpp"
#include <iostream> //debug

void Game::start(){
	InitWindow(VirtualScreenWidth, VirtualScreenHeight, "Agalag");
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetTargetFPS(0);

	// Escape wont close the program with this
	SetExitKey(KEY_Q);

	em.start(VirtualScreenWidth, VirtualScreenHeight);
	target = LoadRenderTexture(VirtualScreenWidth, VirtualScreenHeight);

   // Menu screen and such

   // Load first level

   // hard coding first level for testing.
   setPositions();
}

void Game::run(){

	while(!WindowShouldClose()){

		update();

		// Draw to texture
		BeginTextureMode(target);
		ClearBackground(BLACK);

      //if(currentState == GameState::MAIN_MENU){;}
   
      if(currentState == GameState::IN_GAME){      
         em.draw();
         
         drawLines();

         EndTextureMode();		
         
         // Calculate screen shit
         float scaleX = static_cast<float>(GetScreenWidth()) / static_cast<float>(VirtualScreenWidth);
         float scaleY = static_cast<float>(GetScreenHeight()) / static_cast<float>(VirtualScreenHeight);

         float scale = std::min(scaleX, scaleY);

         float scaledWidth = VirtualScreenWidth * scale;
         float scaledHeight = VirtualScreenHeight * scale;
         
         float offsetX = (static_cast<float>(GetScreenWidth()) - scaledWidth) / 2.f;
         float offsetY = (static_cast<float>(GetScreenHeight()) - scaledHeight) / 2.f;

         // DRAW
         BeginDrawing();

         SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);
         ClearBackground(BLACK);
         DrawTexturePro(
            target.texture, 
            {0,0, static_cast<float>(target.texture.width), -static_cast<float>(target.texture.height)},
            {offsetX, offsetY, scaledWidth, scaledHeight}, 
            {0,0}, 
            0.f, 
            WHITE
         );

         EndDrawing();
      }
	}

	CloseWindow();
}

void Game::getInput(){
	// Fullscreen
	if(IsKeyPressed(KEY_F)){
		ToggleBorderlessWindowed();
	}
}

void Game::update(){
	getInput();

	em.update();

	if(IsWindowResized()){
		SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);
	}
}

void Game::getLevel(int level){
   // alienPlacement = levelManager.getLevel(level);
   // em.setPlacement(alienPlacement);

   //make some aliens
   std::unique_ptr<NormalAlien> alien = std::make_unique<NormalAlien>();
}

void Game::drawLines(){
   int cellSize = levelManager.getCellSize();
   int cols = 40;
   int rows = 18;
   for(int i = 0; i <= cols; i++){
      DrawLine(i*cellSize, 0, i*cellSize, VirtualScreenHeight - 215, GRAY);
   }
   for(int i = 0; i <= rows; i++){
      DrawLine(0, i*cellSize, VirtualScreenWidth, i*cellSize, GRAY);
   }
}

void Game::setPositions(){
   //make some aliens
   std::unique_ptr<NormalAlien> alien1 = std::make_unique<NormalAlien>();
   std::unique_ptr<NormalAlien> alien2 = std::make_unique<NormalAlien>();
   std::unique_ptr<NormalAlien> alien3 = std::make_unique<NormalAlien>();
   std::unique_ptr<NormalAlien> alien4 = std::make_unique<NormalAlien>();
   std::unique_ptr<NormalAlien> alien5 = std::make_unique<NormalAlien>();
   std::unique_ptr<NormalAlien> alien6 = std::make_unique<NormalAlien>();

   int cellSize = levelManager.getCellSize();
   float halfSize = cellSize / 2.f;

   alien1->setPosition(18 * cellSize - halfSize, 9 * cellSize - halfSize);
   alien2->setPosition(19 * cellSize - halfSize, 9 * cellSize - halfSize);
   alien3->setPosition(20 * cellSize - halfSize, 9 * cellSize - halfSize);
   alien4->setPosition(21 * cellSize - halfSize, 9 * cellSize - halfSize);
   alien5->setPosition(22 * cellSize - halfSize, 9 * cellSize - halfSize);
   alien6->setPosition(23 * cellSize - halfSize, 9 * cellSize - halfSize);

   em.addEntity(std::move(alien1));
   em.addEntity(std::move(alien2));
   em.addEntity(std::move(alien3));
   em.addEntity(std::move(alien4));
   em.addEntity(std::move(alien5));
   em.addEntity(std::move(alien6));
}