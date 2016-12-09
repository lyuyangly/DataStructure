#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct {
	int age;
	int score;
	string name;
} stuinfo;

bool cmpstu(stuinfo v1, stuinfo v2)
{
	if(v1.score != v2.score)
		return v1.score > v2.score;
	else {
		if(v1.age != v2.age)
			return v1.age > v2.age;
		else return v1.name > v2.name;
	}
}

int main(void)
{
	stuinfo stu;
	vector<stuinfo> stus;
	
	while(cin >> stu.name >> stu.age >> stu.score) {
		stus.push_back(stu);
	}
	
	for(vector<stuinfo>::iterator it = stus.begin(); it != stus.end(); ++it) {
		cout << it->name << ' ' << it->age << ' ' << it-> score << endl;
	}
	
	cout << endl << endl;
	
	sort(stus.begin(), stus.end(), cmpstu);
	
	for(vector<stuinfo>::iterator it = stus.begin(); it != stus.end(); ++it) {
		cout << it->name << ' ' << it->age << ' ' << it-> score << endl;
	}
	
	return 0;
}