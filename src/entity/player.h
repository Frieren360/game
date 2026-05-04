#ifndef PLAYER_H
#include <stdbool.h>
#define PLAYER_H
typedef struct Player {
	float x;
	float y;
	float speed;
	int health;
	Rectangle hitbox;
	float cooldown;
	float timer;
	bool colliding;
} Player;
#endif
