#pragma comment(lib, "user32")

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

// Global variables

// The main window class name.
static TCHAR szWindowClass[] = _T("calculator3x3");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Калькулятор умножение матриц 3х3");

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

	hInst = hInstance; // Store instance handle in our global variable

	// The parameters to CreateWindow explained:
	// szWindowClass: the name of the application
	// szTitle: the text that appears in the title bar
	// WS_OVERLAPPEDWINDOW: the type of window to create
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
	// 500, 100: initial size (width, length)
	// NULL: the parent of this window
	// NULL: this application does not have a menu bar
	// hInstance: the first parameter from WinMain
	// NULL: not used in this application

	//Создаем окно
	HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 370, 400, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		MessageBox(NULL, _T("Call to CreateWindow failed!"), _T("Win32 Guided Tour"), NULL);
		return 1;
	}

	// The parameters to ShowWindow explained:
	// hWnd: the value returned from CreateWindow
	// nCmdShow: the fourth parameter from WinMain
	ShowWindow(hWnd,nCmdShow);

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
	PAINTSTRUCT ps;
	HDC hdc;

	wchar_t a11[10], a12[10], a13[10];
	wchar_t a21[10], a22[10], a23[10];
	wchar_t a31[10], a32[10], a33[10];

	wchar_t b11[10], b12[10], b13[10];
	wchar_t b21[10], b22[10], b23[10];
	wchar_t b31[10], b32[10], b33[10];

	wchar_t c11[10], c12[10], c13[10];
	wchar_t c21[10], c22[10], c23[10];
	wchar_t c31[10], c32[10], c33[10];


	static HWND Edit111, Edit112, Edit113, Edit121, Edit122, Edit123, Edit131, Edit132, Edit133;
	static HWND Edit211, Edit212, Edit213, Edit221, Edit222, Edit223, Edit231, Edit232, Edit233;
	static HWND Edit311, Edit312, Edit313, Edit321, Edit322, Edit323, Edit331, Edit332, Edit333;
	static HWND bResult;

	switch (message)
	{
		case WM_CREATE:
		{
		// 1 матрица
		// 1 массив
		Edit111 = CreateWindow(L"edit", L"1", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 20, 50, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit112 = CreateWindow(L"edit", L"2", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 60, 50, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit113 = CreateWindow(L"edit", L"3", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 100, 50, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		// 2 массив
		Edit121 = CreateWindow(L"edit", L"4", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 20, 90, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit122 = CreateWindow(L"edit", L"5", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 60, 90, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit123 = CreateWindow(L"edit", L"6", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 100, 90, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		// 3 массив
		Edit131 = CreateWindow(L"edit", L"7", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 20, 130, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit132 = CreateWindow(L"edit", L"8", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 60, 130, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit133 = CreateWindow(L"edit", L"9", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 100, 130, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);

		// 2 матрица
		// 1 массив
		Edit211 = CreateWindow(L"edit", L"1", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 220, 50, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit212 = CreateWindow(L"edit", L"2", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 260, 50, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit213 = CreateWindow(L"edit", L"3", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 300, 50, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		// 2 массив
		Edit221 = CreateWindow(L"edit", L"4", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 220, 90, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit222 = CreateWindow(L"edit", L"5", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 260, 90, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit223 = CreateWindow(L"edit", L"6", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 300, 90, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		// 3 массив
		Edit231 = CreateWindow(L"edit", L"7", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 220, 130, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit232 = CreateWindow(L"edit", L"8", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 260, 130, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit233 = CreateWindow(L"edit", L"9", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 300, 130, 30, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		
		//Создаем кнопку для умножения
		bResult = CreateWindow(TEXT("button"), TEXT("="), WS_CHILD | WS_VISIBLE, 130, 165, 90, 30, hWnd, (HMENU)100, ((LPCREATESTRUCT)lParam)->hInstance, 0);

		// 3 матрица
		// 1 массив
		Edit311 = CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 70, 235, 65, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit312 = CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 145, 235, 65, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit313 = CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 220, 235, 65, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		// 2 массив
		Edit321 = CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 70, 275, 65, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit322 = CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 145, 275, 65, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit323 = CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 220, 275, 65, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		// 3 массив
		Edit331 = CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 70, 315, 65, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit332 = CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 145, 315, 65, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		Edit333 = CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE, 220, 315, 65, 20, hWnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		break;
		}
		case WM_COMMAND:
			switch (wParam)
			{
			case  100:
				//матрица a
				GetWindowText(Edit111, a11, 10);
				GetWindowText(Edit112, a12, 10);
				GetWindowText(Edit113, a13, 10);
				GetWindowText(Edit121, a21, 10);
				GetWindowText(Edit122, a22, 10);
				GetWindowText(Edit123, a23, 10);
				GetWindowText(Edit131, a31, 10);
				GetWindowText(Edit132, a32, 10);
				GetWindowText(Edit133, a33, 10);
				//матрица b 
				GetWindowText(Edit211, b11, 10);
				GetWindowText(Edit212, b12, 10);
				GetWindowText(Edit213, b13, 10);
				GetWindowText(Edit221, b21, 10);
				GetWindowText(Edit222, b22, 10);
				GetWindowText(Edit223, b23, 10);
				GetWindowText(Edit231, b31, 10);
				GetWindowText(Edit232, b32, 10);
				GetWindowText(Edit233, b33, 10);
				
				int c1 = _wtoi(a11) * _wtoi(b11) + _wtoi(a12) * _wtoi(b21) + _wtoi(a13) * _wtoi(b31);
				_stprintf(c11, TEXT("%d"), c1);
				int c2 = _wtoi(a11) * _wtoi(b12) + _wtoi(a12) * _wtoi(b22) + _wtoi(a13) * _wtoi(b32);
				_stprintf(c12, TEXT("%d"), c2);
				int c3 = _wtoi(a11) * _wtoi(b13) + _wtoi(a12) * _wtoi(b23) + _wtoi(a13) * _wtoi(b33);
				_stprintf(c13, TEXT("%d"), c3);

				
				int c4 = _wtoi(a21) * _wtoi(b11) + _wtoi(a22) * _wtoi(b21) + _wtoi(a23) * _wtoi(b31);
				_stprintf(c21, TEXT("%d"), c4);
				int c5 = _wtoi(a21) * _wtoi(b12) + _wtoi(a22) * _wtoi(b22) + _wtoi(a23) * _wtoi(b32);
				_stprintf(c22, TEXT("%d"), c5);
				int c6 = _wtoi(a21) * _wtoi(b13) + _wtoi(a22) * _wtoi(b23) + _wtoi(a23) * _wtoi(b32);
				_stprintf(c23, TEXT("%d"), c6);


				int c7 = _wtoi(a31) * _wtoi(b11) + _wtoi(a32) * _wtoi(b21) + _wtoi(a33) * _wtoi(b31);
				_stprintf(c31, TEXT("%d"), c7);
				int c8 = _wtoi(a31) * _wtoi(b12) + _wtoi(a32) * _wtoi(b22) + _wtoi(a33) * _wtoi(b32);
				_stprintf(c32, TEXT("%d"), c8);
				int c9 = _wtoi(a31) * _wtoi(b13) + _wtoi(a32) * _wtoi(b23) + _wtoi(a33) * _wtoi(b33);
				_stprintf(c33, TEXT("%d"), c9);

				//матрица 3
				SetWindowText(Edit311, c11);
				SetWindowText(Edit312, c12);
				SetWindowText(Edit313, c13);
				SetWindowText(Edit321, c21);
				SetWindowText(Edit322, c22);
				SetWindowText(Edit323, c23);
				SetWindowText(Edit331, c31);
				SetWindowText(Edit332, c32);
				SetWindowText(Edit333, c33);
				break;
	}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 40, 25, TEXT("Матрица 1"), _tcslen(TEXT("Матрица 1")));
		TextOut(hdc, 240, 25, TEXT("Матрица 2"), _tcslen(TEXT("Матрица 2")));
		TextOut(hdc, 155, 210, TEXT("ОТВЕТ"), _tcslen(TEXT("Ответ")));
		EndPaint(hWnd, &ps);
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