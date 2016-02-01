class Matrix
{
private:
	int nstr, nstl;
	int **a;
public:
	Matrix(int m, int n);
	Matrix(int m, int n, int *b);
	~Matrix();
	Matrix operator+ (Matrix b);
	Matrix operator* (Matrix b);
	Matrix operator* (int c);
	Matrix operator= (Matrix b);
	Matrix operator+= (Matrix b);
	Matrix(const Matrix &T);
	Matrix & operator = (const Matrix &);
	void Print();
};