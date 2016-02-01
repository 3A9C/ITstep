#include <Windows.h>

class Line{
	
public:
	static HDC hdc;
	Line(double x1_, double y1_, double x2_, double y2_) : x1(x1_), x2(x2_), y1(y1_), y2(y2_) {}
	double x1; double y1; double x2; double y2;

	void Draw()
	{
		MoveToEx(hdc, x1, y1, NULL);
		LineTo(hdc, x2, y2);


	}
};