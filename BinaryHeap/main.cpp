#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BinaryHeap.h"

using namespace std;


int main(int argc, char **argv)
{
	int tmp;
	vector<int> items;
	
	srand(time(NULL));
	
	cout << "Before percolate down: " << flush;
	for(size_t i = 0; i < 10; ++i) {
		tmp = rand() % 100;
		items.push_back(tmp);
		cout << tmp << " " << flush;
	}
	cout << endl;
	
	BinaryHeap<int> BH(items);

	cout << "After build heap: " << flush;
	for(vector<int>::iterator itr = BH.array.begin(); itr != BH.array.end(); ++itr)
		cout << *itr << " " << flush;
	cout << endl;

	return 0;
}

