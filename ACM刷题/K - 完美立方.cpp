#include<stdio.h>
#include<math.h>
//±©Á¦Ã¶¾Ù 
int main()
{
	int N,b,c,d,a;
	scanf("%d",&N);
	for(a=2;a<=N;a++)
	for(b=2;b<N;b++)
	for(c=2;c<N;c++)
	for(d=2;d<N;d++)
	if(pow(b,3)+pow(c,3)+pow(d,3)==pow(a,3)&&b<=c&&c<=d)
	{
		printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
	}	
} 
