#ifndef PLAYER_H
#define PLAYER_H
typedef struct Player {
	float x;
	float y;
	float speed;
	int health;
	Rectangle hitbox;
} Player;
#endif
