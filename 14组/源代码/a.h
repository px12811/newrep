#ifndef _A_H_//��ֹͷ�ļ����ظ������ͱ��� 
#define _A_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct result
{
	int result_chinese;	//���ĳɼ�
	int result_math;		//��ѧ
	int result_english;  //Ӣ��ɼ�
	int result_sum;
}result;
typedef struct Student  
{  
   char name[100]; 		//����  
   char num[100];  		//ѧ��  
   char sex;			//�Ա� (m����Ů��f��������)  
   int age;				//����  
   result result;			//�ɼ�  
}stu;  
typedef struct LNode  
{  
    stu data;  
    struct LNode *next;  
}LinkList;
typedef int Status;  
typedef int ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
char nam[100];//����  
char nu[100];//ѧ��  
char s;//�Ա�  
int ag;//����  
result re;//�ɼ� 
BiTree T_C,T_M,T_E,T_S;  
#endif
