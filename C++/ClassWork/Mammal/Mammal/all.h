#include <string>

using namespace std;


//Voice 
class Animal
{
public:
	string name;
public:
	//конструктор
	Animal(string name) {} //передача параметров конструктора
	//деструктор
	~Animal() {}
	virtual void Voice() {} /* метод помечаем как виртуальный( динамический - адрес метода задается не изначально
						  (не известен на этапе компиляции), а в процессе работы) */
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
	//конструктор
	Flyers(string fly_) {} //передача параметров конструктора
	//деструктор
	~Flyers() {}
	virtual void Voice() {} /* метод помечаем как виртуальный( динамический - адрес метода задается не изначально
						  (не известен на этапе компиляции), а в процессе работы) */
};






//Животные с клыками
class Lupus : public Mammal {
public:
	Lupus() : Mammal("Yo Shy") {}
};
//Животные с клыками

//Летающие животные
class Bird : public Animal, public Flyers {
public:
	Bird() : Animal("Soka"), Flyers("10m") {}
};

class Bat : public Mammal, public Flyers {
public:
	Bat() : Mammal("Soka"), Flyers("10m") {}
};
//Летающие животные

//Вертушка

class Helicopter : public Flyers {
public:
	Helicopter() : Flyers("500m") {}
};

//Вертушка
