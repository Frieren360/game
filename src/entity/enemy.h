#ifndef ENEMY_H
#define ENEMY_H
typedef struct Enemy {
	float x;
	float y;
	float speed;
	int health;
	Rectangle hitbox;
} Enemy;
#endif
