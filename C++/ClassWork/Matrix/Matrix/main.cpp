#include<windows.h>

int main()
{
	// �������� DC ��� ���������
	HWND hWnd = GetConsoleWindow();

	HDC hDC = GetDC(hWnd);

	// �������� ������ ���������� ������� ����
	RECT rc;
	GetClientRect(hWnd, &rc);

	// ������� Pen
	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));

	// �������� ���� Pen � DC, ���������� ������ Pen
	HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);

	// ���������� ����� ��������� � ����� ������� ���� ����
	MoveToEx(hDC, rc.left, rc.top, NULL);
	// ������ ����� � ������ ������ ����
	LineTo(hDC, rc.right, rc.bottom);

	// �������� ������ Pen � DC (����������� ���� Pen �� DC)
	SelectObject(hDC, hOldPen);

	// ������� Pen
	DeleteObject(hPen);

	// ����������� DC
	ReleaseDC(hWnd, hDC);

	system("PAUSE");
}