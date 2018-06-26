/*
*���̿ռ������������ķ�ʽ����1kB��Ϊ�̿�Ϊ���䵥λ������λʾͼ��¼�̿���������λ���̿�0��
*ϵͳ����100k���̿飬ǰ100���̿����ڴ��λͼ��char[]��
*�ļ�Ŀ¼������״Ŀ¼��ϵͳ��ʼ��һ�Ÿ�Ŀ¼���û���ʼλ�ã���ռ��һ���̿�
*Ŀ¼��ļ�����FCB�̿�ţ��ļ�����
*�ļ����ƿ�FCB���ļ�������ʼ�̿�ţ��ļ���С��������,��ָ�룬���ݴ�С��ռ��һ���̿�
*�ļ����ݺ�FCB�ֿ����
*/

#include"FileOperate.h"
#include"DiskOperate.h"
//#include <iostream>
#include <stdio.h>
#include <string.h>
//using namespace std;

//�������
void help();

int main()
{
    //---����ͬ����д
    //int readCount = 0; //��ǰ�Ķ�����
    //semaphore rmutex = 1; //readCount�������
    //semaphore mutex = 1;  //���̶��ļ��Ļ������

    //��ʼ��ϵͳ
    initSystem();
    //������Ŀ¼
    initRootDir();

    help();
    char command[10];
    printf("littleqi:\\>");
    scanf("%s", command);
    while(strcmp(command, "quit") != 0)
    {
        if(strcmp(command, "ls") == 0)//�г�Ŀ¼�������ļ�
        {
            showDir();
            //printf("ls\n");
        }else if(strcmp(command, "help") == 0)//����
        {
            help();
        }else if(strcmp(command, "cd") == 0)//�л�Ŀ¼
        {
            char name[59];
            scanf("%s", name);
            changeDir(name);
        }else if(strcmp(command, "pwd") == 0)//��ʾĿ¼
        {
            printf("%s\n", getPath());
        }else if(strcmp(command, "mkdir") == 0)//����Ŀ¼
        {
            char name[59];
            scanf("%s", name);
            creatDir(name);
        }else if(strcmp(command, "rmdir") == 0)//ɾ��Ŀ¼
        {
            char name[59];
            scanf("%s", name);
            deleteDir(name);
        }else if(strcmp(command, "mv") == 0)//�޸��ļ�����Ŀ¼��
        {
            char oldname[59];
            scanf("%s", oldname);
            char newname[59];
            scanf("%s", newname);
            changeName(oldname, newname);
        }else if(strcmp(command, "touch") == 0)//�����ļ�
        {
            char name[59];
            scanf("%s", name);
            int fileSize;
            scanf("%d", &fileSize);
            creatFile(name, fileSize);
        }else if(strcmp(command, "rm") == 0)//ɾ���ļ�
        {
            char name[59];
            scanf("%s", name);
            deleteFile(name);
        }else if(strcmp(command, "read") == 0)//��ȡ�ļ�
        {
            char name[59];
            scanf("%s", name);
            int length;
            scanf("%d", &length);
            /*
            wait(rmutex)
            if(readCount==0)
                wait(mutex);
            readCount++;
            signal(rmutex);
            */
            read(name, length);
            /*
            wait(rmutex);
            readCount--;
            if(readCount == 0)
                signal(mutex);
            signal(rmutex);
            */
        }else if(strcmp(command, "reread") == 0)//�����ָ��Ϊ���
        {
            char name[59];
            scanf("%s", name);
            int length;
            scanf("%d", &length);
            /*
            wait(rmutex)
            if(readCount==0)
                wait(mutex);
            readCount++;
            signal(rmutex);
            */
            reread(name, length);
            /*
            wait(rmutex);
            readCount--;
            if(readCount == 0)
                signal(mutex);
            signal(rmutex);
            */
        }else if(strcmp(command, "write") == 0)//д�ļ�,ֻ֧�ִ�ĩβд��
        {
            char name[59];
            scanf("%s", name);
            char content[1024];
            scanf("%s", content);
            //wait(mutex);
            write(name, content);
            //signal(mutex);
        }else if(strcmp(command, "rewrite") == 0)//����д�ļ�
        {
            char name[59];
            scanf("%s", name);
            char content[1024];
            scanf("%s", content);
            //wait(mutex);
            rewrite(name, content);
            //signal(mutex);
        }else
        {
            printf("command error\n");
        }

        printf("littleqi:%s>", getPath());
        scanf("%s", command);
    }
    exitSystem();

    return 0;
}
void help()
{
    printf("Ŀ¼�������\nls\npwd\ncd dirName\nmkdir dirName\nrmdir dirName\nmv fileName newName\n");
    printf("�ļ��������\ntouch fileName size(�ļ���С) ep:touch a.txt 10\nrm fileName\n");
    printf("read fileName size(��ȡ�ֽڳ���) ����һ�ο�ʼ��ep:read a.txt 10\nreread fileName size ��ͷ��ʼ��\n");
    printf("write fileName content(д������) ��ĩβд��ep:write a.txt helloworld\nrewrite fileName content ��ͷ��ʼд\n");
    printf("\n");
}
