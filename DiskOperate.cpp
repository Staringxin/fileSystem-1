#include"DiskOperate.h"

#include<stdio.h>
#include<stdlib.h>



char* systemStartAddr;  //ϵͳ��ʼ��ַ

//��ʼ��ϵͳ
void initSystem()
{
    //�����ռ�
    systemStartAddr = (char*)malloc(system_size * sizeof(char));
    //��ʼ���̿��λʾͼ
    for(int i=0; i<block_count; i++)
        systemStartAddr[i] = '0';
    //���ڴ��λʾͼ�Ŀռ��ѱ�ռ��
    int bitMapSize = block_count * sizeof(char) / block_szie;//λʾͼռ���̿���:100
    for(int i=0; i<bitMapSize; i++)//���㿪ʼ����
        systemStartAddr[i] = '1';   //�̿��ѱ�ʹ��
}
//�˳�ϵͳ
void exitSystem()
{
    free(systemStartAddr);
}
//���̷���
int getBlock(int blockSize)
{
    int startBlock = 0;
    int sum=0;
    for(int i=0; i<block_count; i++)
    {
        if(systemStartAddr[i] == '0')//�����̿�
        {
            if(sum == 0)//�տ�ʼ�����ÿ�ʼ�̿��
                startBlock = i;
            sum++;
            if(sum == blockSize)//�����̿��Ƿ���������
            {
                //������䣬��1
                for(int j=startBlock; j<startBlock+blockSize; j++)
                    systemStartAddr[j] = '1';
                return startBlock;
            }

        }
        else//�ѱ�ʹ��,�����Ѿ������
            sum = 0;
    }
    printf("not found such series memory Or memory is full\n");
    return -1;
}
//����̿�������ַ
char* getBlockAddr(int blockNum)
{
    return systemStartAddr + blockNum * block_szie; //ƫ������λΪ�ֽ�
}
//��������ַ���̿��
int getAddrBlock(char* addr)
{
    return (addr - systemStartAddr)/block_szie;
}
//�ͷ��̿顢
int releaseBlock(int blockNum, int blockSize)
{
    int endBlock = blockNum + blockSize;
    //�޸�λʾͼ�̿��λ��Ϊ0
    for(int i=blockNum; i<endBlock; i++)
        systemStartAddr[i] = '0';
    return 0;
}
