#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    long studentid;
    char studentname[15];
    int score[6];
    int totalscore;
}STUDENT;
void one(STUDENT stu[],int studentnum,int classesnum);
void two(STUDENT stu[],int studentnum,int classesnum);
void three(STUDENT stu[],int studentnum,int classesnum);
void four(STUDENT stu[],int studentnum,int jiangxu[]);
void five(STUDENT stu[],int studentnum,int shengxu[]);
void six(STUDENT stu[],int studentnum,int IDshengxu[],int IDscore[]);
void seven(STUDENT stu[],int studentnum);
void eight(STUDENT stu[],int studentnum,int jiangxu[]);
void nine(STUDENT stu[],int studentnum,int jiangxu[]);
void ten(STUDENT stu[],int studentnum,int classesnum);
int main()
{
    int studentnum,classesnum,choice,k;
    int jiangxu[30],shengxu[30],IDscore[30];
    long IDshengxu[30];
    STUDENT stu[30];
    //����ѧ����������������
    printf("Input the number of student:");
    scanf("%d" ,&studentnum);
    printf("Input the number of classes:");
    scanf("%d" ,&classesnum);
    for(k=0;k<20;k++)
    {
        //ѡ��˵�
        printf("--------------------------------------------------------------------------------------\n");
        printf("1.¼��ÿ��ѧ����ѧ�š����������ƿ��Գɼ�\n");
        printf("2.����ÿ�ſγ̵��ֺܷ�ƽ����\n");
        printf("3.����ÿ��ѧ�����ֺܷ�ƽ����\n");
        printf("4.��ÿ��ѧ�����ܷ��ɸߵ����ų����α�(ע��ʹ��4ʱ����ʹ��3)\n");
        printf("5.��ÿ��ѧ�����ܷ��ɵ͵����ų����α�(ע��ʹ��5ʱ����ʹ��3)\n");
        printf("6.��ѧ�Ŵ�С�ų��ɼ���(ע��ʹ��6ʱ����ʹ��3)\n");
        printf("7.���������ֵ�˳���ų��ɼ���(ע��ʹ��7ʱ����ʹ��3)\n");
        printf("8.��ѧ�Ų�ѯѧ���������俼�Գɼ�(ע��ʹ��8ʱ����ʹ��3��4)\n");
        printf("9.��������ѯѧ���������俼�Գɼ�(ע��ʹ��9ʱ����ʹ��3��4)\n");
        printf("10.�����㡢���á��еȡ����񡢲������ÿ�ŷֱ�ͳ��ÿ������������ռ����\n");
        printf("11.���ÿ��ѧ����ѧ�š����������ƿ��Գɼ����Լ�ÿ�ſγ̵��ֺܷ�ƽ����\n");
        printf("12.��ÿ��ѧ���ļ�¼��Ϣд���ļ�\n");
        printf("13.���ļ��ж���ÿ��ѧ���ļ�¼��Ϣ����ʾ\n");
        printf("0.�˳�����\n");
        printf("Please enter your choice\n");
        scanf("%d" ,&choice);
        printf("--------------------------------------------------------------------------------------\n");
        getchar();
        //ѡ��ִ�г���
        if(choice==0)
            exit(0);
        else if(choice==1)
            one(stu,studentnum,classesnum);
        else if(choice==2)
            two(stu,studentnum,classesnum);
        else if(choice==3)
            three(stu,studentnum,classesnum);
        else if(choice==4)
            four(stu,studentnum,jiangxu);
        else if(choice==5)
            five(stu,studentnum,shengxu);
        else if(choice==6)
            six(stu,studentnum,IDshengxu,IDscore);
        else if(choice==7)
            seven(stu,studentnum);
        else if(choice==8)
            eight(stu,studentnum,jiangxu);
        else if(choice==9)
            nine(stu,studentnum,jiangxu);
        else if(choice==10)
            ten(stu,studentnum,calssesnum);
    }
    return 0;
}
//��һ��С����
void one(STUDENT stu[],int studentnum,int classesnum)
{
    int i,j;
    for(i=0;i<studentnum;i++)
    {
        printf("Input studentID:");
        scanf("%ld" ,&stu[i].studentid);
        printf("Input studentname:");
        scanf("%s" ,stu[i].studentname);
        printf("Input all scores:");
        for(j=0;j<classesnum;j++)
            scanf("%d" ,&stu[i].score[j]);
    }
}
//�ڶ���С����
void two(STUDENT stu[],int studentnum,int classesnum)
{
    int i,j,sum=0;
    for(i=0;i<classesnum;i++)
    {
        for(j=0;j<studentnum;j++)
            sum = sum+stu[j].score[i];
        printf("��%d�ſγ��ܷ�%d,��%d�ſγ�ƽ����%.2f\n" ,i+1,sum,i+1,(float)sum/studentnum);
        sum=0;
    }
}
//������С����
void three(STUDENT stu[],int studentnum,int classesnum)
{
    int i,j,sum=0;
    for(i=0;i<studentnum;i++)
    {
        for(j=0;j<classesnum;j++)
            sum = sum+stu[i].score[j];
        stu[i].totalscore = sum;
        printf("%s�γ��ܷ�%d,�γ�ƽ����%.2f\n" ,stu[i].studentname,sum,(float)sum/studentnum);
        sum=0;
    }
}
//���ĸ�С����
void four(STUDENT stu[],int studentnum,int jiangxu[])
{
    int i,temp,j;
    for(i=0;i<studentnum;i++)
        jiangxu[i] = stu[i].totalscore;
    for(i=0;i<studentnum-1;i++)
    {
        for(j = i+1;j<studentnum;j++)
        {
            if(jiangxu[j]>jiangxu[i])
            {
                temp = jiangxu[i];
                jiangxu[i] = jiangxu[j];
                jiangxu[j] = temp;
            }
        }
    }
    printf("�������гɼ���\n");
    for(i=0;i<studentnum;i++)
        printf("��%d:%d\n" ,i+1,jiangxu[i]);
}
//�����С����
void five(STUDENT stu[],int studentnum,int shengxu[])
{
    int i,temp,j;
    for(i=0;i<studentnum;i++)
        shengxu[i] = stu[i].totalscore;
    for(i=0;i<studentnum-1;i++)
    {
        for(j = i+1;j<studentnum;j++)
        {
            if(shengxu[j]<shengxu[i])
            {
                temp = shengxu[i];
                shengxu[i] = shengxu[j];
                shengxu[j] = temp;
            }
        }
    }
    printf("�������гɼ���\n");
    for(i=0;i<studentnum;i++)
        printf("%d\n" ,shengxu[i]);
}
//������С����
void six(STUDENT stu[],int studentnum,int IDshengxu[],int IDscore[])
{
    int i,j,temp;
    for(i=0;i<studentnum;i++)
        IDshengxu[i] = stu[i].studentid;
    for(i=0;i<studentnum;i++)
        IDscore[i] = stu[i].totalscore;
    for(i=0;i<studentnum-1;i++)
    {
        for(j = i+1;j<studentnum;j++)
        {
            if(IDshengxu[i]>IDshengxu[j])
            {
                temp = IDshengxu[i];
                IDshengxu[i] = IDshengxu[j];
                IDshengxu[j] = temp;
                temp = IDscore[i];
                IDscore[i] = IDscore[j];
                IDscore[j] = temp;
            }
        }
    }
    for(i=0;i<studentnum;i++)
        printf("ѧ�ţ�%ld,�ɼ���%d\n" ,IDshengxu[i],IDscore[i]);
}
//���߸�С����
void seven(STUDENT stu[],int studentnum)
{
    char temp[15];
    int i,j,s,temp1;
    for(i=0;i<studentnum-1;i++)
    {
        for(j=i+1;j<studentnum;j++)
        {
            s = strcmp(stu[i].studentname , stu[j].studentname);
            if(s>0)
            {
                strcpy(temp , stu[i].studentname);
                strcpy(stu[i].studentname , stu[j].studentname);
                strcpy(stu[j].studentname , temp);
                temp1 = stu[i].totalscore;
                stu[i].totalscore = stu[j].totalscore;
                stu[j].totalscore = temp1;
            }
        }
    }
    for(i=0;i<studentnum;i++)
        printf("%s�ĳɼ�%d\n" ,stu[i].studentname,stu[i].totalscore);
}
//�ڰ˸�С����
void eight(STUDENT stu[],int studentnum,int jiangxu[])
{
    int i,a=0,j;
    long IDsearch;
    printf("������Ҫ���ҵ�ѧ��");
    scanf("%ld" ,&IDsearch);
    getchar();
    for(i=0;i<studentnum;i++)
    {
        if(IDsearch == stu[i].studentid)
        {
            a = 1;
            for(j=0;j<studentnum;j++)
            {
                if(stu[i].totalscore == jiangxu[j])
                {
                    printf("ѧ�ţ�%ld,�ɼ���%d,������%d\n" ,IDsearch,stu[i].totalscore,j+1);
                    break;
                }
            }
            break;
        }
    }
    if(a==0)
        printf("�Բ���δ�鵽����\n");
}
//�ھŸ�С����
void nine(STUDENT stu[],int studentnum,int jiangxu[])
{
    int i,result,a=0,j;
    char temp[15];
    printf("������Ҫ���ҵ�����");
    gets(temp);
    for(i=0;i<studentnum;i++)
    {
        result = strcmp(temp,stu[i].studentname);
        if(result==0)
        {
            a = 1;
            for(j=0;j<studentnum;j++)
            {
                if(stu[i].totalscore == jiangxu[j])
                {
                    printf("%s�ĳɼ���%d,������%d\n" ,temp,stu[i].totalscore,j+1);
                    break;
                }
            }
            break;
        }
    }
    if(a==0)
        printf("�Բ���δ�鵽����\n");
}
//��ʮ��С����
void ten

