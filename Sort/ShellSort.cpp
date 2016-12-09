/*
 *	A simple shell sort algorithm
 *
 *	average:O(Nlog^2(N)), worse O(N^2), not stable, O(1) extra memory used.
 *
 */

#include <iostream>
#include <vector>
#include <random>

using namespace std;

template <typename T> void ShellSort(vector<T> &vec)
{
	size_t j;
	for(size_t gap = vec.size()/2; gap > 0; gap /=2) {
		for(size_t i = gap; i < vec.size(); ++i) {
			T tmp = vec[i];
			for(j = i; j >= gap && tmp < vec[j - gap]; j -= gap)
				vec[j] = vec[j - gap];
			vec[j] = tmp;
		}
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
	
	ShellSort<int>(forsort);

	cout << "After Sorted:" << endl;
	for(vector<int>::iterator itr = forsort.begin(); itr != forsort.end(); ++itr)
		cout << *itr << " ";
	cout << endl;

	return 0;
}
