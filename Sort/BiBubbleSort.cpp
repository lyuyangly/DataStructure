/*
*	A simple bibubble sort algorithm
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

/*
 *	A extreme case, if the sequence is sorted,
 *	we needn't sort it at all.
 *	so we use a flag.
 */
void bibubble_sort(vector<int> &vec)
{
	size_t i, j;
	bool not_sorted = false;
	size_t min_index = 0, max_index= vec.size() - 1;
	
	while(min_index <= max_index) {
		// carry the big one to right
		for(i = min_index; i < max_index; ++i) {
			if(vec[i] > vec[i + 1]) {
				swap(vec[i], vec[i + 1]);
				not_sorted = true;
			}
		}
		max_index--;

		// if it was sorted.
		if(!not_sorted) break;

		// carry the small one to left
		for(j = max_index; j > min_index; --j) {
			if(vec[j] < vec[j - 1])
				swap(vec[j], vec[j - 1]);
		}
		min_index++;
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

	bibubble_sort(num);
	
	cout << "After Sort: " << flush;
	for(vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr) {
		cout << *itr << " " << flush;
	}

	cout << endl;

	return 0;
}

