//
// Created by tony on 2017/05/28.
//

#ifndef BOOTCAMP_WORLD_H
#define BOOTCAMP_WORLD_H

#include <iostream>
#include <cstdlib>
#include "Bismaric.h"
#include "Enemy.h"

class World : public Bismaric, public Enemy{

private:
	int _nbBullets;
	int MaxWidth;
	int MaxHeight;
public:
	World();
	World(int, int);
	virtual ~World();
	int **CreateWorld();
	void InitializeWorld(int **);
	void DestroyW(int **&);
	void DisplayW(int **);
	void MovePlayer(int **, int);
	void MoveWorld(int **);
	void Shoot(int **, int);
	World &operator=(World const &rhs);

	int getMaxWidth() const;
	void setMaxWidth(int Width);
	int getMaxHeight() const;
	void setMaxHeight(int Height);
	enum WorldPieces {
		Blank = 0,
		Player,
		Bullets,
		Boarder1,
		Boarder2,
		EnemyCreep,
		Lazer
	};
};


#endif //BOOTCAMP_WORLD_H
