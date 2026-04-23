#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

#include "entity/player.h"
#include "entity/enemy.h"

void updatePlayer(Player *player_name);
void drawPlayer(Player *player_name);
void drawEnemy(Enemy *enemy_name);

int main() {
	const int screenWidth = 800;
	const int screenHeight = 450;
	int halfWidth = screenWidth/2;
	int halfHeight = screenHeight/2;

	Color aqua_color = {0, 255, 228, 255};

	Player player = { halfWidth, halfHeight, 4 };
	Enemy enemy = { halfWidth-20, halfHeight-20, 4};

	InitWindow(screenWidth, screenHeight, "My First Raylib Window!");
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetTargetFPS(60);

	Camera2D camera = { 0 };
	camera.target = (Vector2){ player.x, player.y };
	camera.offset = (Vector2){ GetScreenWidth()/2, GetScreenHeight()/2 };
	camera.zoom = 1.0f;


	while (!WindowShouldClose())
	{
			updatePlayer(&player);

			Camera2D camera = { 0 };
			camera.target = (Vector2){ player.x, player.y };
			camera.offset = (Vector2){
					GetScreenWidth()/2.0f,
					GetScreenHeight()/2.0f
			};
			camera.zoom = 1.0f;

			BeginDrawing();
			ClearBackground(aqua_color);

			BeginMode2D(camera);
					DrawRectangle(200, 200, 50, 50, GREEN);
					DrawCircle(200, 200, 20, RED); // IMPORTANT: reference object
					drawEnemy(&enemy);
					drawPlayer(&player);
			EndMode2D();

			EndDrawing();
	}
}

void updatePlayer(Player *p) {
	if (IsKeyDown(KEY_RIGHT))
			p->x += p->speed;
	if (IsKeyDown(KEY_LEFT))
			p->x -= p->speed;
	if (IsKeyDown(KEY_UP))
			p->y -= p->speed;
	if (IsKeyDown(KEY_DOWN))
			p->y += p->speed;
}

void drawPlayer(Player *p) {
	DrawRectangle(p->x, p->y, 25, 25, WHITE);
}

void drawEnemy(Enemy *p) {
	DrawRectangle(p->x, p->y, 25, 25, RED);
}

