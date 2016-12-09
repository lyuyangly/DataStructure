/*
*	A simple selection sort algorithm
*
*	average: O(N^2), not stable, O(1) extra memory used.
*
*/


#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/* selection from left to right. 
 *
 * record the min/max element of every sort.
 *
 */

void selection_sort(vector<int> &vec)
{
	size_t i, j, max;
	size_t n = vec.size();

	for(i = 0; i < n - 1; ++i) {
		max = n - i - 1;
		for(j = 0; j < n - 1 - i; ++j) {
			if(vec[max] < vec[j]) {
				max = j;
			}
		}
		/* selection one element. */
		swap(vec[max], vec[n - i - 1]);
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

	selection_sort(num);
	
	cout << "After Sort: " << flush;
	for(vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr) {
		cout << *itr << " " << flush;
	}

	cout << endl;

	return 0;
}

