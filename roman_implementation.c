#include "roman.h"

char roman[] = "IVXLCDM";
int decimal[] = {1,5,10,50,100,500,1000};

int roman2integer(char *str )
{
	int len = strlen(str);	
	int i=0, j=0, val = 0;
	i = len-1;
	val = val + decimal[indexofletter(str[i])];
	j = i;
	i--;

	while(i>=0)
	{
		if(indexofletter(str[i]) >= indexofletter(str[j]))
			val = val + decimal[indexofletter(str[i])];
		else
			val = val - decimal[indexofletter(str[i])];
		
		i--;
		j--;
	} 
	return val;
}

int indexofletter(char x)
{
	int i=0;
	for(i=0;i<7;i++)
		if(x == roman[i])
		{
			return i;
		}
	return -1;
}

void postdigit(char* answer, int* ind, char c, int n)
{
	int i=0;
	for(i=0;i<n;i++)
		answer[(*ind)++] = c;
}

void predigit(char* answer, int* ind, char num1, char num2)
{
	answer[(*ind)++] = num1;
	answer[(*ind)++] = num2;
}

char * integer2roman(int num)
{
	int i=0;
	static char answer[1000];
	int ind=0;

	if(num == 0)
		return "NULL";

	for(i=0;i<1000;i++)
		answer[i] = '\0';
	
	while(num != 0)
	{
		if(num >= 1000)
		{
			postdigit(answer, &ind, 'M', num/1000);
			num = num - (num/1000)*1000;
		}
		else if(num >= 500)
		{
			if(num < 900)
			{
				postdigit(answer, &ind, 'D', num/500);
				num = num - (num/500)*500;
			}
			else
			{
				predigit(answer, &ind, 'C','M');
				num = num - 900;
			}
		}
		else if(num >= 100)
		{
			if(num < 400)
			{
				postdigit(answer, &ind, 'C', num/100);
				num = num - (num/100)*100;
			}
			else
			{
				predigit(answer, &ind, 'C','D');
				num = num - 400;
			}
		}
		else if(num >= 50)
		{
			if(num < 90)
			{
				postdigit(answer, &ind, 'L', num/50);
				num = num - (num/50)*50;
			}
			else
			{
				predigit(answer, &ind, 'X','C');
				num = num - 90;
			}
		}
		else if(num >= 10)
		{
			if(num < 40)
			{
				postdigit(answer, &ind, 'X', num/10);
				num = num - (num/10)*10;
			}
			else
			{
				predigit(answer, &ind, 'X','L');
				num = num - 40;
			}
		}
		else if(num >= 5)
		{
			if(num < 9)
			{
				postdigit(answer, &ind, 'V', num/5);
				num = num - (num/5)*5;
			}
			else
			{
				predigit(answer, &ind, 'I','X');
				num = num - 9;
			}
		}
		else if(num >= 1)
		{
			if(num < 4)
			{
				postdigit(answer, &ind, 'I', num/1);
				num = num - (num/1)*1;
			}
			else
			{
				predigit(answer, &ind, 'I','V');
				num = num - 4;
			}
		}
	}

	return answer;
}

char * romanAddition(char* str1, char* str2)
{
	int val1 = roman2integer(str1);
	int val2 = roman2integer(str2);
	int val = val1 + val2;
	static char * ans;
	ans = integer2roman(val);

	return ans;
}

char * romanSubtraction(char* str1, char* str2)
{
	int val1 = roman2integer(str1);
	int val2 = roman2integer(str2);
	int val = val1 - val2;
	static char * res;
	res = integer2roman(val);

	return res;
}



