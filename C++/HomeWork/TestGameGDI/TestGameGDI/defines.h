
#include <windows.h>


//Window
static char ClassName[] = "TetrisGDIWindowClass";
static char MainTitle[] = "Tetris Rocks!";


#define HPieceBlocks 4 //Horizontal blocks of piece
#define VPieceBlocks 4 //Vertical blocks of piece

static char ClassicPieces[7][4][4] = {

	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},


	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 0, 0 }
	},

	{

		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 1 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 1 },
		{ 0, 0, 0, 1 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 1 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 }
	}
};

typedef struct{

	char Piece[VPieceBlocks][HPieceBlocks];
	char rotatedPiece[VPieceBlocks][HPieceBlocks]; //used for temporary storage of rotated piece
	int PosX;
	int PosY;

}__FallingPiece;

char Board[BoardHeight][BoardWidth];
__FallingPiece CurPiece;

HWND hWndMain;
RECT RectWndMain;
HDC hDCMain;
HBITMAP hBitmapMain;
CRITICAL_SECTION crsCurPiece;
