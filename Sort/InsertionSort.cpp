/*
 *	A simple insertion sort algorithm
 *
 *	O(N^2), stable, O(1) extra memory used.
 *
 */

#include <iostream>
#include <vector>
#include <random>

using namespace std;

template <typename T> void InsertionSort(vector<T> &vec)
{
	size_t j;
	for(size_t i = 1; i < vec.size(); ++i) {
		T tmp = vec[i];
		for(j = i; j > 0 && tmp < vec[j - 1]; --j)
			vec[j] = vec[j - 1];

		vec[j] = tmp;
	}

}

int main(int argc, char *argv[])
{
	vector<int> forsort;

	uniform_int_distribution<unsigned> u(0, 20);
	default_random_engine e;

	cout << "Before Sorted:" << endl;
	for(size_t i = 0; i < 20; ++i) {
		unsigned x = u(e);
		cout << x << " ";
		forsort.push_back(x);
	}
	cout << endl;
	
	InsertionSort<int>(forsort);

	cout << "After Sorted:" << endl;
	for(vector<int>::iterator itr = forsort.begin(); itr != forsort.end(); ++itr)
		cout << *itr << " ";
	cout << endl;

	return 0;
}
