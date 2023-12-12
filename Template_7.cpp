#include <iostream>
using namespace std;

template <typename T> 
class Array 
{
    private:
        T* ptr;
        int size;

    public:
        Array(T arr[], int s);
        void print();
};

template <typename T> Array<T>::Array(T arr[], int s)
{
	ptr = new T[s];
	size = s;
	for (int i = 0; i < size; i++)
		ptr[i] = arr[i];
}

template <typename T> void Array<T>::print()
{
	for (int i = 0; i < size; i++)
		cout << " " << *(ptr + i);
	cout << endl;
}

int main()
{
	int arr1[5] = { 1, 2, 3, 4, 5 };
    char arr2[5] = {'A', 'B', 'C', 'D', 'E'};
	Array<int> a(arr1, 5);
    Array<char> b(arr2, 5);
	a.print();
	b.print();
	return 0;
}
