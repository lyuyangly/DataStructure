/*
Converts an int or long into a character string
将一个整数转化为字符串,不属于C标准
*/
void itoa(int n, char s[])
{
	int i,j,sign;

	if((sign = n)<0)    //记录符号
		n = -n;         //使n成为正数
	i=0;
	do{
		s[i++] = n % 10 + '0';    //取下一个数字
	}while((n/=10) > 0);      //循环相除

	if(sign < 0)
		s[i++]='-';
	s[i]='\0';
	for(j = i - 1; j >= 0;j--)        //生成的数字是逆序的，所以要逆序输出
		printf("%c",s[j]);
}