#include<stdio.h>
int main() 
{
    int n, i;
    int a = 0, a1 = 0, b = 0, b1 = 0, c = 0, c1 = 0, d = 0;
    char jia, yi;
    scanf("%d", &n);
    getchar();//吸收缓冲区当中的换行符 。 
    //若将前面的改为：scanf("%d\n",&n);  则可以省去后面的getchar（），将'\n'带入运算（抵消换行符） 
    for(i = 0; i < n; i++) 
	{
        scanf("%c %c", &jia, &yi);//scanf函数如果输入了空格（空格键和tab键）会认为字符串结束
        getchar();//吸收scanf函数输入的换行符。
		
		//若将前面的语句改为：scanf("%c %c\n");则可以省去下面的getchar（）,理由同上。 
		 
        //使用scanf函数，在输入完字符后，要按一下回车键。原本输入的字符都存储在缓存区中，在按下回车键后便被读取到变量中。
		//但是在按下回车后多余了一个回车符，getchar()的作用就是把这个回车符读取掉，直接跳过了下一个变量的输入。
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
