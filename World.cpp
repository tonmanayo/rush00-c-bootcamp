//
// Created by tony on 2017/05/28.
//

#include <ncurses.h>
#include <zconf.h>
#include "World.h"


World::World(): MaxWidth(0), MaxHeight(0) {}

World::World(int y, int x): MaxHeight(y), MaxWidth(x) {

}

World::~World() {}

int **World::CreateWorld() {
	int **newWorld = new int*[MaxWidth];
	for (int i = 0; i < MaxHeight; i++) {
		newWorld[i] = new int[MaxWidth];
	}
	return newWorld;
}

World &World::operator=(World const &rhs) {
	//std::cout << "Assignation Constructor called\n";
	if (this != &rhs){
		this->MaxWidth = rhs.getMaxWidth();
		this->MaxHeight = rhs.getMaxHeight();
	}
	return *this;
}

void World::InitializeWorld(int **world) {
	for (int i = 0; i < MaxHeight; i++) {
		for (int j = 0; j < MaxWidth; j++) {
			world[i][j] = Blank;
			if (j % 2 == 0) {
				world[0][j] = Boarder1;
				world[MaxHeight - 1][j] = Boarder2;
			} else {
				world[0][j] = Boarder2;
				world[MaxHeight - 1][j] = Boarder1;
			}
		}
	}
	_pY = MaxHeight / 2;
	_Px = 0;
	world[_pY][_Px] = Player;
}

void World::DestroyW(int **&world, int rows) {

	delete [] world;
	world = NULL;
}

void World::DisplayW(int **world) {
	for (int i = 0; i < MaxHeight; i++) {
		for (int j = 0; j < MaxWidth; j++) {
			if (world[i][j] == Blank)
				mvprintw(i, j, " ");
			else if (world[i][j] == Player)
				mvprintw(i, j, "P");
			else if (world[i][j] == Boarder2)
				mvprintw(i, j, "/");
			else if (world[i][j] == Boarder1)
				mvaddch(i, j, '\\');
			else if (world[i][j] == Bullets)
				mvaddch(i, j, '>');
			else if (world[i][j] == EnemyCreep)
				mvaddch(i, j, '#');
			else if (world[i][j] == Lazer)
				mvaddch(i, j, '-');
		}
	}
}

int World::getMaxWidth() const {
	return MaxWidth;
}

void World::setMaxWidth(int Width) {
	World::MaxWidth = Width;
}

int World::getMaxHeight() const {
	return MaxHeight;
}

void World::setMaxHeight(int Height) {
	World::MaxHeight = Height;
}

void World::MovePlayer(int **world, int key) {

	if (key == KEY_DOWN && _pY < MaxHeight - 2) {
		world[_pY][_Px] = Blank;
		world[_pY + 1][_Px] = Player;
		_pY++;
	} else if (key == KEY_UP && _pY > 1) {
		world[_pY][_Px] = Blank;
		world[_pY - 1][_Px] = Player;
		_pY--;
	}
}

void World::MoveWorld(int **world) {
	for (int i = 0; i < MaxWidth; ++i) {

			if (world[0][i] == Boarder1)
				world[0][i] = Boarder2;
			else if (world[0][i] == Boarder2)
				world[0][i] = Boarder1;

			if (world[MaxHeight - 1][i] == Boarder1)
				world[MaxHeight - 1][i] = Boarder2;
			else if (world[MaxHeight - 1][i] == Boarder2)
				world[MaxHeight - 1][i] = Boarder1;
	}
}

void World::Shoot(int **world, int key) {

	if (key == KEY_RIGHT)
		world[_pY][_Px + 1] = Bullets;
		for (int i = 0; i < MaxHeight; ++i) {
			for (int j = 0; j < MaxWidth; ++j) {
				if (world[i][j + 1] == EnemyCreep && world[i][j] == Bullets) {
					world[i][j] = Blank;
					world[i][j + 1] = Blank;
					break ;
				} else if (world[i][j] == Bullets) {
					world[i][j] = Blank;
					world[i][j + 1] = Bullets;
					break ;
					}
			}
		}
	if (key == 's') {
		DisplayW(world);
		usleep(500000);
		DisplayW(world);
		for (int j = 1; j < MaxWidth; ++j) {
			world[_pY][j] = Blank;
		}
	}

}

