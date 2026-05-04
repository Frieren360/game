#ifndef PLAYER_H
#include <stdbool.h>
#define PLAYER_H
typedef struct Entity {
	float x;
	float y;
	float speed;
	int health;
	Rectangle hitbox;
	float cooldown;
	float timer;
	bool colliding;
} Entity;
#endif
