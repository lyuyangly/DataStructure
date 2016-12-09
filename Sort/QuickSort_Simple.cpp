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

template<typename T> void quick_sort_recursive(vector<T> &vec, ssize_t l, ssize_t r)
{
    if (l < r) {
    	T x = vec[l];
        ssize_t i = l, j = r;
        
        /* find the pivot */
        while (i < j) {
            while(i < j && vec[j] >= x)
				j--;  
            if(i < j) 
				vec[i++] = vec[j];
			
            while(i < j && vec[i] < x)
				i++;
            if(i < j) 
				vec[j--] = vec[i];
        }
        vec[i] = x;
        
        /* quick sort left side and right side recursively */
        quick_sort_recursive(vec, l, i - 1);
        quick_sort_recursive(vec, i + 1, r);
    }
}

template<typename T> void quick_sort(vector<T> &vec)
{
	quick_sort_recursive(vec, 0, vec.size()-1);
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

