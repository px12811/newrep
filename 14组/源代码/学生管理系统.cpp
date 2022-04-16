#include "a.h" 
Status Insertree(BiTree &T,ElemType e){
    if(T==NULL)
    {
        T=(BiTree)malloc(sizeof(struct BiTNode));
        T->data=e;
        T->lchild=NULL;
        T->rchild=NULL;
        return 1;
    }
    if(T->data>e) Insertree(T->lchild,e);
    else if(T->data<e) Insertree(T->rchild,e);
    return 1;
} 

int FindMin( BiTree T)//ʱ�临�Ӷ�O(log2n) 
{
   if(T==NULL) return NULL;
    BiTree p=T;
    while(p&&p->lchild) p=p->lchild;
    return p->data;   
}
int FindMax( BiTree T)//ʱ�临�Ӷ�O(log2n) 
{
   if(T==NULL) return NULL;
    BiTree p=T;
    while(p&&p->rchild) p=p->rchild;
    return p->data;   
}
int InorderTraversal( BiTree T )
{
	if(T==NULL) return 0;
	InorderTraversal(T->lchild);
	printf(" %d",T->data);
	InorderTraversal(T->rchild);
}

void menu()/* �˵�����*/
{

	 printf("\t\t\t                     ѧ����Ϣ����ϵͳ                     \n");
	 printf("\t\t\t          1.��ʾ��ǰ��Ϣ          2.��ѯѧ����Ϣ       \n");
	 printf("\t\t\t          3.�޸�ѧ����Ϣ          4.����ѧ����Ϣ \n");
	 printf("\t\t\t          5.ɾ��ѧ����Ϣ          6.����ѧ����Ϣ  \n");
	 printf("\t\t\t          7.������Ϣ              8.�˳�ϵͳ       \n");
 	 printf("\t\t\t                                                        \n\n\n");

 

}


void InitList(LinkList *&L)//��ʼ������  
{  
    L=(LinkList *)malloc(sizeof(LinkList));  
    L->next=NULL;  
}
void ListInsert(LinkList *&L,LinkList *p)//��ͷ�ڵ����� 
{  
    LinkList *q=NULL;  
    q=L;  
    p->next=q->next;  
    q->next=p;  
}  
void addstu(LinkList *&L)//�����µ�ѧ��  
{   
    printf("������ѧ������Ϣ��\n");  
    printf("ѧ�ţ�");  
    scanf("%s",nu);  
    LinkList *q=L->next;  
    while(q!=NULL )  //�����ж�ѧ����Ϣ�Ƿ��Ѿ�����
    {  
        if(0==strcmp(q->data.num,nu))  
        {  
            printf("��ѧ���Ѵ���\n");  
            break;  
        }  
        q=q->next;  
    }  
    if(q==NULL)  
    {  
        LinkList *p;  
        InitList(p);  
        strcpy(p->data.num,nu);  
        printf("����") ;  
        scanf("%s",nam) ;  
        strcpy(p->data.name,nam);  
        printf("�Ա𣺣�mΪ�� fΪŮ��");  
        scanf(" %c",&s);  
        p->data.sex=s;  
        printf("���䣺");  
        scanf("%d",&ag);  
        p->data.age=ag;  
	 	printf("���ĳɼ���");
  		scanf("%d",&re.result_chinese); 
  		while(re.result_chinese<0||re.result_chinese>100)
  		{
            printf("������������������\n");
   			scanf("%d",&re.result_chinese);  
        }
  		p->data.result.result_chinese=re.result_chinese;
  		printf("��ѧ�ɼ���");
  		scanf("%d",&re.result_math); 
   		while(re.result_math<0||re.result_math>100)
   		{
            printf("������������������\n");
            scanf("%d",&re.result_math);  
        }
   		p->data.result.result_math=re.result_math;
  		printf("Ӣ��ɼ���");
  		scanf("%d",&re.result_english);  
        while(re.result_english<0||re.result_english>100)
        {
            printf("������������������\n");
            scanf("%d",&re.result_english);  
        }
        p->data.result.result_english=re.result_english; 
		p->data.result.result_sum=re.result_chinese+re.result_math+re.result_english; 
        ListInsert(L,p);  
    }  
}  

