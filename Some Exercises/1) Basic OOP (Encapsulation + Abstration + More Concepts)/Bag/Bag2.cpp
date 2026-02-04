#include <iostream>

using namespace std;

class Bag{
		int size, cSize;
		int *x;
		void resize(){
			int *t = new int[size + size];
			for (int i = 0 ; i < size ; i++)
				t[i] = x[i];
			delete []x;
			x = t;
			size += size;
		}
		void clear(){	
			delete []x;
			x = nullptr;
			cSize = size = 0;
		}
		Bag& copy(const Bag& b){
			x = new int[b.size];
			for (int i = 0 ; i < b.cSize ; i++)
				x[i] = b.x[i];
			size = b.size;
			cSize = b.cSize; 
			return *this;
		}
	public:
		Bag(int s = 10){	
			size = s;
			cSize = 0;
			x = new int[size];
		}
		Bag(const Bag& b){
			copy(b);
		}
		Bag& operator = (const Bag &b){
			clear();
			return copy(b);
		}
		void show() const{	
			for (int i = 0 ; i < cSize ; i++)
				cout << x[i] << ' ';
			cout << "\n";				
		}
		Bag& operator += (int x){
			if (cSize == size)	resize();
			this -> x[cSize++] = x;
			return *this;			
		}
		Bag& operator --(){
			if (cSize > 0)
				cSize--;
			return *this;
//This does not actually deallocate the size , for doing that , you should write a function void shrink() and assign values again one more time specifically rather than using resize function
		}
		bool operator > (const Bag &b){
			int sum1 = 0, sum2 = 0;
			for (int i = 0 ; i < cSize ; i++)	sum1 += x[i];
			for (int j = 0 ; j < b.cSize ; j++)	sum2 += b.x[j];
			 return sum1 > sum2;  // 
		}
		int& operator [](int index){
			if (index < cSize)	return x[index];
			//return -99999999;
//Return type here can be * and we can use return &x[index] , and in main() while calling , we write *b[i] = value
//If we don't specify & or * then this will become an rvalue , and rvalue can't be returned so we use & and * to make it lvalue
		}
		~Bag(){	clear();			}
};
int main(){
	Bag b1;
	b1 += 12;
	b1 += 23;
	b1 += 2;
	b1 += 45;
	b1.show();
	Bag b2 = b1, b3 = b1;
	b2 += 40;
	--b3;
	cout << b1[2] << '\n';
	b1[1] = 100;
	b1.show();
	return 0;
}