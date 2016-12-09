/*
*	A simple quick sort algorithm
*
*	average: O(NlogN), not stable, O(1) extra memory used.
*
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 *	In this case, the root index is start at 0.
 *
 *	hence, the lchild index is 2*i+1, rchild index is 2*i+2;
 *	given index x, the root index of it is (x - 1)/2.
 *
 */

template<typename T> void percolate_down(vector<T> &vec, ssize_t i, ssize_t n)
{
	ssize_t child;
	T tmp;
	
	for(tmp = vec[i]; 2*i+1 < n; i = child) {
		child = 2*i+1;
		if(child != n - 1 && vec[child] < vec[child+1])
			child++;

		if(tmp < vec[child])
			vec[i] = vec[child];
		else break;
	}

	vec[i] = tmp;
}

template<typename T> void heap_sort(vector<T> &vec)
{
	// build heap first
	for(ssize_t i = vec.size() / 2; i >= 0; --i)
		percolate_down<T>(vec, i, vec.size());

	// delete max
	for(ssize_t j = vec.size() - 1; j > 0; --j) {
		swap(vec[0], vec[j]);
		percolate_down<T>(vec, 0, j);
	}
}

int main(int argc, char *argv[])
{
	int tmp;
	vector<int> num;
	
	srand(unsigned(time(NULL)));
	
	cout << "Before Sort: " << flush;

	for(int i = 0; i < 15; ++i) {
		tmp = rand() % 100;
		cout << tmp << ' ';
		num.push_back(tmp);
	}
	cout << endl;

	heap_sort<int>(num);
	
	cout << "After Sort: " << flush;
	for(vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr) {
		cout << *itr << " " << flush;
	}

	cout << endl;

	return 0;
}

