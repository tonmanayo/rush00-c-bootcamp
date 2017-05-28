
#include "World.h"
#include <ncurses.h>
#include <unistd.h>
int main(){
	srand(time(0));

	initscr();
	start_color();
	keypad(stdscr, TRUE);
	noecho();
	cbreak();
	curs_set(FALSE);

	int MaxHeight = 0;
	int MaxWidth = 0;
	getmaxyx(stdscr, MaxHeight, MaxWidth);

	World world(MaxHeight, MaxWidth);
	int **NewWorld;

	NewWorld = world.CreateWorld();
	world.InitializeWorld(NewWorld);
	int key = 0;
	int player = MaxHeight / 2;
	mvprintw(player, MaxWidth / 2, "GET READY FOR BATTLE\n");
	attron(A_BOLD);
	mvprintw(player + 1, MaxWidth / 2, "Press any Key to enter battle\n");
	mvprintw(player + 1, MaxWidth / 2, "Keys: Up/Down Arrow keys to move.\n Right Arrow Shoot.\n 'S' Special Attack \n");
	mvprintw(player + 1, MaxWidth / 2, "Right Arrow Shoot.\n");
	mvprintw(player + 1, MaxWidth / 2, "'S' Special Attack \n");

	attroff(A_BOLD);

	refresh();
	getch();
	nodelay(stdscr, TRUE);
	double count = 0;
	world.DisplayW(NewWorld);
	Enemy enemy;
	int nbBullets = 0;
	int Status = 1;

	while (Status == 1) {
		key = getch();
		enemy.CreateEnemy(NewWorld, MaxHeight, MaxWidth, count);
		Status = enemy.MoveEnemy(NewWorld, MaxHeight, MaxWidth);
		world.SpecialLazer(NewWorld, MaxWidth, key);
		world.Shoot(NewWorld, key);
		world.MovePlayer(NewWorld, key);
		world.DisplayW(NewWorld);
		world.MoveWorld(NewWorld);

		usleep(30000);
		count = count + 0.1;
		mvprintw(MaxHeight - 1, 0, "Your Score is: %i", count);
		refresh();

	}
	clear();
	nodelay(stdscr, FALSE);
	printw("You Loose \n");
	printw("Score: %d", count);
	getch();
	clear();


	world.DestroyW(NewWorld, MaxHeight - 1);
	endwin();

	return 0;
}