
//������������
class A //�����
{
public: // �������� ������
	int a, b; //������ ��������� ����������
	int ReturnSomething(); //����� ��������� ����������
private: // ������� ������ 
	int Aa, Ab; //������� ������
	void Do_Something(); //������� �����
};


//------------------------------------------------------------------------------------------------------------------

//������������
class A{    //������� �����
};

class B : public A{    //public ������������
};

class C : protected A{    //protected ������������
};

class Z : private A{    //private ������������
};
//����������� � ���������� ������������
class First // �������� ��� ������ Second
{
public:
	First()  { cout << ">>First constructor" << endl; } //�����������
	~First() { cout << ">>First destructor" << endl; } //����������
};

class Second : public First // �������� ��� ������ Third
{
public:
	Second()  { cout << ">Second constructor" << endl; } 
	~Second() { cout << ">Second destructor" << endl; }
};

class Third : public Second
{
public:
	Third()  { cout << "Third constructor" << endl; }
	~Third() { cout << "Third destructor" << endl; }
};

// ���������� ����
Third *th = new Third();
delete th;

// ��������� ������
/*
>>First constructor
>Second constructor
Third constructor

Third destructor
>Second destructor
>>First destructor
*/


//------------------------------------------------------------------------------------------------------------------

//������
class MyClass : public ParentClass // ParentClass � �����-������, ���� ������� �������
{
public:
	// �������� � ���� ������ �������� �� ����� ����� ���������
	MyClass(); // �����������
	~MyClass(); // ����������
protected:
	// �������� � ���� ������ �������� �� ������ � ��� ��������
private:
	// �������� � ���� ������ �������� ������ �� ������; ��� ������� ������� �� ���������
};

����� ������ �������� ����� ��������� ����������� ����� ������ �, ������������� ���������� ������ ��������� ��������� ������� :

MyClass myinstance;

��������� � ������ ������ :

myinstance.classmember



//------------------------------------------------------------------------------------------------------------------


//������
// �������� ���������� ������ ArrayList � ������ list
ArrayList list = new ArrayList();

// ���������� ����������� ������ Integer � ������ list
list.add(new Integer(1));
list.add(new Integer(2));
list.add(new Integer(3));



//------------------------------------------------------------------------------------------------------------------

//����������� � ����������

//����� ��������� :
1 ����������� � ����������, �� ������ ��������� � ������� public;
2 ��� ���������� ������������, ��� ������ ������������� �������� �� �����������, � ��� ����� � void!!!;
3 � ����������� ��� �� ��� ���� ������ ��� ������������� ��������, � ���� �� ����������� ������ ���������� ������� ����������;
4 ��� ������ � ������������ ������ ���� ���������;
5 ��� ����������� ��������� ����� ������������, �� � ���������� ~;
6 � ������ ��������� ��������� ��������� �������������, ���� ��� ����������.�����, �������� ������ 2 ������ ������, ����� �����������.���������� ����� �� ��������� �� ������������ ����������(��� ��� ���������� �������).���� �� �� �������� � ����������� ���������, �� ��������� ������������� �� ���������;
7 �������� �������� �� ��, ��� � ������ ����� ���� �������� ������ ���� ����������;


# include <iostream>
using namespace std;

class AB //�����
{
private:
	int a;
	int b;
public:
	AB()    //��� �����������:  1) � ������������ ��� ���� ������������� ��������! � ��� ����� void!!!
		//   2) ��� ������ ���� ����� ��� � � ������ (� ����� ������ AB)
	{
		a = 0;//�������� ��������� �������� ����������
		b = 0;
		cout << "������ ������������ ��� �������� ������ �������: " << endl;//� ����� �� �� ��������� �� �����
		cout << "a = " << a << endl;
		cout << "b = " << b << endl << endl;
	}

	void setAB() // � ������� ����� ������ ������� ��������� �������� �������� �������������
	{
		cout << "������� ����� ����� �: ";
		cin >> a;
		cout << "������� ����� ����� b: ";
		cin >> b;
	}

	void getAB() //������� �� ����� ���������� ��������
	{
		cout << "a = " << a << endl;
		cout << "b = " << b << endl << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	AB obj1;     //����������� ��������� �� ������ ����� (�� ����� �������� ������� ������)

	obj1.setAB();   //�������� ����� �������� ����������
	obj1.getAB();   //� ������� �� �� �����

	AB obj2;     //����������� ��������� �� ������ ����� (�� ����� �������� 2-�� ������� ������)
	return 0;
}

//------------------------------------------------------------------------------------------------------------------

//���������� ����������

class Integer
{
private:
	int value;
public:
	Integer(int i) : value(i)
	{}

