
#include "Config.h"
#include "defines.h"
#include "GameLogic.h"

BOOL IsActionPossible(char pPiece[][HPieceBlocks], int PosX, int PosY) {

	int x, y, bX;

	for (y = 0; y < VPieceBlocks; y++, PosY++) {

		for (x = 0, bX = PosX; x < HPieceBlocks; x++, bX++) {

			if (pPiece[y][x] == 1) { //not empty block

				if ((PosY >(BoardHeight - 1)) || (bX >(BoardWidth - 1)) || (bX < 0)) { //goes outside the borders

					return FALSE;
				}

				if (Board[PosY][bX] == 1) { //collision

					return FALSE;
				}
			}
		}
	}


	return TRUE;
}

void DeleteLines() {

	int x, y, bY;

	for (y = 0; y<BoardHeight; y++) {

		for (x = 0; x<BoardWidth; x++) {

			if (Board[y][x] != 1) { break; }
		}


		if (x == BoardWidth) {

			//Move all above lines down
			for (bY = y; bY>0; bY--) {

				for (x = 0; x<BoardWidth; x++) {

					Board[bY][x] = Board[bY - 1][x];
				}
			}
		}
	}
}

BOOL SaveCurPiece() { //return TRUE on collision

	int PosX, PosY, x, y;

	for (PosY = CurPiece.PosY, y = 0; y<VPieceBlocks; PosY++, y++) {

		for (PosX = CurPiece.PosX, x = 0; x<HPieceBlocks; PosX++, x++) {

			if (CurPiece.Piece[y][x] == 1) {
				if (Board[PosY][PosX] == 1) { return TRUE; }
				Board[PosY][PosX] = CurPiece.Piece[y][x];
			}
		}
	}

	return FALSE;
}

void PushRandomPiece() {


	memset(&CurPiece, 0x00, sizeof(CurPiece));
	memcpy(CurPiece.Piece, ClassicPieces[rand() % 7], (HPieceBlocks*VPieceBlocks));
	CurPiece.PosX = ((BoardWidth / 2) - (HPieceBlocks / 2));
}

void ClearBoard() {

	int x, y;

	//Zero the entire board
	for (y = 0; y<BoardHeight; y++) {

		for (x = 0; x<BoardWidth; x++) {

			Board[y][x] = 0;
		}
	}
	///////////////////////
}

void DrawBoard() {

	BOOL bFound;
	int x, y, PosX, PosY, i;
	char Piece[HPieceBlocks][VPieceBlocks];
	HBRUSH hBrush, hCurPieceBrush, hSavedPiecesBrush;


	hCurPieceBrush = CreateSolidBrush(FallingPieceColor);
	hSavedPiecesBrush = CreateSolidBrush(SavedPiecesColor);

	//Clear the board bitmap
	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	FillRect(hDCMain, &RectWndMain, hBrush);
	DeleteObject(hBrush);
	///////////////////////////////////


	EnterCriticalSection(&crsCurPiece);
	PosX = CurPiece.PosX;
	PosY = CurPiece.PosY;
	memcpy(Piece, CurPiece.Piece, (HPieceBlocks*VPieceBlocks));
	LeaveCriticalSection(&crsCurPiece);

	//Draw current piece
	for (y = 0, i = 0; y<HPieceBlocks; y++) {

		for (x = 0, bFound = FALSE; x<VPieceBlocks; x++) {

			if (Piece[y][x] == 1) {
				bFound = TRUE;
				DrawBlock(hDCMain, (x + PosX), (y + PosY - i), hCurPieceBrush);
			}
		}
		if (bFound == FALSE) { i++; }
	}

	//Draw already saved pieces
	for (y = 0; y<BoardHeight; y++) {

		for (x = 0; x<BoardWidth; x++) {

			if (Board[y][x] == 1) {

				DrawBlock(hDCMain, x, y, hSavedPiecesBrush);
			}
		}
	}

	DeleteObject(hCurPieceBrush);
	DeleteObject(hSavedPiecesBrush);
}

void DrawBlock(HDC hdc, int x, int y, HBRUSH hBrush) {

	RECT rect;


	rect.top = y * BlockSize;
	rect.left = x * BlockSize;
	rect.bottom = rect.top + BlockSize;
	rect.right = rect.left + BlockSize;

	FillRect(hdc, &rect, hBrush);
}

void rotateLeft(int maxX, int maxY) { //rotate left

	int rX, rY, X, Y;


	for (Y = maxY, rX = 0; Y>0; Y--, rX++) {

		for (X = 0, rY = 0; X<maxX; X++, rY++) {

			CurPiece.rotatedPiece[rY][rX] = CurPiece.Piece[Y - 1][X];
		}
	}
}

void rotateRight(int maxX, int maxY) { //rotate right

	int rX, rY, X, Y;


	for (Y = maxY, rX = 0; Y>0; Y--, rX++) {

		for (X = maxX, rY = (maxY - 1); X>0; X--, rY--) {

			CurPiece.rotatedPiece[rX][rY] = CurPiece.Piece[X - 1][Y - 1];
		}
	}
}


void UpdateScreen() {

	InvalidateRect(hWndMain, NULL, FALSE);
}