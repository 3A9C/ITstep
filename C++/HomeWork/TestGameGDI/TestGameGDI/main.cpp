
#include <windows.h>

#include "Config.h"
#include "defines.h"
#include "GameLogic.h"


BOOL InitInstance(HANDLE hInstance);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {

	MSG msg;
	int dwRefresh;
	LARGE_INTEGER LargeInt;


	if (InitInstance(hInstance) == FALSE) { return FALSE; }

	//Init random seed
	QueryPerformanceCounter(&LargeInt);
	srand(LargeInt.LowPart);
	////////////////////////////////////////

	InitializeCriticalSection(&crsCurPiece);

	ClearBoard();

	dwRefresh = GetTickCount();

	PushRandomPiece();
	DrawBoard();
	UpdateScreen();


	while (1) {

		if (PeekMessageA(&msg, NULL, 0, 0, PM_NOREMOVE) == TRUE) {

			if (GetMessageA(&msg, NULL, 0, 0) == FALSE) { return 0; }

			TranslateMessage(&msg);
			DispatchMessage(&msg);

		}
		else {


			if (GetTickCount() >= (DWORD)(dwRefresh + FallingPieceSpeed)) {

				DrawBoard();
				UpdateScreen();

				dwRefresh = GetTickCount();

				EnterCriticalSection(&crsCurPiece);

				if (IsActionPossible(CurPiece.Piece, CurPiece.PosX, CurPiece.PosY + 1) == TRUE) {

					CurPiece.PosY++;

				}
				else {

					if (SaveCurPiece() == TRUE) { MessageBoxA(NULL, "Game Over!", NULL, MB_OK); ExitProcess(0); }
					DeleteLines();
					PushRandomPiece();
				}

				LeaveCriticalSection(&crsCurPiece);

			}

			Sleep(100); //give that CPU some rest
		}
	}


	return 0;
}


BOOL InitInstance(HANDLE hInstance) {

	WNDCLASSEX wcex;
	RECT rect;
	int height, width;

	memset(&wcex, 0x00, sizeof(wcex));

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.hInstance = hInstance;
	wcex.lpszClassName = ClassName;

	RegisterClassExA(&wcex);


	//calculate required window width and height, taking in account the required client area and borders
	height = BoardHeight*BlockSize;
	width = BoardWidth*BlockSize;

	rect.left = 0;
	rect.top = 0;
	rect.bottom = height;
	rect.right = width;
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, FALSE, WS_EX_TOPMOST);

	height += ((rect.bottom - rect.top) - height);
	width += ((rect.right - rect.left) - width);
	/////////////////////////////////////////////////

	if ((hWndMain = CreateWindowExA(WS_EX_TOPMOST, ClassName, MainTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, hInstance, NULL)) == NULL) { return FALSE; }

	ShowWindow(hWndMain, SW_SHOW);
	UpdateWindow(hWndMain);

	return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	PAINTSTRUCT ps;
	HDC hdc;

	switch (message) {

	case WM_CREATE:

		hdc = GetDC(hWnd);

		GetClientRect(hWnd, &RectWndMain);

		hDCMain = CreateCompatibleDC(hdc);
		hBitmapMain = CreateCompatibleBitmap(hdc, RectWndMain.right, RectWndMain.bottom);
		SelectObject(hDCMain, hBitmapMain);

		ReleaseDC(hWnd, hdc);

		break;

	case WM_PAINT:

		hdc = BeginPaint(hWnd, &ps);

		BitBlt(hdc, RectWndMain.left, RectWndMain.top, RectWndMain.right, RectWndMain.bottom, hDCMain, 0, 0, SRCCOPY);

		EndPaint(hWnd, &ps);

		break;


	case WM_KEYDOWN:

		switch (wParam) {

		case VK_LEFT:

			EnterCriticalSection(&crsCurPiece);
			if (IsActionPossible(CurPiece.Piece, CurPiece.PosX - 1, CurPiece.PosY) == TRUE) {

				CurPiece.PosX -= 1;
			}
			LeaveCriticalSection(&crsCurPiece);

			break;

		case VK_RIGHT:

			EnterCriticalSection(&crsCurPiece);
			if (IsActionPossible(CurPiece.Piece, CurPiece.PosX + 1, CurPiece.PosY) == TRUE) {

				CurPiece.PosX += 1;
			}
			LeaveCriticalSection(&crsCurPiece);

			break;

		case VK_DOWN:

			EnterCriticalSection(&crsCurPiece);
			if (IsActionPossible(CurPiece.Piece, CurPiece.PosX, CurPiece.PosY + 1) == TRUE) {

				CurPiece.PosY += 1;
			}
			LeaveCriticalSection(&crsCurPiece);

			break;

		case 'A':

			EnterCriticalSection(&crsCurPiece);

			rotateLeft(VPieceBlocks, HPieceBlocks);

			if (IsActionPossible(CurPiece.rotatedPiece, CurPiece.PosX, CurPiece.PosY) == TRUE) {

				memcpy(CurPiece.Piece, CurPiece.rotatedPiece, (VPieceBlocks*HPieceBlocks));
			}

			LeaveCriticalSection(&crsCurPiece);

			break;

		case 'D':

			EnterCriticalSection(&crsCurPiece);

			rotateRight(VPieceBlocks, HPieceBlocks);

			if (IsActionPossible(CurPiece.rotatedPiece, CurPiece.PosX, CurPiece.PosY) == TRUE) {

				memcpy(CurPiece.Piece, CurPiece.rotatedPiece, (VPieceBlocks*HPieceBlocks));
			}

			LeaveCriticalSection(&crsCurPiece);

			break;

		default:
			break;
		}

		break;

	case WM_DESTROY:
		PostQuitMessage(0);

		break;

	case WM_ERASEBKGND:

		return FALSE;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);

	}

	return 0;
}