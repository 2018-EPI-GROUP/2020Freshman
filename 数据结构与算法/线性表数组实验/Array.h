#pragma once
typedef struct ARRAY
{
	int* pAddr;//������׵�ַ
	int capicity;//������������
	int size;//�����Ԫ�ظ���
}Array;
Array* Init_Array();/*��ʼ��һ�������Ա�����*/
void Insert_Array(Array* arr, int value);//Ϊ������ע��Ԫ��
void insertbypos_array(Array* arr, int pos, int value);//��λ�ò���Ԫ��
int FindbyPos(Array* arr, int pos);//���ĳ��λ�õ�Ԫ��ֵ
int FindbyValue(Array* arr, int value);/*���ҵ�һ�γ��ֵ�λ��*/
void DeletebyPos(Array* arr, int pos);//����λ��ɾ��
void DeletebyValue(Array* arr, int value);//����Ԫ��ɾ����һ�����ֵ�
int Length(Array* arr);//��ȡ����ĳ���
void Printf_Array(Array* arr);//��ӡ
int Size_Array(Array* arr);//��ȡ��̬�����Ԫ�ظ���
void Free_Array(Array* arr);//�ͷ�����ռ�
void Delete_Array(Array* arr);//ɾ����������
