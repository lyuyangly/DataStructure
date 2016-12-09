/*
*	A simple merge sort algorithm
*
*	average: O(NlogN), not stable, O(N) extra memory used.
*
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 *	merge elements from index lpos to midpos-1,
 *	midpos to rpos.
 *	since midpos is the start index of second
 *	subarray.
 */
template<typename T> void merge(vector<T> &vec, vector<T> &tmp, size_t lpos, size_t midpos, size_t rpos)
{
	size_t lend = midpos - 1;
	size_t tmppos = lpos;
	
	size_t nelements = rpos - lpos + 1;

	while(lpos <= lend && midpos <= rpos)
		if(vec[lpos] <= vec[midpos])
			tmp[tmppos++] = vec[lpos++];
		else
			tmp[tmppos++] = vec[midpos++];

	// rest elements
	while(lpos <= lend)
		tmp[tmppos++] = vec[lpos++];

	while(midpos <= rpos)
		tmp[tmppos++] = vec[midpos++];

	// write back
	for(size_t i = 0; i < nelements; i++,rpos--)
		vec[rpos] = tmp[rpos];
}

template<typename T> void merge_sort_range(vector<T> &vec, vector<T> &tmp, size_t left, size_t right)
{
	if(left < right) {
		size_t center = (left + right) / 2;
		merge_sort_range(vec, tmp, left, center);
		merge_sort_range(vec, tmp, center + 1, right);
		merge(vec, tmp, left, center + 1, right);
	}
}

template<typename T> void merge_sort(vector<T> &vec)
{
	vector<T> atmp(vec.size());

	// begin and end index.
	merge_sort_range(vec, atmp, 0, vec.size()-1);
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

	merge_sort<int>(num);
	
	cout << "After Sort: " << flush;
	for(vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr) {
		cout << *itr << " " << flush;
	}

	cout << endl;

	return 0;
}

