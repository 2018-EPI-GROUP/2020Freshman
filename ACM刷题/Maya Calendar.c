#include<stdio.h>
#include<string.h>
char *habb[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh",
			  "mac","kankin","muan","pax","koyab","cumhu","uayet"};
			  //��һ���������·����� 
char *tzolkin[]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok",
				 "chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
			  //�ڶ����������������� 
int sum(int year,char *month,int day)//�����������Ч���������ڵ����� 
{
	int i;
	for(i=0;i<19;i++) if(strcmp(month,habb[i])==0) break;//�����������飬ȡ���·� 
	return year*365+20*i+day; 
}

int main()
{
	int test,i;
	scanf("%d",&test);
	printf("%d\n",test); 
	for(i=0;i<test;i++)
	{
		int year,day,sumday;
		char month[20];
		//��һ�������������� 
		scanf("%d.%s %d",&day,month,&year);//ע�⣺�ַ���ָ�벻��Ҫȡ��ַ 
		sumday=sum(year,month,day);
		int tyear,tmonth,tday;//�ڶ��������������� 
		printf("%i %s %i\n",sumday%13+1,tzolkin[sumday%20],sumday/260);//������������ 
	}
	return 0;
 } 
