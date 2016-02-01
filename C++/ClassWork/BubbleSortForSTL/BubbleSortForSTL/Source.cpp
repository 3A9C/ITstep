#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#if defined(_WIN32) || defined(_WIN64)
#include <curses.h>
#include <windows.h>
#define msleep(msec) Sleep(msec)
#else
#include <ncurses.h>
#include <unistd.h>
#define msleep(msec) sleep(msec)
#endif
#include <time.h>
#include <stdbool.h>

#define SNAKE_MAX_LENGTH 30
#define WIN_MSG "You are the WINNER!"
#define WELCOME_MSG "Welcome to games SNAKE!!!"
#define NEXTLVL_MSG "Next LEVEL!!"
#define LOST_MSG "Loooooser :-))))"
#define EXIT_MSG "COME BACK TO ME I WANT YOU PLAY ME!!!!"
#define CREATER_MSG "by Nikolay Morshinin"
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define SNAKE_CHAR 'O'
#define HEAD_SNAKE '@'
#define FOOD_CHAR 'F'
#define WALL_CHAR '#'


void initGame(void);
void checkGame();
void addFood();
void drawFood();
void initSnake();
void shiftSnake();
void addHead();
void removeTail();
void moveSnake();
void showWinner();
void showWelcome();

typedef struct SnakePart_
{
	int x;
	int y;
} SnakePart;

typedef struct Food_
{
	int x;
	int y;
} Food;

Food food;
int direction;
SnakePart snake[SNAKE_MAX_LENGTH];
int snakeLength;
int row = 24, col = 80;
int snakeLevel = 0;
int offon = 0;
int welcome = 2;
int snakelvlup = 6;
int uplvl = 0;
int snakespeed = 170;

// Initialization of ncurses and the game
void initGame(void)
{
	srand(time(NULL));
	for (int i = 0; i<SNAKE_MAX_LENGTH; i++)
	{
		snake[i].x = -1;
		snake[i].y = -1;
	}

	initscr();
	if (has_colors() == FALSE)
	{
		endwin();
		printf("Your terminal does not support color\n");
	}

	//getmaxyx(stdscr, row, col);
	noecho();
	cbreak();
	curs_set(0);
	start_color();			/* Start color 			*/
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(A_BOLD);
	clear();
	color_set(1, NULL);
}

// Randomly add fodd spot to the level
void addFood()
{
	int x, y;
	y = rand() % row;
	x = rand() % col;
	while ((mvinch(y, x) & A_CHARTEXT) != ' ')
	{
		y = rand() % row;
		x = rand() % col;
	}
	food.y = y;
	food.x = x;
}

// Draw food on a game plan
void drawFood()
{
	move(food.y, food.x);
	addch(FOOD_CHAR);
}

void initSnake()
{
	snakeLength = 3;
	snake[2].x = 2;
	snake[2].y = row - 3;
	snake[1].x = 3;
	snake[1].y = row - 3;
	snake[0].x = 4;
	snake[0].y = row - 3;
	direction = UP;
}

// Draw the the actual position of the snake
void drawSnake()
{
	int i = 0;
	while (snake[i].x != -1 && snake[i].y != -1)
	{
		if (i == 0)
		{
			move(snake[i].y, snake[i].x);
			addch(HEAD_SNAKE);
		}
		if (i>0)
		{
			move(snake[i].y, snake[i].x);
			addch(SNAKE_CHAR);
		}
		i++;
	}
}

// Helper method for shifting snake parts
void shiftSnake()
{
	int i = 0;
	for (i = snakeLength - 1; i >= 0; i--)
	{
		snake[i + 1] = snake[i];
	}
}

// Helper method for the snake movement that moves snake head in a desired direction
void addHead()
{
	SnakePart origHead = snake[0];
	shiftSnake();
	switch (direction)
	{
	case UP:
		origHead.y--;
		break;
	case DOWN:
		origHead.y++;
		break;
	case LEFT:
		origHead.x--;
		break;
	case RIGHT:
		origHead.x++;
		break;
	}
	snake[0] = origHead;
}

