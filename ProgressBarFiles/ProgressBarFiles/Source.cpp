﻿#include <windows.h>
#include <tchar.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
// Global variables

// The main window class name.
static TCHAR szWindowClass[] = _T("CreateFiles");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Копирования файла");

HINSTANCE hInst;
static HWND openfile, loadfile, go, edito, editl, hProgress;// дескриптор кнопки
ifstream input;
ofstream output;

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

	HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 600, 500, NULL, NULL, hInstance, NULL);

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


BOOL ParseALargeFile(HWND hwndParent, LPTSTR lpszFileName)
{
	RECT rcClient;  // Client area of parent window.
	int cyVScroll;  // Height of scroll bar arrow.
	HWND hwndPB;    // Handle of progress bar.
	HANDLE hFile;   // Handle of file.
	DWORD cb;       // Size of file and count of bytes read.
	LPCH pch;       // Address of data read from file.
	LPCH pchTmp;    // Temporary pointer.


	GetClientRect(hwndParent, &rcClient);

	cyVScroll = GetSystemMetrics(SM_CYVSCROLL);

	hwndPB = CreateWindowEx(0, L"PROGRESS_CLASS", (LPTSTR)NULL,
		WS_CHILD | WS_VISIBLE, rcClient.left,
		rcClient.bottom - cyVScroll,
		rcClient.right, cyVScroll,
		hwndParent, (HMENU)0, hInst, NULL);

	// Open the file for reading, and retrieve the size of the file. 

	hFile = CreateFile(lpszFileName, GENERIC_READ, FILE_SHARE_READ,
		(LPSECURITY_ATTRIBUTES)NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, (HANDLE)NULL);

	if (hFile == (HANDLE)INVALID_HANDLE_VALUE)
		return FALSE;

	cb = GetFileSize(hFile, (LPDWORD)NULL);

	// Set the range and increment of the progress bar. 

	// Parse the file. 
	pch = (LPCH)LocalAlloc(LPTR, sizeof(char)* 2048);

	pchTmp = pch;

	do {
		ReadFile(hFile, pchTmp, sizeof(char)* 2048, &cb, (LPOVERLAPPED)NULL);

		// TODO: Write an error handler to check that all the
		// requested data was read.
		//
		// Include here any code that parses the
		// file. 
		//  
		//  
		//  
		// Advance the current position of the progress bar by the increment.

	} while (cb);

	CloseHandle((HANDLE)hFile);

	DestroyWindow(hwndPB);

	return TRUE;
}

//Позволяет взять имя открываемого файла в стандартном диалоге Windows
int OpenDialog(HWND hWnd)
{
	OPENFILENAME ofn;
	TCHAR szFile[MAX_PATH];
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.hwndOwner = hWnd;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = TEXT("txt Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0");
	ofn.nFilterIndex = 1;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrFileTitle = NULL;
	ofn.lpstrDefExt = L"txt";
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (GetOpenFileName(&ofn))
	{
		SetWindowText(edito, ofn.lpstrFile);
		input.open(ofn.lpstrFile, ios_base::binary);
	}
	return 0;
}

int SaveDialog(HWND hWnd)
{
	OPENFILENAME ofn;
	TCHAR szFile[MAX_PATH];
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.hwndOwner = hWnd;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = TEXT("txt Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0");
	ofn.nFilterIndex = 1;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrFileTitle = NULL;
	ofn.lpstrDefExt = L"txt";
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (GetOpenFileName(&ofn))
	{
		SetWindowText(editl, ofn.lpstrFile);
		output.open(ofn.lpstrFile, ios_base::binary);
	}
	return 0;
}
int GoCopy(HWND hWnd)
{
	if (!input){ std::cerr << "File not found\n"; return -1; }

	/*while (getline(input, S))
		input.get(mas, 50);*/

	std::copy((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>(), std::ostreambuf_iterator<char>(output));

	input.close();
	output.close();
	MessageBox(hWnd, L"Комплитед", L"Завершено успешно", MB_OK);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
		// Parse the menu selections:
	case WM_CREATE:
	{
					  
					  edito = CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | LBS_STANDARD, 20, 40, 560, 30, hWnd, (HMENU)101, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
					  openfile = CreateWindow(L"button", L"Выбрать файл", WS_VISIBLE | WS_CHILD, 235, 75, 110, 40, hWnd, (HMENU)100, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
					  editl = CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | LBS_STANDARD, 20, 140, 560, 30, hWnd, (HMENU)201, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
					  loadfile = CreateWindow(L"button", L"Выбрать файл", WS_VISIBLE | WS_CHILD, 235, 175, 110, 40, hWnd, (HMENU)200, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
					  go = CreateWindow(L"button", L"Начать", WS_VISIBLE | WS_CHILD, 235, 250, 110, 40, hWnd, (HMENU)300, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
					  hProgress = CreateWindow(L"button", L"Начать", WS_VISIBLE | WS_CHILD, 235, 250, 110, 40, hWnd, (HMENU)300, ((LPCREATESTRUCT)lParam)->hInstance, NULL);

	break;
	}
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case 100:
			OpenDialog(hWnd);
			break;
		case 200:
			SaveDialog(hWnd);
			break;
		case 300:
			GoCopy(hWnd);
			break;
	}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 50, 25, TEXT("Выберете файл который будем копировать"), _tcslen(TEXT("Выбераем файл который будем копировать")));
		TextOut(hdc, 50, 125, TEXT("Выберете файл куда будем сохранять"), _tcslen(TEXT("Выберете файл куда будем сохранять")));
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