#include<stdio.h>
#include<string.h>
#define N 35

int main(void)
{
	int i, j, len = 0;
	char ch;
	char str1[N];
	char str2[N];
 
	ch = getchar();
	for (i = 0; ch != '#'; i++)
	{
		str1[i] = ch;
		len++;
		ch = getchar();
	}
	for (i = 0; i < len; i++)
 	{
		if (str1[i] >= 'A' && str1[i] <= 'Z')
		{
			 str2[i] = str1[i] + 32;
		}
		else if (str1[i] >= 'a' && str1[i] <= 'z')
		{
			 str2[i] = str1[i] - 32;
		}
		else
		{
		   str2[i] = str1[i];
		}
	}
	for (i = 0; i < len; i++)
	{
		 printf("%c", str2[i]);
	}
	printf("\n");
 
	return 0;
}