// Helper method for snake movement that cuts the end of the snake
void removeTail()
{
	mvaddch(snake[snakeLength].y, snake[snakeLength].x, ' ');
	snake[snakeLength].x = -1;
	snake[snakeLength].y = -1;
}

// Refresh snake movement
void moveSnake()
{
	addHead();
	checkGame();
	mvaddch(snake[0].y, snake[0].x, HEAD_SNAKE);
	if (snake[0].x == food.x && snake[0].y == food.y)
	{
		snakeLength++;
		addFood();
	}
	else
	{
		removeTail();
	}
}

// Recognize snake control
void setDirection(char c)
{
	switch (c)
	{
	case 'w':
		if (direction != DOWN)
		{
			direction = UP;
		}
		break;
	case 's':
		if (direction != UP)
		{
			direction = DOWN;
		}
		break;
	case 'd':
		if (direction != LEFT)
		{
			direction = RIGHT;
		}
		break;
	case 'a':
		if (direction != RIGHT)
		{
			direction = LEFT;
		}
		break;
	}
}

// Draw the winner screen
void showWinner()
{
	clear();
	mvprintw(row / 2, col / 2 - strlen(WIN_MSG) / 2, WIN_MSG);
	refresh();
}

// Draw the welcome screen
void showWelcome()
{
	clear();
	mvprintw(row / 2, col / 2 - strlen(WELCOME_MSG) / 2, WELCOME_MSG);
	mvprintw(row - 2, col - strlen(CREATER_MSG) - 2, CREATER_MSG);
	refresh();
}

// Draw the nextlevel screen
void showNextLevel()
{
	clear();
	mvprintw(row / 2, col / 2 - strlen(NEXTLVL_MSG) / 2, NEXTLVL_MSG);
	mvprintw(row - 2, col - strlen(CREATER_MSG) - 2, CREATER_MSG);
	refresh();
}

// Draw the welcome screen
void showYouLoose()
{
	clear();
	mvprintw(row / 2, col / 2 - strlen(LOST_MSG) / 2, LOST_MSG);
	mvprintw(row - 2, col - strlen(CREATER_MSG) - 2, CREATER_MSG);
	refresh();
}
void showExit()
{
	clear();
	mvprintw(row / 2, col / 2 - strlen(EXIT_MSG) / 2, EXIT_MSG);
	mvprintw(row - 2, col - strlen(CREATER_MSG) - 2, CREATER_MSG);
	refresh();
}

// Draw the level walls
void drawLevel()
{
	//Right/Left
	for (int i = 0; i<row; i++)
	{
		mvaddch(i, 0, WALL_CHAR);
		mvaddch(i, col - 1, WALL_CHAR);
	}
	//Head/Down
	for (int i = 1; i<col - 1; i++)
	{
		mvaddch(0, i, WALL_CHAR);
		mvaddch(row - 1, i, WALL_CHAR);
	}
	//Barrier/blocks
	//1
	if (snakeLevel >= 2)
	{
		for (int i = 10; i<row - 10; i++)
		{
			mvaddch(i, 10, WALL_CHAR);
			mvaddch(i, col - 10, WALL_CHAR);
			for (int i = 5; i<col - 5; i++)
			{
				if (i <= 30 || i >= col - 30)
				{
					mvaddch(4, i, WALL_CHAR);
					mvaddch(row - 5, i, WALL_CHAR);
				}
			}
		}

	}
	//2
	if (snakeLevel >= 4)
	{
		for (int i = 20; i<col - 19; i++)
		{
			mvaddch(row / 3, i, WALL_CHAR);
			mvaddch((row / 3) * 2 - 1, i, WALL_CHAR);
			for (int i = 10; i<row - 10; i++)
			{
				if (i <= 16 || i >= 20)
				{
					mvaddch(i, 20, WALL_CHAR);
					mvaddch(i, col - 20, WALL_CHAR);
				}
			}
		}
	}
	//barrier v 1
	if (snakeLevel >= 6)
	{
		for (int i = 9; i<row - 9; i++)
		{
			mvaddch(i, 14, WALL_CHAR);
			mvaddch(i, col - 15, WALL_CHAR);
			for (int i = 5; i<col - 5; i++)
			{
				if (i <= 9 || i >= col - 10)
				{
					mvaddch(8, i, WALL_CHAR);
					mvaddch(row - 9, i, WALL_CHAR);
				}
			}
		}
	}
	//Center/v2
	if (snakeLevel >= 8)
	{
		for (int i = 28; i<col - 28; i++)
		{
			mvaddch(10, i, WALL_CHAR);
			mvaddch(13, i, WALL_CHAR);
		}
	}
	mvprintw(row, col - strlen(CREATER_MSG) - 2, CREATER_MSG);
	mvprintw(row, 2, "Snake LVL %d  |  Left to eat %d | Speed Snake %d", snakeLevel, snakelvlup - snakeLength, snakespeed);

}

