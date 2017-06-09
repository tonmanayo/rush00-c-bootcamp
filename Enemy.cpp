//
// Created by tony on 2017/05/28.
//

#include <cstdlib>
#include "Enemy.h"


Enemy::Enemy() {}

Enemy::~Enemy() {}

const std::string &Enemy::getSName() const {
	return sName;
}

void Enemy::setSName(const std::string &sName) {
	Enemy::sName = sName;
}

int Enemy::getEposX() const {
	return EposX;
}

void Enemy::setEposX(int EposX) {
	Enemy::EposX = EposX;
}

int Enemy::getEposY() const {
	return EposY;
}

void Enemy::setEposY(int EposY) {
	Enemy::EposY = EposY;
}

void Enemy::CreateEnemy(int **world, int height, int width, int count) {
	int Pos = (rand() % (height - 2) + 1);
	int nbSpawn = rand() % (height / 2) + count * 10;
	if (count % 4 == 0) {
		for (int i = 0; i < nbSpawn; ++i) {
			world[Pos][width - 2] = EnemyCreep;
		}
	}
}

int Enemy::MoveEnemy(int **world, int height, int width) {

	for (int i = 0; i < height; ++i) {

		for (int j = 0; j < width; ++j) {
			int ran = rand() % 2;
			int pos = rand() % 2;
			if (pos == 0)
				ran = -ran;
			if (world[i][j - 1] == Player && world[i][j] == EnemyCreep){
				return 0;
			}
			if (world[i][j - 1] == Bullets && world[i][j] == Bullets)
				world[i][j] = Blank;
			if (world[i][j] == EnemyCreep && (i + ran) > 1 && (i + ran < height - 1)){
				world[i][j] = Blank;
				world[i + ran][j - 1] = EnemyCreep;
			}
		}
	}
	return 1;
}
