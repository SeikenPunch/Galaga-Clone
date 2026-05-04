#include "Game.hpp"
#include "Utils.hpp"

void Game::start(){
	// Escape wont close the program with this
	SetExitKey(KEY_NULL);

	InitWindow(VirtualScreenWidth, VirtualScreenHeight, "Agalag");
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetTargetFPS(0);


	player = new Player();

	leftBound = 25;
	rightBound = VirtualScreenWidth - 25;
	topBound = VirtualScreenHeight - 200;
	bottomBound = VirtualScreenHeight - 25;

	player->setPosition({VirtualScreenWidth/2.f, (bottomBound + topBound) / 2});
	player->setBounds(leftBound, rightBound, topBound, bottomBound);

	target = LoadRenderTexture(VirtualScreenWidth, VirtualScreenHeight);
	
	SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);	
	SetTextureFilter(player->getTexture(), TEXTURE_FILTER_POINT);

}

void Game::run(){

	while(!WindowShouldClose()){

		update();

		// Draw to texture
		
		BeginTextureMode(target);
		ClearBackground(BLACK);

		// Draw Player
		DrawTexturePro(
			player->getTexture(), 
			{0, 0, static_cast<float>(player->getTexture().width), static_cast<float>(player->getTexture().height)},
			{player->getPosition().x, player->getPosition().y, static_cast<float>(player->getTexture().width) * spriteScale, static_cast<float>(player->getTexture().height) * spriteScale},
			{(player->getTexture().width * spriteScale) / 2.f , (player->getTexture().height * spriteScale) /2.f}, 
			player->getRotation(), 
			WHITE
		);

		// Draw Bullets
		for(auto& bullet : bullets){
			DrawTexturePro(
				bullet.getTexture(),
				{0,0, static_cast<float>(bullet.getTexture().width), static_cast<float>(bullet.getTexture().height)},
				{bullet.getPosition().x, bullet.getPosition().y, static_cast<float>(bullet.getTexture().width) * spriteScale, static_cast<float>(bullet.getTexture().height) * spriteScale},
				{(bullet.getTexture().width * spriteScale) / 2.f, (bullet.getTexture().height * spriteScale) / 2.f},
				bullet.getRotation(),
				WHITE
			);
		}

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

	delete player;

	CloseWindow();
}

void Game::getInput(){
	// Movement
	Vector2 newMovement = {0,0};
	if(IsKeyDown(KEY_W)){
		newMovement.y = -1;
	}
	if(IsKeyDown(KEY_A)){
		newMovement.x = -1;
	}
	if(IsKeyDown(KEY_D)){
		newMovement.x = 1;
	}
	if(IsKeyDown(KEY_S)){
		newMovement.y = 1;
	}

	// Shoot
	if(IsKeyDown(KEY_SPACE)){
		if(player->canShoot()){
			Bullet b = player->shoot();
			bullets.push_back(b);
		}
	}

	// Fullscreen
	if(IsKeyPressed(KEY_F)){
		ToggleBorderlessWindowed();
	}

	newMovement = normalize(newMovement);

	player->move(newMovement);
}

void Game::update(){
	getInput();

	player->update();

	if(IsWindowResized()){
		SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);
	}

	// Update bullets;
	for(std::size_t i = 0; i < bullets.size();){
		
		bullets[i].update();

		if(bullets[i].killMe){
			bullets[i] = bullets.back();
			bullets.pop_back();
			continue;
		}
		i++;
	}

}