#include<stdio.h>
#include<stdlib.h>
#include"Array.h"
int main()
{
	Array* test1 = Init_Array();
	for (int i = 1;i <= 10;i++)
		Insert_Array(test1, i);
	Printf_Array(test1);
	for (int i = 1;i <= 15;i++)
		printf("%d ", FindbyPos(test1, i));
	printf("\n");
	DeletebyPos(test1, 4);
	Printf_Array(test1);
	printf("%d", FindbyValue(test1, 9));
	insertbypos_array(test1, 3, 999);
	Printf_Array(test1);
	DeletebyValue(test1, 999);
	Printf_Array(test1);
	printf("%d %d", Length(test1), Size_Array(test1));
	Delete_Array(test1);
}