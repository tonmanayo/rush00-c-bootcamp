//
// Created by tony on 2017/05/27.
//

#include "Bismaric.h"

void Bismaric::SpecialLazer(int **world, int width, int key) {
	if (key == 's') {
		for (int j = 1; j < width; ++j) {
			world[_pY][j] = Lazer;
		}
	}
}
