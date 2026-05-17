#include "Game.hpp"
#include "Utils.hpp"

void Game::start(){
	// Escape wont close the program with this
	SetExitKey(KEY_NULL);

	InitWindow(VirtualScreenWidth, VirtualScreenHeight, "Agalag");
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetTargetFPS(0);

	em.start(VirtualScreenWidth, VirtualScreenHeight);
	target = LoadRenderTexture(VirtualScreenWidth, VirtualScreenHeight);
}

void Game::run(){

	while(!WindowShouldClose()){

		update();

		// Draw to texture
		BeginTextureMode(target);
		ClearBackground(BLACK);

		em.draw();

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