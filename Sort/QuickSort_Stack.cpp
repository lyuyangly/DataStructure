/*
 *	A simple quick sort algorithm
 *
 *	average: O(NlogN), worse: O(N^2), not stable, O(logN) extra memory used.
 *
 */
 
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// typedef signed int ssize_t

/* Simulate a stack */
struct Range {
	ssize_t start, end;
	Range(ssize_t s = 0, ssize_t e = 0) {start = s, end = e;}
};

/* quick sort */
template<typename T> void quick_sort(vector<T> &arr) {
	ssize_t p = 0, len = arr.size();
	if (len <= 0) return;
	
	Range r[len];
	r[p++] = Range(0, len - 1);
	
	while (p) {
		Range range = r[--p];
		if(range.start >= range.end) continue;
		T mid = arr[range.end];
		
		ssize_t left = range.start, right = range.end - 1;
		
		while (left < right) {
			while (arr[left] < mid && left < right) left++;
			while (arr[right] >= mid && left < right) right--;
			std::swap(arr[left], arr[right]);
		}
		
		if (arr[left] >= arr[range.end])
			std::swap(arr[left], arr[range.end]);
		else
			left++;
		r[p++] = Range(range.start, left - 1);
		r[p++] = Range(left + 1, range.end);
	}
}

/* simple test case */
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

	quick_sort(num);
	
	cout << "After Sort: " << flush;
	for(vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr) {
		cout << *itr << " " << flush;
	}

	cout << endl;

	return 0;
}
