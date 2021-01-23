#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
	char dictionary[105][10];
	char words[105][10];
	int i,j,pos1 = 0,pos2=0;
	while (scanf("%s", dictionary[pos1]), strcmp(dictionary[pos1], "XXXXXX"))
	{
		pos1++;
	}
	for(int i=0;i<pos1-1;i++)
	{
		for(int j=i+1;j<pos1;j++)
		{
			if(strcmp(dictionary[i],dictionary[j])==1)
			{
				char b[10];
				strcpy(b,dictionary[i]);
				strcpy(dictionary[i],dictionary[j]);
				strcpy(dictionary[j],b);
			}

		}
	}
	while (scanf("%s", words[pos2]), strcmp(words[pos2], "XXXXXX"))
	{
		int flag = 0;
		for (j = 0;j < pos1;j++)
		{
			if (strcmp(words[pos2], dictionary[j]) == 0)
			{
				flag = 1;printf("%s\n", words[pos2]);
			}
		}
		if (flag==0) printf("NOT A VALID WORD\n");
		printf("******\n");
		pos2++;
	}
	return 0;
}
