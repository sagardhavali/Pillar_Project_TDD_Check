#include "roman.h"

char roman[] = "IVXLCDM";
int decimal[] = {1,5,10,50,100,500,1000};
char *lookup[59] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX",	 "XX", "XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII", "XXIX", "XXX", "XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX", "XL", "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", "XC", "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX" };

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

bool isvalidroman(char *str)
{
	int len = strlen(str);
	int i=0, prev=0, pres=0, count=0;
	int first_M = 0;
	char temp[len-1];
	//int temp_len=0;

	if(str[0] == 'M')
		first_M = 1;
	else
		first_M = 0;

	for(i=0;i<len;i++)
	{
		pres = indexofletter(str[i]);
		if(pres == -1)
			return false;
		count++;
		if(prev == pres)
		{
			if(pres%2 == 1)
				return false;
			if(pres%2 == 0 && count == 2 && str[i] == 'M' && first_M == 0)
				return false;
		}
		else
			count = 1;
		if(count >3 && str[i] != 'M')
			return false;		
		prev = pres;
	}
		
	prev = indexofletter(str[0]);
	count = 0;
	for(i=1;i<len;i++)
	{
		pres = indexofletter(str[i]);
		if(pres == prev)
			count++;
		if(pres > prev && count == 1)
			return false;	
	}

	prev = 0;
	pres = 0;
	switch(str[0])
	{
		case 'I' :	if(len == 2 && (indexofletter(str[1]) > (indexofletter(str[0])+2)))
						return false;					
					else if(len > 2)
					{
						if(indexofletter(str[2]) == indexofletter(str[0]) && str[1] != 'I')
							return false;
						if(indexofletter(str[2]) > indexofletter(str[0]))
							return false;
					}
					else
						return true;

		case 'X' :	for(i=1;i<59;i++)
					{	
						if(!strcmp(str,lookup[i]))
							return true;
					}
					return false;

					/*if(len == 2 && (indexofletter(str[1]) > (indexofletter(str[0])+2)))
						return false;
					else if(len > 2)
					{						
						if(str[1] == 'D' || str[1] == 'M')
							return false;									
						if(indexofletter(str[2]) == indexofletter(str[0]))
						{
							if(str[1] != 'I' && str[1] != 'X')
								return false;
						}
						if(indexofletter(str[2]) > indexofletter(str[0]))
							return false;
						for(i=2;i<len;i++)
							if(indexofletter(str[i]) > indexofletter(str[0]))
								return false; 
						return true;
					}
					else
						return true;*/

		case 'C' :	if(len == 2 && (indexofletter(str[1]) > (indexofletter(str[0])+2)))
						return false;
					else if(len > 2 )
					{
						if (indexofletter(str[2]) == indexofletter(str[0]) && str[1] != 'C')
							return false;						
						if (indexofletter(str[2]) > indexofletter(str[0]))
							return false;
						else
							return true;
					}
					else
						return true;

		case 'V' :	for(i=1;i<len;i++)
						if(indexofletter(str[i]) >= indexofletter(str[0]))
							return false;		
					return true;

		case 'L' :	for(i=1;i<len;i++)
						if(indexofletter(str[i]) >= indexofletter(str[0]))
							return false;
					if(len > 3 && (indexofletter(str[3]) >= indexofletter(str[1])))
						return false;
					strncpy(temp,str+1,len-1);
					temp[len-1] = '\0';					
					return isvalidroman(temp);

		case 'D' :	strncpy(temp,str+1,len-1);
					temp[len-1] = '\0';					
					return isvalidroman(temp);

		case 'M' : 	count = 1;
					for(i=1;i<len;i++)
					{
						if(str[i-1] == str[i])
							count++;
						else
							count = 1;
						if(count > 4)
							return false;
					}
					strncpy(temp,str+1,len-1);
					temp[len-1] = '\0';					
					return isvalidroman(temp);
					break;
	
	
	}
	
	return true;
}
