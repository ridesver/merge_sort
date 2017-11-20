#include <iostream>
#include <sstream>

using namespace std;

bool read(int * a, int & b)
{
	cout << "Enter the elements: \n";
	string str;
	getline(cin, str);
	istringstream stream(str);
	for (int i = 0; i < b; ++i)
	{
		if (!(stream >> a[i]))
		{
			cout << "An error has occured while reading input data." << endl;
			return false;
		}
	}
	return true;
}

void merge_sort(int * a, int first, int last)
{
	if (first < last)
	{
		int part = (first + last) / 2;
		merge_sort(a, first, part);
		merge_sort(a, part + 1, last);
		int * A = new int[last - first + 1];
		int i = 0;
		int F = first;
		int L = part + 1;
		while (F <= part && L <= last)
		{
			if (a[F] < a[L])
				swap(A[i], a[F++]);
			else
				swap(A[i], a[L++]);
			i++;
		}
		while (L <= last)
		{
			swap (A[i], a[L++]);
			i++;
		}
		while (F<= part)
		{
			swap(A[i], a[F++]);
			i++;
		}
		for (i = 0; i < last - first + 1; i++)
		{
			swap(a[first + i], A[i]);
		}
		delete[] A;
	}
}

int main()
{
	int b;
	string k;
	cout << "Enter the number of elements: \n";
	getline(cin, k);
	istringstream stream(k);
	if (!(stream >> b))
	{
		cout << "An error has occured while reading input data." << endl;
		return -1;
	}
	int * a = new int[b];
	if (read(a, b))
	{
		cout << "Result: \n";
		merge_sort(a, 0, b - 1);
		for (int i = 0; i < b; i++)
		{
			cout << a[i] << " ";
		}

		delete[] a;
		return 0;
	}
}
