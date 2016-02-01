
#include <windows.h>

void ClearBoard();
void DrawBoard();
void PushRandomPiece();
void UpdateScreen();
BOOL SaveCurPiece();
void DeleteLines();
BOOL IsActionPossible(char pPiece[][HPieceBlocks], int PosX, int PosY);
void DrawBlock(HDC hdc, int x, int y, HBRUSH hBrush);
void rotateRight(int maxX, int maxY);
void rotateLeft(int maxX, int maxY);
BOOL IsGameOver();