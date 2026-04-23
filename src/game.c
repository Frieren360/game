#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

typedef struct Player {
	float x;
	float y;
	float speed;
} Player;

void updatePlayer(Player *player_name);
void drawPlayer(Player *player_name);

int main() {
	const int screenWidth = 800;
	const int screenHeight = 450;

	Color aqua_color = {0, 255, 228, 255};

	Player player = { screenWidth/2, screenHeight/2, 4 };

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
					drawPlayer(&player);

					DrawCircle(200, 200, 20, RED); // IMPORTANT: reference object
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

