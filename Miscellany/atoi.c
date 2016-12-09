#include <ctype.h>
/*
Converts a character string into an int or long
将一个字符串转化为整数
*/
int atoi(char s[])
{
	int i,n,sign;

	for(i = 0; isspace(s[i]); i++);   //跳过空白

	sign = (s[i] == '-') ? -1 : 1;
	if(s[i]=='+' || s[i]==' -')     //跳过符号位
		i++;
	for(n = 0; isdigit(s[i]); i++)
		n = 10*n + (s[i] - '0');        //将数字字符转换成整形数字
	return sign*n;
}
