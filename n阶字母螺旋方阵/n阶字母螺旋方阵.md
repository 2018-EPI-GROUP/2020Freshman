+ 先输入循环次数 后输入方阵阶数
+ 代码中运用了C/C++语言初始化函数memset  作用是作用是将某一块内存中的内容全部设置为指定的值， 这个函数通常为新申请的内存做初始化工作。
> void *memset(void *s, int ch, size_t n);

> 函数解释：将s中当前位置后面的n个字节 （typedef unsigned int size_t ）用 ch 替换并返回 s 。

> memset：作用是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法
```
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char num[20][20];
int main()
{
    int N;
    scanf("%d",&N);
    while(N--)
    {
        int n;
        scanf("%d",&n);
        int i,j;
        int js='A';
        memset(num,0,sizeof(num));
        for(i=0; i<=n/2; i++)
        {
            for(j=i; j<=n-i-1; j++)
            {
                if(js>'Z')
                    js=js-1-'Z'+'A';
                num[i][j]=js++;
            }
            for(j=i+1; j<=n-i-1; j++)
            {
                if(js>'Z')
                    js=js-1-'Z'+'A';
                num[j][n-i-1]=js++;
            }
            for(j=n-i-2; j>=i; j--)
            {
                if(js>'Z')
                    js=js-1-'Z'+'A';
                num[n-i-1][j]=js++;
            }
 
            for(j=n-i-2; j>i; j--)
            {
                if(js>'Z')
                    js=js-1-'Z'+'A';
                num[j][i]=js++;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                printf("%5c",num[i][j]);
            printf("\n");
 
        }
    }
    return 0;
 
}
```
