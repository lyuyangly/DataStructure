/*
*	A simple bubble sort algorithm
*
*	average: O(N^2), stable, O(1) extra memory used.
*
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubble_sort(vector<int> &vec)
{
	size_t i, j;
	size_t n = vec.size();

	for(i = 0; i < n - 1; ++i) {
		for(j = 1; j < n - i; ++j) {
			if(vec[j] < vec[j - 1]) {
				swap(vec[j], vec[j - 1]);
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int tmp;
	vector<int> num;
	
	srand(unsigned(time(NULL)));
	
	cout << "Before Sort: " << flush;

	for(size_t i = 0; i < 15; ++i) {
		tmp = rand() % 100;
		cout << tmp << ' ';
		num.push_back(tmp);
	}
	cout << endl;

	bubble_sort(num);
	
	cout << "After Sort: " << flush;
	for(vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr) {
		cout << *itr << " " << flush;
	}

	cout << endl;

	return 0;
}

