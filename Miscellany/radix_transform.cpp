/* A radix transform program by non recursion */
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

stack<int> radix_transform(int num, unsigned int radix)
{
	stack<int> res;
	
	while(num != 0) {
		res.push(num % radix);
		num /= radix;
	}
	return res;
}

int main(int argc, char *argv[])
{
	int x = 273;
	cout << x << "(8) is: ";
	stack<int> r = radix_transform(273, 8);
	// std::reverse(r.begin(), r.end());

	// for(vector<int>::iterator itr = r.begin(); itr != r.end(); ++itr)
	//	cout << *itr;
	size_t stack_size = r.size();
	for(size_t i = 0; i < stack_size; ++i) {
		cout << r.top() << flush;
		r.pop();
	}

	cout << endl;

	return 0;
}
