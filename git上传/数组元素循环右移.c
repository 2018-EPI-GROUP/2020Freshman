#include <stdio.h>
int main()
{
	int n,m,t;
	int i,j;
	int a[100];
	scanf("%d %d\n",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d\n",&a[i]);
	}
		while(m--)//һ��һ�λ���һ����m�� 
		{
			t=a[n-1];
			for(j=n-1;j>=1;j--)
			{
				a[j]=a[j-1];
			}
			a[0]=t;
		}
		for(i=0;i<n;i++)//���һ������û�пո� 
		{
			if(i!=0)
			{
				printf(" ");
			}
			printf("%d",a[i]);
		}
	return 0;
}