	//������� +
	friend const Integer& operator+(const Integer& i);

	//������� -
	friend const Integer operator-(const Integer& i);

	//���������� ���������
	friend const Integer& operator++(Integer& i);

	//����������� ���������
	friend const Integer operator++(Integer& i, int);

	//���������� ���������
	friend const Integer& operator--(Integer& i);

	//����������� ���������
	friend const Integer operator--(Integer& i, int);
};

//������� ���� ������ �� ������.
const Integer& operator+(const Integer& i) {
	return i.value;
}

const Integer operator-(const Integer& i) {
	return Integer(-i.value);
}

//���������� ������ ���������� �������� ����� ����������
const Integer& operator++(Integer& i) {
	i.value++;
	return i;
}

//����������� ������ ���������� �������� �� ����������
const Integer operator++(Integer& i, int) {
	Integer oldValue(i.value);
	i.value++;
	return oldValue;
}

//���������� ������ ���������� �������� ����� ����������
const Integer& operator--(Integer& i) {
	i.value--;
	return i;
}

//����������� ������ ���������� �������� �� ����������
const Integer operator--(Integer& i, int) {
	Integer oldValue(i.value);
	i.value--;
	return oldValue;
}



//------------------------------------------------------------------------------------------------------------------




//����������� �������

// ��������� ������ ������������� ����������� �������
#include <iostream.h>
class Base {
public:
	virtual void who() { // ����������� ����������� �������
		cout << *Base\n";
	}
};
class first_d : public Base {
public:
	void who() { // ����������� who() ������������� � first_d
		cout << "First derivation\n";
	}
};
class seconded : public Base {
public:
	void who() { // ����������� who() ������������� � second_d
		cout << "Second derivation\n*";
	}
};
int main()
{
	Base base_obj;
	Base *p;
	first_d first_obj;
	second_d second_obj;
	p = &base_obj;
	p->who(); // ������ � who ������ Base
	p = &first_obj;
	p->who(); // ������ � who ������ first_d
	p = &second_ob;
	p->who(); // ������ � who ������ second_d
	return 0;
}

��������� ������ ��������� ��������� :

Base
First derivation
Second derivation





//------------------------------------------------------------------------------------------------------------------

//���������




#include <iostream>
using namespace std;

struct building     //������� ���������!
{
	char *owner;       //����� ����� ��������� ��� ���������
	char *city;        //�������� ������
	int amountRooms;   //���������� ������
	float price;       //����
};

int main()
{
	setlocale(LC_ALL, "rus");

	building apartment1;   //��� ������ ��������� � ����� ������, ������ ���������, building

	apartment1.owner = "�����"; //��������� ������ � ��������� � �.�.
	apartment1.city = "�����������";
	apartment1.amountRooms = 5;
	apartment1.price = 150000;

	cout << "�������� ��������: " << apartment1.owner << endl;
	cout << "�������� ��������� � ������: " << apartment1.city << endl;
	cout << "���������� ������: " << apartment1.amountRooms << endl;
	cout << "���������: " << apartment1.price << " $" << endl;

	return 0;
}


//------------------------------------------------------------------------------------------------------------------


//��������


ContainerType C; // ����� ����������� ��� ����������, �������� std::list<sometype>
//for (ContainerType::iterator it = C.begin(),end = C.end(); it != end; ++it) { ��� ����������� ���������
//(���� ��� ����� �������� ��������)
for (ContainerType::const_iterator it = C.begin(), end = C.end(); it != end; ++it) {
	std::cout << *it << std::endl;
}


ContainerType<ItemType> C; // ����� ����������� ��� ���������� ��������� ItemType
void ProcessItem(const ItemType& I) // �������, �������������� ������ ������� ���������
{
	std::cout << I << std::endl;
}

std::for_each(C.begin(), C.end(), ProcessItem); // ���� ���������




//------------------------------------------------------------------------------------------------------------------


//����������� ����

class foo {
private:
	int x; // ��� ���� � ��������. ������ � ���� �������� ������
	// �� ������� ������ ''foo''.
public:
	int y; //��� ���� � ��������. ������ � ���� �������� ��
	//������ ����� ���������. ������������� ��� �� ������.

	// ��� ��� ������ ([[�������� (����������������)#��������� �������|��������]]
	// � [[w:en:Mutator method|�������]]) ������������ ������ �
	// ��������� ���� x. ������������� ������ ������ ���.
	int get_x() { return x; };
	void set_x(int x) { this->x = x; };

