template < class T>
class Vector
{
public:
	Vector() : elements(nullptr), size(0){}
	Vector(size_t size_, T initial) : size(size_) {
		elements = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			elements[i] = initial;
		}
	}
	~Vector() {
		delete[] elements;
	}
	T& operator[](size_t index) {
		if (index < size)
		{
			return elements[index];
		}
	}

private:
	T* elements;
	size_t size;
};