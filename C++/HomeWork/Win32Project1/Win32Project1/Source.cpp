#include <glut.h>
#include <math.h>
#include <utility>

using namespace std;

float MinWie = 480.0;
float MinHei = 480.0;
int i, j;
class Game
{
public:
	int selectedCellI_;
	int selectedCellJ_;

	enum Cell { EMPTY, BLACK, WHITE };
	Game(){
		for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board_[i][j] = EMPTY;
		for (int j = 0; j < 3; j++)
		for (int i = (j) % 2; i < 8; i += 2)
			board_[i][j] = BLACK;
		for (int j = 5; j < 8; j++)
		for (int i = (j) % 2; i < 8; i += 2)
			board_[i][j] = WHITE;
		int selectedCellI_(-1);
		int selectedCellJ_(-1);
	}
	Cell cell(int i, int j) const{
		return board_[i][j];
	}

	pair<int, int>selectedCell() const{
		return make_pair(selectedCellI_, selectedCellJ_);
	}
	void selectCell(int i, int j){
		if ((i >= 0) && (i<8) && (j >= 0) && (j<8) && (board_[i][j] == WHITE))
		{
			selectedCellI_ = i;
			selectedCellJ_ = j;
		}
		else
		{
			selectedCellI_ = -1;
			selectedCellJ_ = -1;

		}
	}

	void unselect(){

	}
	void move(int i, int j){

	}
private:
	typedef Cell Board[8][8];
	Board board_;




};

Game game;
/*selectedCellI_(-1);
selectedCellJ_(-1);*/
void chessboard()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();



	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) & 1)
			{
				glColor3f(1.0f, 1.0f, 1.0f);

			}
			else
			{
				glColor3f(0.0f, 0.0f, 0.0f);
			}
			glBegin(GL_QUADS);
			glVertex2f(i * 480 / 8, j * 480 / 8);
			glVertex2f((i + 1) * 480 / 8, j * 480 / 8);
			glVertex2f((i + 1) * 480 / 8, (j + 1) * 480 / 8);
			glVertex2f(i * 480 / 8, (j + 1) * 480 / 8);
			glEnd();

			switch (game.cell(i, j)){
			case Game::EMPTY:
				break;
			case Game::BLACK:

				glColor3f(0.3f, 0.3f, 0.3f);
				glBegin(GL_POLYGON);
				for (int z = 0; z < 5; z++)
				{
					float xx = 480 / 8 / 2 * cos(2 * 3.1415926*z / 5) + (i + 0.5f) * 480 / 8;
					float yy = 480 / 8 / 2 * sin(2 * 3.1415926*z / 5) + (j + 0.5f) * 480 / 8;

					glVertex2f(xx, yy);
				}
				glEnd();
				break;
			case Game::WHITE:
				pair<int, int>selected = game.selectedCell();
				if (selected.first == i && selected.second == j)
				{
					glColor3f(1.0, 0.0, 0.0);
				}
				else
				{
					glColor3f(0.7, 0.7, 0.7);
				}
				glColor3f(0.7f, 0.7f, 0.7f);
				glBegin(GL_POLYGON);
				for (int z = 0; z < 5; z++)
				{
					float xx = 480 / 8 / 2 * cos(2 * 3.1415926*z / 5) + (i + 0.5f) * 480 / 8;
					float yy = 480 / 8 / 2 * sin(2 * 3.1415926*z / 5) + (j + 0.5f) * 480 / 8;

					glVertex2f(xx, yy);
				}
				glEnd();
				break;
			}
		}
	}
	glPopMatrix();
	glutSwapBuffers();

}

void Init()
{
	glClearColor(0.75, 0.75, 0.75, 0.75);
	glColor3f(0.0f, 0.0f, 0.0f);
	//glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

}
void mouse(int button, int state, int i, int j)
{
	if (state == GLUT_UP)
	{
		const int xx = i / (480 / 8);
		const int yy = j / (480 / 8);

		if (game.selectedCell() != make_pair(-1, -1))
			game.selectCell(xx, yy);

	}
	else
	{
		//game.move(xx,yy);
		glutPostRedisplay();
	}
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(MinWie, MinHei);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("CHECKERS");

	Init();
	glOrtho(0.0, MinWie, MinHei, 0.0, -1.0, 1.0);
	glutDisplayFunc(chessboard);
	glutMouseFunc(mouse);

	glutMainLoop();
	return 0;
}