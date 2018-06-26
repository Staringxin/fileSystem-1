#ifndef FILEOPERATE_H_INCLUDED
#define FILEOPERATE_H_INCLUDED

//�ļ�����
#include"DiskOperate.h"

#define dirTable_max_size 15    //Ŀ¼�������ֵ

//Ŀ¼�� 64B
struct dirUnit{
    char fileName[59];  //�ļ���
    char type;  //�ļ�����,0Ŀ¼�� 1�ļ�
    int startBlock; //��ʼ�̿�
};
//Ŀ¼��
    //һ��Ŀ¼��ռ��һ���̿飬��������ļ���Ϊ15
struct dirTable {
    int dirUnitAmount;//Ŀ¼����Ŀ
    dirUnit dirs[dirTable_max_size];//Ŀ¼���б�
};

//FCB
struct FCB {
    int blockNum;   //�ļ�������ʼ�̿��
    int fileSize;   //�ļ���С���̿�Ϊ��λ
    int dataSize;   //��д������ݴ�С���ֽ�Ϊ��λ
    int readptr;    //��ָ�룬�ֽ�Ϊ��λ
    int link;   //�ļ�������
};

//�ļ�ϵͳ����
//��ʼ����Ŀ¼
void initRootDir();
//չʾ����·��
char* getPath();
//չʾ��ǰĿ¼�ļ�
void showDir();
//����Ŀ¼
int creatDir(char dirName[]);
//�л�Ŀ¼
int changeDir(char dirName[]);
//ɾ��Ŀ¼
int deleteDir(char fileName[]);
//�޸��ļ�������Ŀ¼��
int changeName(char oldName[], char newName[]);

//�����ļ�
int creatFile(char fileName[], int fileSize);
//ɾ���ļ�
int deleteFile(char fileName[]);


//���ļ�
int read(char fileName[], int length);
//���¶��ļ�
int reread(char fileName[], int length);
//ִ�ж�����
int doRead(FCB* myFCB, int length);
//д�ļ�����ĩβд��
int write(char fileName[], char content[]);
//����д����
int rewrite(char fileName[], char content[]);
//ִ��д����
int doWrite(FCB* myFCB, char content[]);

//�ͷ��ļ��ڴ�
int releaseFile(int FCBBlock);
//���Ŀ¼��
int addDirUnit(dirTable* currentDirTable, char fileName[], int type, int FCBBlockNum);
//����FCB
int creatFCB(int fcbBlockNum, int fileBlockNum, int fileSize);
//ָ��Ŀ¼ɾ��
int deleteFileInTable(dirTable* myDirTable, int unitIndex);
//ɾ��Ŀ¼��
int deleteDirUnit(dirTable* currentDirTable, int unitIndex);
//��Ŀ¼�в���Ŀ¼��Ŀ
int findUnitInTable(dirTable* currentDirTable, char unitName[]);


#endif // FILEOPERATE_H_INCLUDED
