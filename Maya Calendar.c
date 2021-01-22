#include<stdio.h>
#include<string.h>
char *habb[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh",
			  "mac","kankin","muan","pax","koyab","cumhu","uayet"};
			  //第一个历法的月份名称 
char *tzolkin[]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok",
				 "chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
			  //第二个历法的日期名称 
int sum(int year,char *month,int day)//计算从历法生效到输入日期的天数 
{
	int i;
	for(i=0;i<19;i++) if(strcmp(month,habb[i])==0) break;//遍历名称数组，取得月份 
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
		//第一个历法的年月日 
		scanf("%d.%s %d",&day,month,&year);//注意：字符串指针不需要取地址 
		sumday=sum(year,month,day);
		int tyear,tmonth,tday;//第二个历法的年月日 
		printf("%i %s %i\n",sumday%13+1,tzolkin[sumday%20],sumday/260);//根据天数换算 
	}
	return 0;
 } 