void deletestu(LinkList *L)//ɾ��ѧ��  
{   
	 int flag; 
    printf("1.��ѧ��ɾ����\n");
    printf("2.������ɾ����\n");
    printf("�������ѯ��ʽ��");
    while(1){
		scanf("%d",&flag);
		if(flag==1||flag==2) break;
		else{
			printf("��������ȷ��ѡ��\n"); 
		}
	}
	if(flag==1){
    printf("��������Ҫɾ����ѧ����ѧ��:");  
    scanf("%s",nu);   
    LinkList *p,*pre;  
    if(L->next==NULL)  
    {  
        printf("��û��ѧ����Ϣ,������ѧ����Ϣ\n");  
        return;  
    }  
    pre=L;  
    p=pre->next;  
    int judge=0;  
    while(p)  
    {  
         if(0==strcmp(p->data.num,nu))  
         {  
                 judge=1;  
                 pre->next =p->next;  
                 free(p);  
                 printf("ɾ��ѧ���ɹ�\n");  
                 break;  
         }  
         pre=p;  
         p=p->next;  
    }  
    if(judge==0)  
       printf("���ѧ��������\n");  
	
	}
	else if(flag==2){
		  printf("��������Ҫɾ����ѧ��������:");  
    scanf("%s",nam);   
    LinkList *p,*pre;  
    if(L->next==NULL)  
    {  
        printf("��û��ѧ����Ϣ,������ѧ����Ϣ\n");  
        return;  
    }  
    pre=L;  
    p=pre->next;  
    int judge=0;  
    while(p)  
    {  
         if(0==strcmp(p->data.name,nam))  
         {  
                 judge=1;  
                 pre->next =p->next;  
                 free(p);  
                 printf("ɾ��ѧ���ɹ�\n");  
                 break;  
         }  
         pre=p;  
         p=p->next;  
    }  
    if(judge==0)  
       printf("���ѧ��������\n");  
	}
}  

