//
// Created by tony on 2017/05/28.
//

#ifndef BOOTCAMP_ENEMY_H
#define BOOTCAMP_ENEMY_H

#include <string>

class Enemy {
private:
	std::string sName;
	int EposX;
	int EposY;
public:
	enum WorldPieces {
		Blank = 0,
		Player,
		Bullets,
		Boarder1,
		Boarder2,
		EnemyCreep
	};
	void CreateEnemy(int **, int, int, int);
	int MoveEnemy(int **, int, int);

	const std::string &getSName() const;

	void setSName(const std::string &sName);

	int getEposX() const;

	void setEposX(int EposX);

	int getEposY() const;

	void setEposY(int EposY);

	virtual ~Enemy();

	Enemy();
};

#endif //BOOTCAMP_ENEMY_H
