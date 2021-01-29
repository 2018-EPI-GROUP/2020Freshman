#include<stdio.h>
#include"Array.h"
#include<stdlib.h>
#include<string.h>
Array* Init_Array()
/*初始化一个空线性表数组*/
{
	Array* Array1 = (Array*)malloc(sizeof(Array));//创建第一个数组，并分配空间
	Array1->size = 0;
	Array1->capicity = 20;
	Array1->pAddr = (int*)malloc(Array1->capicity * sizeof(int));
	return Array1;
}
void Insert_Array(Array* arr, int value)//为空数组注入元素
{
	if (arr == NULL) return;
	if (arr->size == arr->capicity)
	{
		int* newSpace = (int*)malloc(sizeof(int) * 2 * arr->capicity);
		/*1.申请一块更大的内存空间，新空间的内存是旧空间的2倍*/
		memcpy(newSpace, arr->pAddr, arr->capicity * sizeof(int));
		//2.拷贝数据到新的空间
		free(arr->pAddr);
		//3.释放旧空间内存
		arr->capicity = arr->capicity * 2;
		arr->pAddr = newSpace;
		//更新容量
	}
	arr->pAddr[arr->size] = value;
	arr->size++;
	//插入新元素
}
void insertbypos_array(Array* arr,int pos,int value)//按位置插入元素
{
	if (arr == NULL) return;
	else if (pos > arr->size || pos < 0)
	{
		printf("Error!Wrong postion!\n");
		return;
	}
	else if (arr->size == arr->capicity)
	{
		printf("该数组容量已满，正在为其分配更多空间！\n");
		int* Newspace = (int*)malloc(2 * arr->capicity * sizeof(int));
		/*1.申请一块更大的内存空间，新空间的内存是旧空间的2倍*/
		memcpy(Newspace, arr->pAddr, arr->capicity * sizeof(int));
		//2.拷贝数据到新的空间
		free(arr->pAddr);
		//3.释放旧空间内存
		arr->capicity = 2 * arr->capicity;
		//更新容量
		arr->pAddr = Newspace;//更新地址
		printf("已为其分配同样大小的空间!\n");
	}
		for (int i = arr->size - 1;i >= pos - 1;i--)
		{
			arr->pAddr[i + 1] = arr->pAddr[i];
		}
		//从后往前挪动元素为插入元素腾出位置
		arr->pAddr[pos-1] = value;//插入元素
		arr->size++;
		printf("Success!\n");
}
int FindbyPos(Array* arr, int pos)//获得某个位置的元素值
{
	if (arr == NULL) return -1;
	else if (pos <= 0 || pos > arr->size) return -1;
	else return arr->pAddr[pos-1];
}
int FindbyValue(Array* arr, int value)/*查找第一次出现的位置*/
{
	if (arr == NULL) return NULL;
	for (int i = 0;i < arr->size;i++)
	{
		if (arr->pAddr[i] == value) return i;
	}
	printf("Failed!No search!\n");
	return -1;
}
void DeletebyPos(Array* arr, int pos)//根据位置删除
{
	if (arr == NULL) return;
	else if (pos < 0 || pos > arr->size)
	{
		printf("Failed!Invalid position!\n");
		return;
	}
	for (int i = pos;i < arr->size;i++)
	{
		arr->pAddr[i] = arr->pAddr[i + 1];
	}
	arr->size--;
}
void DeletebyValue(Array* arr, int value)//根据元素删除第一个出现的
{
	if (arr == NULL) return;
	int pos=FindbyValue(arr, value);
	if (pos != -1)
	{
		DeletebyPos(arr, pos);
		printf("Success!\n");
	}
}
int Length(Array* arr)//获取数组的长度
{
	if (arr == NULL)
	{
		printf("Error!Invalid array!\n");
		return NULL;
	}
	else return arr->size;
}
void Printf_Array(Array* arr)//打印
{
	for (int i = 0;i < arr->size;i++)
	{
		printf("%d ", arr->pAddr[i]);
	}
	printf("\n");
}
int Size_Array(Array* arr)//获取动态数组的元素个数
{
	if (arr == NULL) return -1;
	return arr->size;
}
void Free_Array(Array* arr)//释放数组空间
{
	if (arr == NULL) return;
	else
	{
		free(arr->pAddr);
		free(arr);
	}
}
void Delete_Array(Array* arr)//删除整个数组
{
	if (arr == NULL) return;
	else
	{
		arr->size = 0;
		Free_Array(arr);
		return;
	}
}