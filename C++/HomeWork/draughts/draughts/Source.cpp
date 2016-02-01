#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

// Global variables

// The main window class name.
static TCHAR szWindowClass[] = _T("Shahki");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Шашки");

HINSTANCE hInst;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	hInst = hInstance;

	HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_SYSMENU | WS_MINIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, 596, 620, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		MessageBox(NULL, _T("Call to CreateWindow failed!"), _T("Win32 Guided Tour"), NULL);
		return 1;
	}

	// The parameters to ShowWindow explained:
	// hWnd: the value returned from CreateWindow
	// nCmdShow: the fourth parameter from WinMain
	ShowWindow(hWnd, nCmdShow);

	UpdateWindow(hWnd);

	// Main message loop:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//







LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//normal
	static HANDLE blackBitmap = LoadImage(NULL, L"img/black.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); // ключ LR_LOADFROMFILE  показывает, что мы загружаем image.bmp. Нужно, что бы картинка лежала в папке с твоими библиотеками
	static HANDLE whiteBitmap = LoadImage(NULL, L"img/white.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); // ключ LR_LOADFROMFILE  показывает, что мы загружаем image.bmp. Нужно, что бы картинка лежала в папке с твоими библиотеками
	//stain
	static HANDLE WhiteStainBitmap = LoadImage(NULL, L"img/whitestain.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); // ключ LR_LOADFROMFILE  показывает, что мы загружаем image.bmp. Нужно, что бы картинка лежала в папке с твоими библиотеками
	static HANDLE BlackStainBitmap = LoadImage(NULL, L"img/blackstain.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); // ключ LR_LOADFROMFILE  показывает, что мы загружаем image.bmp. Нужно, что бы картинка лежала в папке с твоими библиотеками
	//empty
	static HANDLE formBitmap = LoadImage(NULL, L"img/form.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); // ключ LR_LOADFROMFILE  показывает, что мы загружаем image.bmp. Нужно, что бы картинка лежала в папке с твоими библиотеками
	static HANDLE fromtomoveBitmap = LoadImage(NULL, L"img/fromtomove.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); // ключ LR_LOADFROMFILE  показывает, что мы загружаем image.bmp. Нужно, что бы картинка лежала в папке с твоими библиотеками


	static HWND button[MAX_PATH][MAX_PATH];
	static int board[8][8];
	switch (message)
	{
	case WM_CREATE:
	{
					  int x = 10;
					  int y = 10;

					  for (int k = 0; k < 8; k++)
					  {
						  for (int j = 0; j < 8; j++)
						  {
							  if ((k + j + 1) & 1)
							  {
								  continue;
							  }

							  if (j <= 2)
							  {
								  button[j][k] = CreateWindow(TEXT("button"), TEXT("black"), WS_CHILD | WS_VISIBLE | BS_BITMAP, x + k * 70, y + j * 70, 70, 70, hWnd, (HMENU)100, ((LPCREATESTRUCT)lParam)->hInstance, 0);
								  SendMessage(button[j][k], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)blackBitmap);
								  board[j][k] = 100;

							  }
							  else if (j <= 4)
							  {
								  button[j][k] = CreateWindow(TEXT("button"), TEXT("empty"), WS_CHILD | WS_VISIBLE | BS_BITMAP, x + k * 70, y + j * 70, 70, 70, hWnd, (HMENU)0, ((LPCREATESTRUCT)lParam)->hInstance, 0);
								  SendMessage(button[j][k], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
								  board[j][k] = 0;
							  }
							  else if (j > 4)
							  {
								  button[j][k] = CreateWindow(TEXT("button"), TEXT("white"), WS_CHILD | WS_VISIBLE | BS_BITMAP, x + k * 70, y + j * 70, 70, 70, hWnd, (HMENU)200, ((LPCREATESTRUCT)lParam)->hInstance, 0);
								  SendMessage(button[j][k], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)whiteBitmap);
								  board[j][k] = 200;
							  }

						  }

					  }

	}
		break;
		static int l, h;



	case WM_COMMAND:
	{
					   int k, j;
					   static int checkstep; // почему не работает без static
					   int x = 10;
					   int y = 10;
					   static int zuzu = 0;

					   for (k = 0; k < 8; k++)
					   {
						   for (j = 0; j < 8; j++)
						   {
							   if ((k + j + 1) & 1)
							   {
								   continue;
							   }
							   if ((HWND)lParam == button[j][k])
							   {
								   if (board[j][k] == 100) // black
								   {
									   zuzu = 1;
									   //MessageBox(hWnd, TEXT("черная"), TEXT(""), 0);
									   if (board[h][l] == 200)
									   {
										   if (button[h - 1][l + 1] == button[j][k])
										   {
											   if (board[h - 2][l + 2] == 0 && l + 2 < 8 && h - 2 >= 0)
											   {
												   board[h][l] = 0;
												   board[j][k] = 0;
												   board[h - 2][l + 2] = 200;
												   SendMessage(button[h][l], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
												   SendMessage(button[j][k], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
												   SendMessage(button[h - 2][l + 2], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)whiteBitmap);
												   zuzu = 0;
											   }
										   }
										   else if (button[h - 1][l - 1] == button[j][k])
										   {
											   if (board[h - 2][l - 2] == 0 && l - 2 >= 0 && h - 2 >= 0)
											   {
												   board[h][l] = 0;
												   board[j][k] = 0;
												   board[h - 2][l - 2] = 200;
												   SendMessage(button[h][l], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
												   SendMessage(button[j][k], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
												   SendMessage(button[h - 2][l - 2], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)whiteBitmap);
												   zuzu = 0;
											   }
										   }
										   else if (button[h + 1][l - 1] == button[j][k])
										   {
											   if (board[h + 2][l - 2] == 0 && l - 2 >= 0 && h + 2 < 8)
											   {
												   board[h][l] = 0;
												   board[j][k] = 0;
												   board[h + 2][l - 2] = 200;
												   SendMessage(button[h][l], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
												   SendMessage(button[j][k], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
												   SendMessage(button[h + 2][l - 2], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)whiteBitmap);
												   zuzu = 0;
											   }
										   }
										   else if (button[h + 1][l + 1] == button[j][k])
										   {
											   if (board[h + 2][l + 2] == 0 && l - 2 >= 0 && h + 2 < 8)
											   {
												   board[h][l] = 0;
												   board[j][k] = 0;
												   board[h + 2][l + 2] = 200;
												   SendMessage(button[h][l], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
												   SendMessage(button[j][k], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
												   SendMessage(button[h + 2][l + 2], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)whiteBitmap);
												   zuzu = 0;
											   }
										   }
									   }								   
									   if (zuzu == 1)
									   {
										   h = j;
										   l = k;
										   checkstep = 100;
										   zuzu = 0;
										   if (board[h + 1][l + 1] == 0 && h + 1 < 8 && l + 1 < 8)
										   {
											   SendMessage(button[h + 1][l + 1], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)fromtomoveBitmap);
										   }
										   if (board[h + 1][l - 1] == 0 && h + 1 < 8 && l - 1 >= 0)
										   {
											   SendMessage(button[h + 1][l - 1], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)fromtomoveBitmap);
										   }
										   if (board[h - 1][l + 1] == 200 && h - 1 >= 0 && l + 1 < 8)
										   {
											   SendMessage(button[h - 1][l + 1], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)fromtomoveBitmap);
										   }
										   if (board[h - 1][l - 1] == 200 && h - 1 >= 0 && l - 1 >= 0)
										   {
											   SendMessage(button[h - 1][l - 1], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)fromtomoveBitmap);
										   }
									   }
								   }
								   else if (board[j][k] == 0) // empty
								   {

									   if (checkstep == 100)
									   {
										   if (button[h + 1][l - 1] == button[j][k] || button[h + 1][l + 1] == button[j][k])
										   {
											   board[h][l] = 0;
											   board[j][k] = 100;
											   SendMessage(button[h][l], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
											   SendMessage(button[j][k], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)blackBitmap);
											   zuzu = 0;
										   }
									   }
									   else if (checkstep == 200)
									   {
										   if (button[h - 1][l - 1] == button[j][k] || button[h - 1][l + 1] == button[j][k])
										   {
											   board[h][l] = 0;
											   board[j][k] = 200;
											   SendMessage(button[h][l], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
											   SendMessage(button[j][k], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)whiteBitmap);
											   zuzu = 0;
										   }
									   }
									   h = NULL;
									   l = NULL;
									   checkstep = 0;
								   }

								   else if (board[j][k] == 200) //white
								   {
									   zuzu = 2;
									   //MessageBox(hWnd, TEXT("Нажата белая шашка"), TEXT(""), 0);
									   if (board[h][l] == 100)
									   {
										   if (button[h + 1][l + 1] == button[j][k])
										   {
											   if (board[h + 2][l + 2] == 0 && l + 2 < 8 && h + 2 < 8)
											   {
												   board[h][l] = 0;
												   board[j][k] = 0;
												   board[h + 2][l + 2] = 100;
												   SendMessage(button[h][l], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
												   SendMessage(button[j][k], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
												   SendMessage(button[h + 2][l + 2], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)blackBitmap);
												   zuzu = 0;
											   }
										   }
										   else if (button[h + 1][l - 1] == button[j][k])
										   {
											   if (board[h + 2][l - 2] == 0 && l - 2 >= 0 && h + 2 < 8)
											   {
												   board[h][l] = 0;
												   board[j][k] = 0;
												   board[h + 2][l - 2] = 100;
												   SendMessage(button[h][l], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
												   SendMessage(button[j][k], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
												   SendMessage(button[h + 2][l - 2], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)blackBitmap);
												   zuzu = 0;
											   }
										   }
										   else if (button[h - 1][l - 1] == button[j][k])
										   {
											   if (board[h - 2][l - 2] == 0 && l - 2 >= 0 && h - 2 >= 0)
											   {
												   board[h][l] = 0;
												   board[j][k] = 0;
												   board[h - 2][l - 2] = 100;
												   SendMessage(button[h][l], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
												   SendMessage(button[j][k], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
												   SendMessage(button[h - 2][l - 2], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)blackBitmap);
												   zuzu = 0;
											   }
										   }
										   else if (button[h - 1][l + 1] == button[j][k])
										   {
											   if (board[h - 2][l + 2] == 0 && l + 2 < 8 && h - 2 >= 0)
											   {
												   board[h][l] = 0;
												   board[j][k] = 0;
												   board[h - 2][l + 2] = 100;
												   SendMessage(button[h][l], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
												   SendMessage(button[j][k], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)formBitmap);
												   SendMessage(button[h - 2][l + 2], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)blackBitmap);
												   zuzu = 0;
											   }
										   }
									   }
									   if (zuzu == 2)
									   {
										   h = j;
										   l = k;
										   checkstep = 200;
										   zuzu = 0;
									   }

								   }
							   }
						   }
					   }
	}
	break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}