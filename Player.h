//
// Created by tony on 2017/05/27.
//

#ifndef BOOTCAMP_PLAYER_H
#define BOOTCAMP_PLAYER_H

#include <cstdlib>
#include <string>

class Player {

public:
	int get_Px() const;

	void set_Px(int _Px);

	int get_pY() const;

	void set_pY(int _pY);

protected:
	int _Px;
	int _pY;
	int _iHp;
	int _iArmor;
	std::string _sWeapon;
	std::string _sName;
public:

	const int Lazer = 6;
	Player(std::string name, int hp, int armor, std::string weapon);
	int get_iHp() const;
	void set_iHp(int _iHp);
	int get_iArmor() const;
	void set_iArmor(int _iArmor);
	const std::string &get_sWeapon() const;
	void set_sWeapon(const std::string &_sWeapon);
	const std::string &get_sName() const;
	void set_sName(const std::string &_sName);
	Player();

	virtual ~Player();
};


#endif //BOOTCAMP_PLAYER_H