void changestu(LinkList *L)//�޸�ѧ����Ϣ  
{  
	int flag=0;  
    printf("��������Ҫ�޸�ѧ����ѧ�ţ�\n");  
    scanf("%s",nu);  
    LinkList *q=L->next;  
    while(q!=NULL )  
    {  
        if(0==strcmp(q->data.num,nu))  
        {  
            flag=1;  
            printf("��������Ҫ�޸ĵ���Ϣѡ�1.���� 2. �ɼ�(���ģ���ѧ��Ӣ��)  3.����   \n");  
            int choose;  
            scanf("%d",&choose); 
            switch(choose)  
            {  
            case 1:  
                	printf("��������Ҫ�޸ĵ����֣�");  
                	scanf("%s",nam);  
                	printf("�޸ĵ�����Ϊ��%s\n",nam);  
                	strcpy(q->data.name,nam);
                	printf("�޸����ֳɹ���\n");  
                	break;  
            case 2:  
                	printf("��������Ҫ�޸ĵĳɼ������� ��ѧ Ӣ��");  
               		scanf("%d%d%d",&re.result_chinese,&re.result_math,&re.result_english);  
                	printf("�޸ĵ����ĳɼ�Ϊ��%d  �޸ĵ���ѧ�ɼ�Ϊ��%d  �޸ĵ�Ӣ��ɼ�Ϊ��%d\n",re.result_chinese,re.result_math,re.result_english); 
					re.result_sum=re.result_chinese+re.result_english+re.result_math; 
               		q->data.result=re;  
                	printf("�޸ĳɼ��ɹ���\n");  
                	break;  
            case 3:  
                	printf("��������Ҫ�޸ĵ����䣺");  
                	scanf("%d",&ag);  
                	printf("�޸ĵ�����Ϊ��%d\n",ag);  
               		q->data.age=ag;  
                	printf("�޸�����ɹ���\n");  
                	break;  
            default :  
                	printf("��������ȷ��ѡ��\n");  
                	break;  
            }  
        }  
        q=q->next;  
    }  
   if(flag==0)  
   {  
     printf("����������\n");  
   }  
}  
void findstu(LinkList *L)//��ѧ�Ż�����������ѧ�������������Ϣ  
{  
    int flag; 
    printf("1.��ѧ�Ų�ѯ��\n");
    printf("2.��������ѯ��\n");
    printf("3.ѧ���ɼ���ѯ��\n");
    printf("�������ѯ��ʽ��");
	while(1){
		scanf("%d",&flag);
		if(flag==1||flag==2||flag==3) break;
		else{
			printf("��������ȷ��ѡ��\n"); 
		}
	} 
    if(flag==1){
        printf("���������ѧ�ţ�"); 
        scanf("%s",nu);  
        //�ж�  
        LinkList *q=L->next;  
        while(q!=NULL )  
        {  
            if(strcmp(q->data.num,nu)==0)  
            {  
                printf("������%s\n",q->data.name);  
                printf("ѧ�ţ�%s\n",q->data.num);  
                printf("�Ա�%c\n",q->data.sex);  
                printf("���䣺%d\n",q->data.age);  
                printf("���ĳɼ���%d\n",q->data.result.result_chinese); 
    			printf("��ѧ�ɼ���%d\n",q->data.result.result_math); 
    			printf("Ӣ��ɼ���%d\n",q->data.result.result_english); 
    			printf("�ܳɼ���%d\n",q->data.result.result_sum); 
                break;  
            }  
             q=q->next;  
        }  
        if(q==NULL)  
            printf("����������\n");  
    	}else if(flag==2){
        	printf("���������������");
        	scanf("%s",nam);  
        	LinkList *q=L->next;  
        	while(q!=NULL)  
        	{  
            	if(strcmp(q->data.name,nam)==0)  
            	{  
                	printf("������%s\n",q->data.name);  
                	printf("ѧ�ţ�%s\n",q->data.num);  
                	printf("�Ա�%c\n",q->data.sex);  
                	printf("���䣺%d\n",q->data.age);  
                	printf("���ĳɼ���%d\n",q->data.result.result_chinese); 
    				printf("��ѧ�ɼ���%d\n",q->data.result.result_math); 
    				printf("Ӣ��ɼ���%d\n",q->data.result.result_english);
    				printf("�ܳɼ���%d\n",q->data.result.result_sum);
                	break;  
            	}  
             	q=q->next;  
        	}  
        	if(q==NULL)  
            	printf("����������\n");  
    	}
    	else if(flag==3)
    	{
    		printf("1.�ܳɼ�\n");
    		printf("2.���ĳɼ�\n");
    		printf("3.��ѧ�ɼ�\n");
    		printf("4.Ӣ��ɼ�\n");
    		printf("�������ѯ���ݣ�");
    		while(1){
			scanf("%d",&flag);
			if(flag==1||flag==2||flag==3||flag==4) break;
			else{
				printf("��������ȷ��ѡ��\n"); 
				}
			}
			if(flag==1)  
			{
				InorderTraversal(T_S);
				printf("\n");
				printf("�ܳɼ���ͷ�=%d\n",FindMin(T_S));
				printf("�ܳɼ���߷�=%d\n",FindMax(T_S));
			}
			else if(flag==2)
			{
				InorderTraversal(T_C);
				printf("\n");
				printf("���ĳɼ���ͷ�=%d\n",FindMin(T_C));	
				printf("���ĳɼ���߷�=%d\n",FindMax(T_C));
			}
			else if(flag==3)
			{
				InorderTraversal(T_M);
				printf("\n");
				printf("��ѧ�ɼ���ͷ�=%d\n",FindMin(T_M));	
				printf("��ѧ�ɼ���߷�=%d\n",FindMax(T_M));
			 } 
			else if(flag==4)
			{
				InorderTraversal(T_E);
				printf("\n");
				printf("Ӣ��ɼ���ͷ�=%d\n",FindMin(T_E));	
				printf("Ӣ��ɼ���߷�=%d\n",FindMax(T_E));
			}
		}
}  
void display(LinkList *&L)//���ȫ��ѧ����Ϣ  
{  
    LinkList *q=L->next;  
    if(q==NULL)  
    {  
        printf("��û��ѧ����Ϣ��������ѧ����Ϣ\n");  
        return;  
    }  
    while(q)  
    {   
  		printf("������%s\t",q->data.name);  
        printf("ѧ�ţ�%s\t",q->data.num);  
        printf("�Ա�%c\t",q->data.sex);  
        printf("���䣺%d\t",q->data.age);  
        printf("���ĳɼ���%d\t",q->data.result.result_chinese); 
  		printf("��ѧ�ɼ���%d\t",q->data.result.result_math); 
  		printf("Ӣ��ɼ���%d\t",q->data.result.result_english);
  		printf("�ܳɼ���%d\n",q->data.result.result_sum);
  		q=q->next;  
    }  
}
//ʱ�临�Ӷ�O(n~2) �ռ临�Ӷ�O(n)
void sort_1(LinkList *L)//��ѧ���������� ����������Ľ��  
{   
    LinkList *q,*p,*r=L->next;  
    int count=0;
    //�ж�  
    if(r==NULL)  
    {  
        printf("��û��ѧ����Ϣ��������ѧ����Ϣ\n");  
        return;  
    } 
	

    	 while(r) //����ѭ���������  
    {  
         p=r;  
         q=r->next; 
		  LinkList *tmp;//��������ʱ�ݴ�ڵ�    
         InitList(tmp);  //�����м���� ���ڽ���ֵ 
         while(q)  
         {  
             if(q->data.result.result_sum > p->data.result.result_sum)  //�ɼ��Ӵ�С 
             {  
             
                //�ȸ���q�����Ϣ��tmp  
                strcpy(tmp->data.num,q->data.num);  
                strcpy(tmp->data.name,q->data.name);  
                tmp->data.sex=q->data.sex;  
                tmp->data.age=q->data.age;  
                tmp->data.result=q->data.result; 
				//�ٸ���p�����Ϣ��q
                strcpy(q->data.num,p->data.num);  
                strcpy(q->data.name,p->data.name);  
                q->data.sex=p->data.sex;  
                q->data.age=p->data.age;  
                q->data.result=p->data.result;
				//�����exchange�����Ϣ��p
                strcpy(p->data.num,tmp->data.num);  
                strcpy(p->data.name,tmp->data.name);  
                p->data.sex=tmp->data.sex;  
                p->data.age=tmp->data.age;  
                p->data.result=tmp->data.result;  
             }  
              q=q->next;  
         }  
         r=r->next; 
         }
        printf("ˢ�º��ѧ����Ϣ�ǣ�\n");  
    	display(L);    
   
       
} 
 void sort_2(LinkList *L)//��ѧ���������� ����������Ľ��  
{   
	    LinkList *q,*p,*t=L->next;  
    int count=0;
    //�ж�  
    if(t==NULL)  
    {  
        printf("��û��ѧ����Ϣ��������ѧ����Ϣ\n");  
        return;  
    } 
	

    	 while(t) //����ѭ���������  
    {  
         p=t;  
         q=t->next; 
		  LinkList *tmp;//��������ʱ�ݴ�ڵ�    
         InitList(tmp);  //�����м���� ���ڽ���ֵ 
         while(q)  
         {  
             if(strcmp(q->data.num,p->data.num)<0)  //ѧ�ŴӴ�С 
             {  
             	//printf("%d %s %s\n",strcmp(q->data.num,p->data.num),q->data.num,p->data.num);
                //�ȸ���q�����Ϣ��tmp  
                strcpy(tmp->data.num,q->data.num);  
                strcpy(tmp->data.name,q->data.name);  
                tmp->data.sex=q->data.sex;  
                tmp->data.age=q->data.age;  
                tmp->data.result=q->data.result; 
				//�ٸ���p�����Ϣ��q
                strcpy(q->data.num,p->data.num);  
                strcpy(q->data.name,p->data.name);  
                q->data.sex=p->data.sex;  
                q->data.age=p->data.age;  
                q->data.result=p->data.result;
				//�����exchange�����Ϣ��p
                strcpy(p->data.num,tmp->data.num);  
                strcpy(p->data.name,tmp->data.name);  
                p->data.sex=tmp->data.sex;  
                p->data.age=tmp->data.age;  
                p->data.result=tmp->data.result;  
             }  
              q=q->next;  
         }  
         t=t->next; 
         }
        printf("ˢ�º��ѧ����Ϣ�ǣ�\n");  
    	display(L);  
    
         }
   
