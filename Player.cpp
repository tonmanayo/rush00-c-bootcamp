//
// Created by tony on 2017/05/27.
//

#include <iostream>
#include "Player.h"

Player::Player(): _iHp(0), _iArmor(0), _sName(""), _sWeapon(""), _pY(0), _Px(0) {
	std::cout << "A player was created\n";
}

Player::Player(std::string name, int hp, int armor, std::string weapon): _sName(name), _iHp(hp), _iArmor(armor), _sWeapon(weapon) {
	std::cout << "A player was created\n";
}

Player::~Player() {
	std::cout << "A Player Has Died\n";
}

int Player::get_iHp() const {
	return _iHp;
}

void Player::set_iHp(int _iHp) {
	Player::_iHp = _iHp;
}

int Player::get_iArmor() const {
	return _iArmor;
}

void Player::set_iArmor(int _iArmor) {
	Player::_iArmor = _iArmor;
}

const std::string &Player::get_sWeapon() const {
	return _sWeapon;
}

void Player::set_sWeapon(const std::string &_sWeapon) {
	Player::_sWeapon = _sWeapon;
}

const std::string &Player::get_sName() const {
	return _sName;
}

void Player::set_sName(const std::string &_sName) {
	Player::_sName = _sName;
}

int Player::get_Px() const {
	return _Px;
}

void Player::set_Px(int _Px) {
	Player::_Px = _Px;
}

int Player::get_pY() const {
	return _pY;
}

void Player::set_pY(int _pY) {
	Player::_pY = _pY;
}