// Check on a game state. Checked after every game step (see main())
void checkGame()
{
	if (snakeLevel == 10)
	{
		showWinner();
		msleep(3000);
		exit(0);
	}
	if ((mvinch(snake[0].y, snake[0].x) & A_CHARTEXT) == WALL_CHAR)
	{
		showYouLoose();
		msleep(3000);
		exit(0);
	}

	int i = 1;
	while (snake[i].x != -1 && snake[i].y != -1)
	{
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
		{
			showYouLoose();
			msleep(2000);
			exit(0);
		}
		i++;
	}
}

void menuGame()
{
	const char items[2][11] =
	{
		"Start Game",
		"Exit"
	};

	unsigned choice = 0; //Выбор пользователя
	char menu = ' ';

	while (offon == 0)
	{
		clear();
		for (unsigned i = 0; i < 2; i++) //Проходим по всем элементам меню
		{
			if (i == choice) //Если текущий элемент совпадает с выбором пользователя
			{
				move(row / 2 - i, col / 2 - strlen(items[i]) / 2);
				addch('>' | A_BOLD | A_UNDERLINE); //Выводим указатель
			}
			else
			{
				move(row / 2 - i, col / 2 - strlen(items[i]) / 2);
				addch(' '); //Иначе выводим " ", для равновесия
			}
			printw("%s %d\n", items[i], i);
			mvprintw(row - 2, col - strlen(CREATER_MSG) - 2, CREATER_MSG);
		}
		menu = getch();
		//Получаем нажатие пользователя
		switch (menu)
		{
		case 's':
			if (choice) //Если возможно, переводим указатель вверх
				choice--;
			break;
		case 'w':
			if (choice != 2) //Если возможно, переводим указатель вниз
				choice++;
			break;
		case 'f':
			if (choice == 1)
			{
				offon++;
				showExit();
				exit(0);
				break;
			}
			if (choice == 0)
			{
				offon++;
				break;
			}
		}
	}
}

// Game init function
int main()
{
	char c;

	// Main game loop
	while (1)
	{
		if (welcome == 1 || welcome == 2)
		{
			initGame();
			if (welcome == 2)
			{
				showWelcome();
				msleep(2);
				welcome = 0;
			}
			if (uplvl == 1)
			{
				showNextLevel();
				msleep(2);
				snakespeed -= 15;
				snakelvlup += 3;
				uplvl--;
				welcome--;
			}
			menuGame();
			clear();
			initSnake();
			drawLevel();
			drawSnake();
			addFood();
			refresh();
			msleep(1);
		}
		timeout(snakespeed);
		c = getch();
		setDirection(c);
		clear();
		drawLevel();
		moveSnake();
		drawSnake();
		drawFood();
		checkGame();
		refresh();
		if (snakeLength == snakelvlup)
		{
			welcome = 1;
			snakeLevel++;
			uplvl = 1;
		}
	}
}
