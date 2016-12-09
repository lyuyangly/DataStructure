#include <iostream>
#include <memory>
#include "List.h"

using namespace std;

int main(int argc, char *argv[])
{
	List<int> L;
	
	cout << "Test Begin!" << endl;
	cout << L.size() << endl;
	
	for(size_t i = 0; i<5; ++i) {
		L.push_back(i);
	}
	
	for(List<int>::iterator itr = L.begin(); itr != L.end(); ++itr)
		cout << *itr << '\t';
	cout << endl;
	cout << "Test End!" << endl;
    return 0;
}


