#include <iostream>
#include <time.h>
using namespace std;
class Array {
	int N;
	int* array;
public:
	Array();
	explicit Array(int);
	Array(const Array& Ar);
	//Array(int n);
	~Array();
	void Clear();
	void Print();
	void SetRnd(int min, int max);
	void Input();
};
//Array::Array(int n) :N(n), array(new int [n] {0}) {
Array::Array(int n) {
	N = n;
	array = new int [n] {0};
}
Array::Array(const Array& Ar) {
	N = Ar.N;
	array = new int[Ar.N];
	for (size_t i = 0; i < N; i++)
		array[i] = Ar.array[i];
}
Array::Array() {
	N = 0;
	array = nullptr;;
}
Array::~Array() {
	Clear();
}
void Array::Clear() {
	N = 0;
	delete[]array;
	array = nullptr;
}
void Array::Print() {
	for (size_t i = 0; i < N; i++)
		cout << array[i] << "\t";
	cout << endl;
}
void Array::SetRnd(int min, int max) {
	if (min > max)swap(min, max);
	for (int i = 0; i < N; i++)
		array[i] = min + rand() % (max - min + 1);
}
void Array::Input() {
	for (size_t i = 0; i < N; i++) {
		cout << "array[" << i << "] =";
		cin >> array[i];
	}
}
int main() {
	srand(time(0));
	Array mas(5);
	Array mas2 = mas;
	mas.Print();
	mas.SetRnd(-5, 5);
	mas.Print();
	mas.Input();
	mas.Print();


	cout << "The end\n";
}