#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void password();//��¼���棬��ӭ��䣬�������롣

typedef struct personnelArchiveInfo{
    char num[10];
    char name[10];
    int sex;
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
void displyNode(struct link *head);//����һ�����нڵ㲢��ʾ����Ϣ
void deleteMemory(struct link *head);//�ͷ��ڴ�
/*��������ģ��*/



int main()
{
    PAInfo sum[10];
    password();
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
