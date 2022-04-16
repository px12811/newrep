#ifndef _A_H_//防止头文件被重复包含和编译 
#define _A_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct result
{
	int result_chinese;	//语文成绩
	int result_math;		//数学
	int result_english;  //英语成绩
	int result_sum;
}result;
typedef struct Student  
{  
   char name[100]; 		//姓名  
   char num[100];  		//学号  
   char sex;			//性别 (m代表女生f代表男生)  
   int age;				//年龄  
   result result;			//成绩  
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
char nam[100];//名字  
char nu[100];//学号  
char s;//性别  
int ag;//年龄  
result re;//成绩 
BiTree T_C,T_M,T_E,T_S;  
#endif
