#include <iostream>

using namespace std;

class Bag
{
	int size, cSize;
	int *x;
	void resize()
	{
		int *t = new int[size + size];
		for (int i = 0; i < size; i++)
			t[i] = x[i];
		delete[] x;
		x = t;
		size += size;
	}
	void clear()
	{
		delete[] x;
		x = nullptr;
		cSize = size = 0;
	}
	Bag &copy(const Bag &b)
	{
		x = new int[b.size];
		for (int i = 0; i < b.cSize; i++)
			x[i] = b.x[i];
		size = b.size;
		cSize = b.cSize;
	}

public:
	Bag(int s = 10)
	{
		size = s;
		cSize = 0;
		x = new int[size];
	}
	Bag(const Bag &b)
	{
		copy(b);
	}
	Bag &operator=(const Bag &b)
	{
		clear();
		return copy(b);
	}
	void show() const
	{
		for (int i = 0; i < cSize; i++)
			cout << x[i] << ' ';
		cout << "\n";
	}
	Bag &operator+=(int x)
	{
		if (cSize == size)
			resize();
		this->x[cSize++] = x;
		return *this;
	}
	Bag &operator--()
	{
		if (cSize > 0)
			cSize--;
		return *this;
//This does not actually deallocate the size , for doing that , you should write a function void shrink() and assign values again one more time specifically rather than using resize function
	}
	~Bag() { clear(); }
};
int main()
{
	Bag b;
	b += 12;
	b += 23;
	b += 2;
	b += 45;
	b.show();
	(--b).show();
	(--b).show();
	return 0;
}