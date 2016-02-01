#pragma once


class String
{
private:
	char *s;
	int length;
public:
	void PrintStr() const; //���� ����� �� �������� ������
	const char *Find(const char *substr) const;


	//classwork
	void UpReg();
	bool FirstNChar(int n, String &result);
	bool EndNChar(int n, String &result);
	bool Substr(int n, int position, String &result);
	void DeleteSpace();

	const char *c_str() const{//������ ��� ������, inline-�����
		return s;
	}

	//���������� ��������� ������������
	void operator=(const String &source);
	String &operator+=(const String &source);
	//inline
	String operator+(const String &source) const{
		String res(*this);
		return res += source;
	}



	//ctor
	String();
	String(const char *p);
	String(char c, size_t n);
	String(const String &orig); //����������� �����������
	//dtor
	~String();
};

void PrintStr(String str);



inline int sqr(int x){
	return x*x;
}