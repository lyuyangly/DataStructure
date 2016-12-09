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

/* seek the pivot */
template<typename T> void quick_sort_recursive(vector<T> &arr, ssize_t start, ssize_t end) {
	if (start >= end) return;
	
	T mid = arr[end];
	
	ssize_t left = start, right = end - 1;
	
	while (left < right) {
		while (arr[left] < mid && left < right) left++;
		while (arr[right] >= mid && left < right) right--;
		std::swap(arr[left], arr[right]);
	}
	
	// next mid
	if (arr[left] >= arr[end])
		std::swap(arr[left], arr[end]);
	else
		left++;
	
	quick_sort_recursive(arr, start, left - 1);
	quick_sort_recursive(arr, left + 1, end);
}

/* quick sort */
template<typename T> void quick_sort(vector<T> &arr) {
	quick_sort_recursive(arr, 0L, arr.size() - 1L);
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

