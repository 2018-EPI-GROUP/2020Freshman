#include<stdio.h>
#include"Array.h"
#include<stdlib.h>
#include<string.h>
Array* Init_Array()
/*��ʼ��һ�������Ա�����*/
{
	Array* Array1 = (Array*)malloc(sizeof(Array));//������һ�����飬������ռ�
	Array1->size = 0;
	Array1->capicity = 20;
	Array1->pAddr = (int*)malloc(Array1->capicity * sizeof(int));
	return Array1;
}
void Insert_Array(Array* arr, int value)//Ϊ������ע��Ԫ��
{
	if (arr == NULL) return;
	if (arr->size == arr->capicity)
	{
		int* newSpace = (int*)malloc(sizeof(int) * 2 * arr->capicity);
		/*1.����һ�������ڴ�ռ䣬�¿ռ���ڴ��Ǿɿռ��2��*/
		memcpy(newSpace, arr->pAddr, arr->capicity * sizeof(int));
		//2.�������ݵ��µĿռ�
		free(arr->pAddr);
		//3.�ͷžɿռ��ڴ�
		arr->capicity = arr->capicity * 2;
		arr->pAddr = newSpace;
		//��������
	}
	arr->pAddr[arr->size] = value;
	arr->size++;
	//������Ԫ��
}
void insertbypos_array(Array* arr,int pos,int value)//��λ�ò���Ԫ��
{
	if (arr == NULL) return;
	else if (pos > arr->size || pos < 0)
	{
		printf("Error!Wrong postion!\n");
		return;
	}
	else if (arr->size == arr->capicity)
	{
		printf("��������������������Ϊ��������ռ䣡\n");
		int* Newspace = (int*)malloc(2 * arr->capicity * sizeof(int));
		/*1.����һ�������ڴ�ռ䣬�¿ռ���ڴ��Ǿɿռ��2��*/
		memcpy(Newspace, arr->pAddr, arr->capicity * sizeof(int));
		//2.�������ݵ��µĿռ�
		free(arr->pAddr);
		//3.�ͷžɿռ��ڴ�
		arr->capicity = 2 * arr->capicity;
		//��������
		arr->pAddr = Newspace;//���µ�ַ
		printf("��Ϊ�����ͬ����С�Ŀռ�!\n");
	}
		for (int i = arr->size - 1;i >= pos - 1;i--)
		{
			arr->pAddr[i + 1] = arr->pAddr[i];
		}
		//�Ӻ���ǰŲ��Ԫ��Ϊ����Ԫ���ڳ�λ��
		arr->pAddr[pos-1] = value;//����Ԫ��
		arr->size++;
		printf("Success!\n");
}
int FindbyPos(Array* arr, int pos)//���ĳ��λ�õ�Ԫ��ֵ
{
	if (arr == NULL) return -1;
	else if (pos <= 0 || pos > arr->size) return -1;
	else return arr->pAddr[pos-1];
}
int FindbyValue(Array* arr, int value)/*���ҵ�һ�γ��ֵ�λ��*/
{
	if (arr == NULL) return NULL;
	for (int i = 0;i < arr->size;i++)
	{
		if (arr->pAddr[i] == value) return i;
	}
	printf("Failed!No search!\n");
	return -1;
}
void DeletebyPos(Array* arr, int pos)//����λ��ɾ��
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
void DeletebyValue(Array* arr, int value)//����Ԫ��ɾ����һ�����ֵ�
{
	if (arr == NULL) return;
	int pos=FindbyValue(arr, value);
	if (pos != -1)
	{
		DeletebyPos(arr, pos);
		printf("Success!\n");
	}
}
int Length(Array* arr)//��ȡ����ĳ���
{
	if (arr == NULL)
	{
		printf("Error!Invalid array!\n");
		return NULL;
	}
	else return arr->size;
}
void Printf_Array(Array* arr)//��ӡ
{
	for (int i = 0;i < arr->size;i++)
	{
		printf("%d ", arr->pAddr[i]);
	}
	printf("\n");
}
int Size_Array(Array* arr)//��ȡ��̬�����Ԫ�ظ���
{
	if (arr == NULL) return -1;
	return arr->size;
}
void Free_Array(Array* arr)//�ͷ�����ռ�
{
	if (arr == NULL) return;
	else
	{
		free(arr->pAddr);
		free(arr);
	}
}
void Delete_Array(Array* arr)//ɾ����������
{
	if (arr == NULL) return;
	else
	{
		arr->size = 0;
		Free_Array(arr);
		return;
	}
}