#include<stdio.h>
int main() 
{
    int n, i;
    int a = 0, a1 = 0, b = 0, b1 = 0, c = 0, c1 = 0, d = 0;
    char jia, yi;
    scanf("%d", &n);
    getchar();//���ջ��������еĻ��з� �� 
    //����ǰ��ĸ�Ϊ��scanf("%d\n",&n);  �����ʡȥ�����getchar��������'\n'�������㣨�������з��� 
    for(i = 0; i < n; i++) 
	{
        scanf("%c %c", &jia, &yi);//scanf������������˿ո񣨿ո����tab��������Ϊ�ַ�������
        getchar();//����scanf��������Ļ��з���
		
		//����ǰ�������Ϊ��scanf("%c %c\n");�����ʡȥ�����getchar����,����ͬ�ϡ� 
		 
        //ʹ��scanf���������������ַ���Ҫ��һ�»س�����ԭ��������ַ����洢�ڻ������У��ڰ��»س�����㱻��ȡ�������С�
		//�����ڰ��»س��������һ���س�����getchar()�����þ��ǰ�����س�����ȡ����ֱ����������һ�����������롣
        if(jia == 'B' && yi == 'C') 
		{
            c++;
        }
		else if(jia == 'C' && yi == 'J') 
		{
            a++;
        }
		else if(jia == 'J' && yi == 'B') 
		{
            b++;
        }
		else if(jia == yi) 
		{
            d++;
        }
		else if(yi == 'C' && jia == 'J') 
		{
            a1++;
        }
		else if(yi == 'J' && jia == 'B') 
		{
            b1++;
        }
		else if(yi == 'B' && jia == 'C') 
		{
            c1++;
        }
	}
    
    printf("%d %d %d\n", a+b+c, d, a1+b1+c1);
    printf("%d %d %d\n", a1+b1+c1, d, a+b+c);
    
    if(c >= b && c >= a) printf("B ");
    else if(a >= b && a >= c) printf("C ");
    else if(b >= a && b >= c) printf("J ");
    
    if(c1 >= b1 && c1 >= a1) printf("B");
    else if(a1 >= b1 && a1 >= c1) printf("C");
    else if(b1 >= a1 && b1 >= c1) printf("J");
    
    return 0;
}