void sort(LinkList *L){
	  int flag; 
    printf("1.���ɼ��Ӵ�С����\n");
    printf("2.��ѧ�Ŵ�С��������\n");
    printf("����������ʽ��");
	while(1){
		scanf("%d",&flag);
		if(flag==1||flag==2) break;
		else{
			printf("��������ȷ��ѡ��\n"); 
		}
	} 
	//printf("flag=%d\n",flag); 
	if (flag==1) sort_1(L);
	else if(flag==2) sort_2(L);
}  
void saveStuDentFile(LinkList * &L)//����ѧ����Ϣ���ļ�  
{  
    FILE *fp;  
    LinkList *p=L->next;  
    if((fp=fopen("student.txt","w"))==NULL)// �Կ�д�ķ�ʽ�򿪵�ǰĿ¼�µ�.txt  
    {  
        printf("���ܴ򿪴��ļ����밴������˳�\n");  
        exit(1);  //�쳣�˳�
    }  
    while(p)  
    {  
        fprintf(fp,"%s  %s  %c  %d  %d %d %d %d\n",p->data.num,p->data.name,p->data.sex,p->data.age,p->data.result.result_chinese,p->data.result.result_math,p->data.result.result_english,p->data.result.result_sum);  
        p=p->next;  
        printf("����ɹ�\n");  
    }  
    fclose(fp);  
}  

