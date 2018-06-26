#ifndef DISKOPERATE_H_INCLUDED
#define DISKOPERATE_H_INCLUDED
//���̲����ӿ�
#define system_size 100*1024*1024   //ϵͳ��С
#define block_szie 1024 //�̿��С
#define block_count system_size/block_szie //ϵͳ�̿���Ŀ

//��ʼ��ϵͳ
void initSystem();
//���̷���
int getBlock(int blockSize) ;
//����̿�������ַ
char* getBlockAddr(int blockNum);
//��������ַ���̿��
int getAddrBlock(char* addr);
//�ͷ��̿顢
int releaseBlock(int blockNum, int blockSize);
//�˳�ϵͳ
void exitSystem();
#endif // DISKOPERATE_H_INCLUDED
