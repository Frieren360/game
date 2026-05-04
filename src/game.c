#include <stdio.h>
//#include <stdlib.h>
#include <raylib.h>

#include "entity/player.h"
#include "entity/enemy.h"

#include "variables/globals.h"

void updatePlayer(Player *player_name);
void drawPlayer(Player *player_name);
void drawEnemy(Enemy *enemy_name);

float delta = 0;

int main() {
	const int screenWidth = 800;
	const int screenHeight = 450;
	float halfScreenWidth = screenWidth/2;
	float halfScreenHeight = screenHeight/2;

	Color aqua_color = {0, 255, 228, 255};

	const int rectHeight = 25;
	const int rectWidth = 25;


	Player player = {
		.x = halfScreenWidth,
		.y = halfScreenHeight,
		.speed = 500,
		.health = 100,
		.hitbox = {halfScreenWidth, halfScreenHeight, 25, 25},
		.cooldown = 1.0,
		.timer = 0.0,
		.colliding = false
	};
	Enemy enemy = {
		.x = halfScreenWidth,
		.y = halfScreenHeight,
		.speed = 5000,
		.hitbox = {halfScreenWidth, halfScreenHeight, 25, 25}
	};

	InitWindow(screenWidth, screenHeight, "My First Raylib Window!");
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetTargetFPS(GetMonitorRefreshRate(0));

	Camera2D camera = { 0 };
	camera.target = (Vector2){ player.x, player.y };
	camera.offset = (Vector2){ GetScreenWidth()/2, GetScreenHeight()/2 };
	camera.zoom = 1.0f;


	while (!WindowShouldClose()) {
		delta = GetFrameTime();
		updatePlayer(&player);

		camera.target = (Vector2){ player.x, player.y };
		camera.offset = (Vector2){
				GetScreenWidth()/2.0f,
				GetScreenHeight()/2.0f
		};
		camera.zoom = 1.0f;

		BeginDrawing();
		ClearBackground(aqua_color);


		if (CheckCollisionRecs(player.hitbox, enemy.hitbox)) {
			if (!player.colliding) {
				player.health -= 5;
				player.colliding = true;
			}
			else if (player.timer == player.cooldown) {
				player.health -= 5;
			}
			printf("Health = %d\n", player.health);
		}
		else {
			player.colliding = false;
		}

		BeginMode2D(camera);
				DrawRectangle(200, 200, 50, 50, GREEN);
				DrawCircle(200, 200, 20, RED);
				drawEnemy(&enemy);
				drawPlayer(&player);
				//DrawRectangleRec(player.hitbox, (Color)YELLOW);
				//DrawRectangleRec(enemy.hitbox, (Color)PURPLE);
		EndMode2D();

		EndDrawing();
	}
}

void updatePlayer(Player *p) {
	if (IsKeyDown(KEY_RIGHT))
			p->x += p->speed*delta;
	if (IsKeyDown(KEY_LEFT))
			p->x -= p->speed*delta;
	if (IsKeyDown(KEY_UP))
			p->y -= p->speed*delta;
	if (IsKeyDown(KEY_DOWN))
			p->y += p->speed*delta;
	p->hitbox.x = p->x;
	p->hitbox.y = p->y;

	if (p->timer > 0) {
		p->timer -= delta;
	}
	else if (p->timer <= 0) {
		p->timer = p->cooldown;
	}
}

void drawPlayer(Player *p) {
	DrawRectangle(p->x, p->y, 25, 25, WHITE);
}

void drawEnemy(Enemy *p) {
	DrawRectangle(p->x, p->y, 25, 25, RED);
}

