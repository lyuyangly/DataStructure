/*
 *		使用栈做括号匹配工作
 *		例子的括号有[](){}
 *		输出是否匹配
 */
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string &s) {
	stack<char> chs;
	
	for(string::iterator it = s.begin(); it != s.end(); ++it) {
		if(chs.empty()) {
			chs.push(*it);
		}
		else if((chs.top() == '(' && *it == ')') || (chs.top() == '[' && *it == ']') || (chs.top() == '{' && *it == '}')) {
			chs.pop();
		}
		else {
			chs.push(*it);
		}
	}
	
	return chs.empty();
}

int main(void)
{
	string s;
	
	cin >> s;
	
	cout << boolalpha << isValid(s) << endl;
	
	return 0;
}
