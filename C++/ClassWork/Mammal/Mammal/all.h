#include <string>

using namespace std;


//Voice 
class Animal
{
public:
	string name;
public:
	//�����������
	Animal(string name) {} //�������� ���������� ������������
	//����������
	~Animal() {}
	virtual void Voice() {} /* ����� �������� ��� �����������( ������������ - ����� ������ �������� �� ����������
						  (�� �������� �� ����� ����������), � � �������� ������) */
};
//Voice 

class Mammal : Animal {
public:
	Mammal(string name) :Animal(name) {}
	virtual void voice() {}
};

class Flyers
{
public:
	string fly;
public:
	//�����������
	Flyers(string fly_) {} //�������� ���������� ������������
	//����������
	~Flyers() {}
	virtual void Voice() {} /* ����� �������� ��� �����������( ������������ - ����� ������ �������� �� ����������
						  (�� �������� �� ����� ����������), � � �������� ������) */
};






//�������� � �������
class Lupus : public Mammal {
public:
	Lupus() : Mammal("Yo Shy") {}
};
//�������� � �������

//�������� ��������
class Bird : public Animal, public Flyers {
public:
	Bird() : Animal("Soka"), Flyers("10m") {}
};

class Bat : public Mammal, public Flyers {
public:
	Bat() : Mammal("Soka"), Flyers("10m") {}
};
//�������� ��������

//��������

class Helicopter : public Flyers {
public:
	Helicopter() : Flyers("500m") {}
};

//��������
