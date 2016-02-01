#include<windows.h>

int main()
{
	// Получаем DC для рисования
	HWND hWnd = GetConsoleWindow();

	HDC hDC = GetDC(hWnd);

	// Получаем размер клиентской области окна
	RECT rc;
	GetClientRect(hWnd, &rc);

	// Создаем Pen
	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));

	// Выбираем свой Pen в DC, запоминаем старый Pen
	HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);

	// Перемещаем точку рисования в левый верхний угол окна
	MoveToEx(hDC, rc.left, rc.top, NULL);
	// Рисуем линию в правый нижний угол
	LineTo(hDC, rc.right, rc.bottom);

	// Выбираем старый Pen в DC (освобождаем свой Pen из DC)
	SelectObject(hDC, hOldPen);

	// Удаляем Pen
	DeleteObject(hPen);

	// Освобождаем DC
	ReleaseDC(hWnd, hDC);

	system("PAUSE");
}