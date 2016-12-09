/*
 *	Program to distinguish a prime number.
 *
 *
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int num)
{
	int i, m;
	if(num < 2)
		return false;

	m = sqrt(num);

	for(i = 2; i <= m; ++i) {
		if(num % i == 0)
			break;
	}

	if(i > m) return true;
	else return false;
}

int main(int argc, char *argv[])
{
	for(size_t x = 1; x < 10; ++x) {
		if(is_prime(x))
			cout << x << " is a prime number." << endl;
		else cout << x << " is not a prime number." << endl;
	}
	
	return 0;
}