	static int z; // ��� ����������� ����. ��� ����������� ������
	// foo �������, � �� ��� ��������.

	char a : 3; // ��� ������� ����. � ����� ��� ��������
	char b : 3; // 8 ���, �.�. ��� ����� ��������� � �����
	char c : 1; // ����� ������. ����� ������� ��������
	char d : 1; // ���������� � ��������� ����� ������.
};




//------------------------------------------------------------------------------------------------------------------


//�����

// ���� ���������� ������ CppStudio.cpp

#include <iostream>
using namespace std;
// ���������� ��������� ������ � ����� ��� ����������
#include "CppStudio.h"

CppStudio::CppStudio(int date_day, int date_month, int date_year) // ����������� ������
{
	setDate(date_day, date_month, date_year); // ����� ������� ��������� ����
}

void CppStudio::message() // ������� (����� ������) ��������� ��������� �� �����
{
	cout << "nwebsite: cppstudio.comntheme: Classes and Objects in C + +n";
}

void CppStudio::setDate(int date_day, int date_month, int date_year) // ��������� ���� � ������� ��.��.��
{
	day = date_day; // ������������� ����
	month = date_month; // ������������� �����
	year = date_year; // ������������� ���
}

void CppStudio::getDate() // ���������� ������� ����
{
	cout << "date: " << day << "." << month << "." << year << endl;
}


//------------------------------------------------------------------------------------------------------------------


//���������

// ���������������� ��������� �����������
const int ci1 = 6, ci7 = 7;

// ���������� ��������� ������������ � ������ ������
extern const int a;

int func(const char* arg){
	// ������ �� ������� ��������� arg
	// ������ ��������
	...
}


//------------------------------------------------------------------------------------------------------------------

//��������



for_each, ������� ������������ ����� �������� ������ �� ���������. (����� transform ��� ��������� "�� ������".)

find_if, ������� ������������ ����� �������� ������ �� ���������.

sort, lower_bound � ������ ��������� ���������� �� ��������� � ��������� ������.

��� �������� ����������� �� ���� ����������� ����������� ������� ����������� < � ����������� ������ - ���������.
C++

auto comp = [](const widget& w1, const widget& w2)
{ return w1.weight() < w2.weight(); }

sort(v.begin(), v.end(), comp);

auto i = lower_bound(v.begin(), v.end(), comp);

�����

���� ��������, ����������� ����� for �� ������ ��������� ��� ������ ���������, � �� ���������� ������� �����.copy, transform, count_if, remove_if � ������ �������� �� ������� �����, ��� ���������� �����, ��������� �� �������������� �������� � ��� ��������� ��������� ���� ��� ������.����� ����, ������ ��������� STL ����� ����������� ����������, ������� ������ �� ����� ������������.

������ ������� C++:
C++

for (auto i = strings.begin(); i != strings.end(); ++i) {
	:::
	:: :
}

auto i = v.begin();

for (; i != v.end(); ++i) {
	if (*i > x && *i < y) break;
}

����������� ����������� ���� C++ ��������� ������� :
C++

for_each(begin(strings), end(strings), [](string& s) {
	:::
	:: :
});
auto i = find_if(begin(v), end(v), [=](int i) { return i > x && i < y; });

����� "for" �� ������ ���������

���� for �� ������ ��������� �������� �������� ����� �++11, � �� ��������� STL.��� �� ����� �� ����������� ���������� � ���� ��������� � ������.���������� �� ��������� ����� for ������������ ����� ���������� ��������� ����� for � �������� ������� � ����������� �������� ������ ������, ����������� �������� � ���������� ��������.����������, ������ � ������� STL ������ ��� ������ for �� ���� ����������.����� �������� ���� ����� ��������� �������� ��� ����������������� ����, �������� ��������� ��������� :

����� begin, ������������ �������� � ������ ��������� � ����� end, ������� ���������� �������� � ����� ���������.

��������� � ��������� ���� ������� : operator*, operator!= � operator++ (������ ��������).

��� ������ ����� ������������ ����� ����� ��� ��������� �������.



//------------------------------------------------------------------------------------------------------------------


//��������� STL

http://ci-plus-plus-snachala.ru/?p=298


//------------------------------------------------------------------------------------------------------------------

//������� �������

http://cppstudio.com/post/5188/

//------------------------------------------------------------------------------------------------------------------


//�������� ��������������� ����������������
http://habrahabr.ru/post/142351/