# fileSystem
简易Linux文件系统

编译

```shell
$ g++ main.cpp FileOperate.cpp DiskOperate.cpp -o main
```

基于<https://blog.csdn.net/little_qi/article/details/73801336> 

#### 创建

系统大小：`1024*1024*100`：100m

盘块大小：`1024`：1kb

系统盘块数：`1024*100`：100kb

1. 初始化系统
   * 分配空间
   * 初始化盘块的位示图
   * 系统开头存放位示图
2. 初始化根目录
   * 分配第一个可用盘块
   * 设置`rootDirTable`和`currentDirTable`为当前目录

目录表

```c
struct dirTable {
    int dirUnitAmount;               //目录项数目
    dirUnit dirs[dirTable_max_size]; //目录项列表
};
```

目录项

```c
struct dirUnit {
    char fileName[59]; //文件名
    char type;         //文件类型,0目录， 1文件
    int startBlock;    //起始盘块
};
```

FCB

```c
struct FCB {
    int blockNum; //文件数据起始盘块号
    int fileSize; //文件大小，盘块为单位
    int dataSize; //已写入的内容大小，字节为单位
    int readptr;  //读指针，字节为单位
    int link;     //文件链接数
};
```



#### ls: 展示当前目录

1. 先取得当前目录`dirtable`，然后取得目录项里的所有表项
2. 遍历表项`dirUnit`
3. 根据`dirUnit`的`type`信息判断该项是文件还是目录
4. 如果是文件，继续输出文件其他信息

#### mkdir: 

1. 先判断长度
2. 得到空闲块创建目录表
3. 将目录作为目录项添加到当前目录表中
   * 检测当前目录表是否已满
   * 创建新的目录项内容并连接到目录表末尾
4. 为新建目录添加返回目录项`..`

#### touch: 

1. 得到空闲块分配给FCB
2. 获取FCB的数据空间
3. 创建FCB
   * 找到地址
   * 赋值对应属性
4. 将该目录项添加到目录表中

#### read:

1. 根据文件名查找对应目录项
2. 取得当前目录项的`startBlock`为`FCBBlock`
3. 读操作
   * 根据FCB的指针读取内容`readptr`会改变（reread只需先将`readptr`置零）

#### write：

1. 与读类似
2. data+dataSize定位输入内容

​	

