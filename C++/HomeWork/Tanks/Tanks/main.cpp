

#include <cstdlib>
#include <iostream>
#include "color.h"
#include <conio.h>

using namespace std;
using namespace Petter;

void title();
void credits();
void backGround();
void instructions();
int menu(char arrayGrid[][21]);
void displayGrid(char arrayGrid[][21]);
void gamePlay();
void yourTank();
void yourTankRotate();
void compTank();
void compTankRotate();
void stats();
void compStats();
void yourShootL();
void compShootL();
//void shootG();
void shieldLeft();
void move();
void hitLaser();
//void hitGrenade();
void direction();
void yourTankFace();

char arrayGrid[21][21];
int yourTankY = 2;
int yourTankX = 2;
int compTankY = 19;
int compTankX = 19;
int action;
int compShield; // HP
int compMove; // actions per a turn
int compWeapon; // +damage
int compRange; // how far weapon can shoot
int compTotal = compRange + compShield + compWeapon + compMove;
int yourShield;// HP
int yourMove; // actions per a round
int yourWeapon; // +damage
int yourRange; // how far your weapon shoots
int yourFace;

int main(int argc, char *argv[])
{
	//yourTank;
	//compTank;

	char arrayGrid[21][21] = {
		{ 201, 205, 209, 205, 209, 205, 209, 205, 209, 205, 209, 205, 209, 205, 209, 205, 209, 205, 209, 205, 187 },
		{ 186, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 186 },
		{ 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182 },
		{ 186, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 186 },
		{ 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182 },
		{ 186, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 186 },
		{ 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182 },
		{ 186, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 186 },
		{ 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182 },
		{ 186, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 186 },
		{ 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182 },
		{ 186, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 186 },
		{ 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182 },
		{ 186, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 186 },
		{ 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182 },
		{ 186, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 186 },
		{ 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182 },
		{ 186, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 186 },
		{ 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182 },
		{ 186, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 179, ' ', 186 },
		{ 200, 205, 207, 205, 207, 205, 207, 205, 207, 205, 207, 205, 207, 205, 207, 205, 207, 205, 207, 205, 188 },
	};


	title();
	credits();
	cout << endl;
	cout << endl;
	menu(arrayGrid);


	system("PAUSE");
	return EXIT_SUCCESS;
}
void title()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t" << RED << " WELCOME TO M.I.M.E WARS!!!!!!!" << NORMAL << endl;
}
void credits()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\tCreated by: Michael Meyer" << endl;
	cout << "\t\t\tWith Help from: Mountain Dew" << endl;
}
int menu(char arrayGrid[][21])
{
	char choice;

	do
	{


		cout << "                                 :[b]ATTLE!:   " << endl;
		cout << "                                               " << endl;
		cout << "                                :[S]STORY LINE:" << endl;
		cout << "                                               " << endl;
		cout << "                               :[i]NSTRUCTIONS:" << endl;
		cout << "                                               " << endl;
		cout << "                              :[E]XIT(chicken!?):    " << endl;

		choice = getch(); // calls for input
		switch (choice)
		{
		case 'b':
		{
					gamePlay();
		}
			break;
		case 's':
		{
					backGround();
		}
			break;
		case 'i':
		{
					instructions();
		}
			break;
		case 'e':
			break;
		}
	} while (choice != 'e');

	return 0;
}

void instructions()
{
	cout << "\t\t\t\t Instructions" << endl << endl << endl;

	cout << "Player controls:" << endl;
	cout << "W key: Progress the M.I.M.E forward, towards the way they are facing." << endl;
	cout << "A key: Rotates the M.I.M.E left." << endl;
	cout << "D key: Rotatest the M.I.M.E Counter right." << endl;
	cout << "E key: Chooses to fire the M.I.M.E's Lazer." << endl;
	//cout << "Q key: Chooses to lob a M.I.M.E's Grenade." << endl;
}
void backGround()
{
	cout << "\t\t\t\t Introduction" << endl << endl << endl;
	cout << "\tDuring the third World War a new breed of warefare was brought to life. M.I.M.E's were born to be a slave of men.";
	Sleep(4000);
	cout << " M.I.M.E, Mechines In Main Engagement, were a far more advance design of A.I.(Artificial Intelegence).";
	Sleep(4000);
	cout << "There mechines   were designed to lower human casualties, but instead turned and increase the   death toll.";
	cout << endl;
	Sleep(4000);
	cout << "\tWhen the M.I.M.Es turned, it was nothing more then a silent killing of  those around them.";
	Sleep(4000);
	cout << "Man was once again forced back into traditional warfare of    opertaing there own mechines and demise.";
	cout << endl;
	cout << endl;
	cout << endl;
	Sleep(4000);
	cout << "Who will win!?!?.........";
	cout << endl;
	cout << endl;
}



void displayGrid(char arrayGrid[][21])    //create grid
{
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{

			cout << arrayGrid[i][j];
		}
		cout << endl;
	}
}

void gamePlay()
{
	stats();
	cout << endl;
	displayGrid(arrayGrid);
	cout << endl;
	shieldLeft();
	cout << endl;
	direction();
	cout << endl;
	cout << endl;
	move();
}



