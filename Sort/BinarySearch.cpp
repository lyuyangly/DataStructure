/*
 *****************************************************************************************
 *	File:		BinarySearch.cpp
 *	Author:		Lyu Yang
 *	Function:	
 *	Description: A simple binary search program log2(N)
 *
*****************************************************************************************
*/

#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(int a[], int element, size_t low, size_t high)
{
	if(low <= high) {
		size_t mid = (low+high) / 2;
		if(element == a[mid])
			return mid;
		else if(element < a[mid])
			return BinarySearch(a, element, low, mid - 1);
		else if(element > a[mid])
			return BinarySearch(a, element, mid + 1, high);
	} else {
		return -1;
	}
	return -1;
}


int main(int argc, char *argv[])
{
	int vec[] = {4, 6, 7, 3, 9, 5 , 8, 1, 2, 0};
	cout << "Find 5: " << BinarySearch(vec, 5, 0, 9) << endl;
	cout << "Find 15: " << BinarySearch(vec, 15, 0, 9) << endl;
	return 0;
}
