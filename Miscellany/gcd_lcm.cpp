/*
 *
 * A simple program for gcd & lcm calculation.
 *
 */
#include <iostream>

using namespace std;


int gcd(int a, int b)
{
	int x = a % b;
	if(x == 0)
		return b;
	else return gcd(b, x);	
}

int gcd2(int a, int b)
{
	while(a != b) {
		if(a > b)
			a -= b;
		else b -= a;
	}
	
	if(a > b) return a;
	else return b;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main(int argc, char **argv)
{
	int a, b;
	while(cin >> a >> b) {
		cout << "GCD: " << gcd2(a, b) << endl;
		cout << "LCM: " << lcm(a, b) << endl;
	}

	return 0;
}