void readStuDentput (LinkList *&L) //����ǰ���ļ����ݶ�ȡ�������ڴ�  
{  
    FILE *fp;  
    fp=fopen("student.txt","rb"); //��ֻ����ʽ�򿪵�ǰĿ¼�µ�.txt  
    if(fp==NULL)  
    {  
        printf("�ļ�������\n");  
       // exit(0);                   //��ֹ����  
    }  
    int i=0;  
    while(!feof(fp)) //feof(fp)����������ֵ:��������ļ�����������feof��fp����ֵΪ����ֵ������Ϊ0 
    {  
        char nu[100];//ѧ��  
        char nam[100];//���� 
        char s;//�Ա�  
        int ag;//����  
         re;//�ɼ�  
        fscanf(fp," %s %s %c %d %d %d %d %d %d",nu,nam,&s,&ag,&re.result_chinese,&re.result_math,&re.result_english,&re.result_sum,&re.result_sum);
        i++;  
    }  
    fclose(fp);  
    FILE *FP;  
    FP=fopen("student.txt","rb"); //��ֻ����ʽ�򿪵�ǰĿ¼�µ�.txt  
    if(FP==NULL)  
    {  
        printf("�޷����ļ�\n");  
        //exit(0); //��ֹ����  
    }  
    int count=i-1;//��¼���ݸ���  
    int j=1;  
        while(!feof(FP))//feof(fp)����������ֵ:��������ļ�����������feof��fp����ֵΪ����ֵ������Ϊ0   
        {  
            fscanf(FP,"%s %s %c %d %d %d %d %d",nu,nam,&s,&ag,&re.result_chinese,&re.result_math,&re.result_english,&re.result_sum);  
            LinkList *n=(LinkList *)malloc(sizeof(LinkList));  
            strcpy(n->data.num,nu);//�Ѻ��ߵ����ݿ�����ǰ����  
            strcpy(n->data.name,nam);//�Ѻ��ߵ����ݿ�����ǰ����  
            n->data.sex=s;  
            n->data.age=ag;  
            n->data.result=re;  
            ListInsert(L,n);//��n�ڵ����L�� 
            n=n->next;  
            if(j==count)  
               break;  
            j++;  
        }  
    fclose(FP);    //�ر��ļ�  
}  
void read_t(LinkList *L)
{
	LinkList *p = L->next;
	while(p)
	{
		Insertree(T_C,p->data.result.result_chinese);
		Insertree(T_M,p->data.result.result_math);
		Insertree(T_E,p->data.result.result_english);
		Insertree(T_S,p->data.result.result_sum);
		p=p->next;
	}	
}
int main()  
{   

	LinkList *L;  
    InitList(L);  
    readStuDentput (L);   //����ǰ���ļ����ݶ�ȡ������   
	read_t(L);//�����ݶ�������� 
	
	
    int choose;  
    while(1)  
    {  
  		printf("\n");
        menu();     //���ܲ˵� 
  		printf("����������ѡ��\n"); 
        scanf("%d",&choose);  
        switch(choose)  
        {  
        
        case 6://������Ϣ���ɼ���ѧ������
   			sort(L);
   			break;
  		case 2: //��ѯѧ����Ϣ
            findstu(L);  
            break;  
        case 3://�޸�ѧ����Ϣ  
   			changestu(L); 
            break; 
  		case 4://����ѧ����Ϣ  
            addstu(L); 
            break; 
 		case 5://ɾ��ѧ����Ϣ  ���ɼ���ѧ��ɾ����
            deletestu(L);  
            break;  
        case 1://�������ѧ������Ϣ  
            display(L);  
            break; 
        case 7://����ѧ����Ϣ���ļ�   
            saveStuDentFile(L);  
            break;
  		case 8://�˳�  
            printf("ллʹ�ã�");  
            exit(0);
        default:  
            printf("��������ȷ��ѡ��\n");  
            break;  
        }  
    } 
 	return 0;
}  

