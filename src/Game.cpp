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


	// ALIEN TESTING
	std::unique_ptr<Alien> a = std::make_unique<Alien>();
	int width = a->getTexture().width * spriteScale;
	int height = a->getTexture().height * spriteScale;
	std::cout << width << std::endl;
	int amountX = VirtualScreenWidth / width;
	int amountY = (VirtualScreenHeight - 200) / height;

	std::cout << amountX << "  " << amountY << std::endl;
	
	for(int i = 0; i < amountX; i++){
		for(int j = 0; j < amountY; j++){
			std::unique_ptr<Alien> a = std::make_unique<Alien>();
			a->setPosition({(float)i * width + width/2, (float)j * height + height / 2});
			em.addEntity(std::move(a));
		}
	}
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