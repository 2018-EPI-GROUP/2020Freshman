#pragma once
typedef struct ARRAY
{
	int* pAddr;//数组的首地址
	int capicity;//数组的最大容量
	int size;//数组的元素个数
}Array;
Array* Init_Array();/*初始化一个空线性表数组*/
void Insert_Array(Array* arr, int value);//为空数组注入元素
void insertbypos_array(Array* arr, int pos, int value);//按位置插入元素
int FindbyPos(Array* arr, int pos);//获得某个位置的元素值
int FindbyValue(Array* arr, int value);/*查找第一次出现的位置*/
void DeletebyPos(Array* arr, int pos);//根据位置删除
void DeletebyValue(Array* arr, int value);//根据元素删除第一个出现的
int Length(Array* arr);//获取数组的长度
void Printf_Array(Array* arr);//打印
int Size_Array(Array* arr);//获取动态数组的元素个数
void Free_Array(Array* arr);//释放数组空间
void Delete_Array(Array* arr);//删除整个数组
