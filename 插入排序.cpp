#include<iostream>
#include<cmath>
using namespace std;
void insert_queue(int a[], int n)
{
    int i,j,key;
    for (i = 1;i < n;i++)
    {
        key = a[i];
        j = i - 1;
        while (key < a[j]&&j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int a[10000],i;
    for (i = 0;i < n;i++)
        scanf("%d", &a[i]);
    insert_queue(a, n);
    for (i = 0;i < n;i++)
        printf("%d ", a[i]);
    return 0;
}

