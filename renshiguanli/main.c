#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void password();//��ӭ��䣬�������롣
void hello();//��ʼ����

typedef struct personnelArchiveInfo{
    char num[10];
    char name[10];
    char sex[5];
    int age;
    char job[10];
    char post[10];
    char politic[10];
    char edu_level[10];
    char period[10];
    char start_time[10];
}PAInfo;

struct link{
    PAInfo data;
    struct link *next;
};

struct link *AppendNode(struct link *head);//���һ������
void DisplyNode(struct link *head);
void DeleteMemory(struct link *head);//�ͷ��ڴ�
void Inputdata();

/*��������ģ��*/



int main()
{
    int se;
    //password();
    hello();
    printf("���������\n");
    scanf("%d",&se);
    getchar();
    if(se == 1){
        Inputdata();
    }
    return 0;
}

void password(){
    printf("Hello!\n");
    printf("welcome to use the personal management system!\n");
    char password[11] = {"jiangkaida"};
    char s[11];
    int flag = 0;
    int n = 3;
    int i,m;
    do{
        printf("please input your password:\n");
        for(m = 0;m < 10;m++){
            s[m] = getch();
            putchar('*');
        }
        s[m] = '\0';
        printf("\n");
        if((!strcmp(s,password))){
            printf("land successfully!\n");
            flag = 1;
            break;

        }
        else{
            printf("error!please input again!\n");
            n--;
        }
    }while(n>0);
    if(!flag){
        printf("Input error more than three times!");
        exit(0);
    }
}

void hello(){
    printf("* * * * * * * * * * * * * * * * * * * \n");
    printf("*      ��ӭʹ�����¹���ϵͳ��       * \n");
    printf("*     �����빦����Ž���ʹ�ã�      * \n");
    printf("*\t1.�½�Ա����Ϣ              * \n");
    printf("*\t2.���Ա����Ϣ              * \n");
    printf("*\t3.ɾ��Ա����Ϣ              * \n");
    printf("*\t4.��ѯԱ����Ϣ              * \n");
    printf("*\t5.�޸�Ա����Ϣ              * \n");
    printf("*\t6.����Ϣ��������            * \n");
    printf("*\t7.ͳ��Ա����Ϣ              * \n");
    printf("* * * * * * * * * * * * * * * * * * * \n");
}

void Inputdata(){
    struct link *head = NULL;
    char c;
    int i = 0;
    printf("����Ҫ�½�һ��Ա��������(Y/N)?");
    scanf(" %c",&c);
    while(c == 'Y' || c == 'y'){
        head = AppendNode(head);
        printf("����Ҫ���½�һ��Ա��������(Y/N)?");
            scanf(" %c",&c);
            i++;
    }
    while(getchar()!='\n');
    printf("���ɹ��½��� %d ��Ա������,�Ƿ���Ҫ��ʾ��ϸ��Ϣ��\n",i);
    scanf(" %c",&c);
    while(c == 'y' || c == 'Y'){
    DisplyNode(head);
    }
}

struct link *AppendNode(struct link *head){
    struct link *p = NULL, *pr = head;
    PAInfo data;
    p = (struct link *)malloc(sizeof(struct link));
    if(p == NULL){
        printf("�ڴ治�㣡");
        exit(0);
    }
    if(head ==NULL){
        head = p;
    }
    else{
        while(pr->next!=NULL){
            pr = pr ->next;
        }
    }
    printf("������Ա������ϸ��Ϣ\n");
    printf("�����ţ�");
    scanf("%s",data.num);
    printf("����������");
    scanf("%s",data.name);
    printf("�����Ա�");
    scanf("%s",data.sex);
    printf("�������䣺");
    scanf("%d",&data.age);
    printf("����ְ��");
    scanf("%s",data.job);
    printf("����ְ�ƣ�");
    scanf("%s",data.post);
    printf("����������ò��");
    scanf("%s",data.politic);
    printf("�������ѧ����");
    scanf("%s",data.edu_level);
    printf("������ְʱ�䣺");
    scanf("%s",data.period);
    printf("������Ժʱ�䣺");
    scanf("%s",data.start_time);
    p->data = data;
    p->next = NULL;
    return head;
}

void DisplyNode(struct link *head){
    struct link *p = head;
    int j = 1;
    while(p!= NULL){
        printf("--------�� %d ��Ա����Ϣ--------",j);
        printf("|\t������%s            \n",p->data.name);
        printf("|\t��ţ�%s            \n",p->data.num);
        printf("|\t�Ա�%s            \n",p->data.sex);
        printf("|\t���䣺%d            \n",p->data.age);
        printf("|\tְ��%s            \n",p->data.job);
        printf("|\tְ�ƣ�%s            \n",p->data.post);
        printf("|\t������ò��%s",p->data.politic);
        printf("|\t���ѧ����%s",p->data.edu_level);
        printf("|\t��ְʱ�䣺%s",p->data.period);
        printf("|\t��Ժʱ�䣺%s",p->data.start_time);
        printf("--------------------------------");
        p = p->next;
        j++;
    }
}


