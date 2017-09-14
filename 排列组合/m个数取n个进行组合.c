/*

[10反转置换法]
算法思想：
     (1)  初始化一个m个元素的数组（全部由0，1组成），将前n个初始化为1，后面的为0。这时候就可以输出第一个组合序列了。
     (2)  从前往后找，找到第一个10组合，将其反转成01，然后将这个10组合前面的所有1，全部往左边推 ，即保证其前面的1都在最左边。这时又可以输出一组组合序列了。
     (3)  重复第(2)步，知道找不到10组合位置。这时已经输出了全部的可能

*/

#include <stdio.h>
#include <stdlib.h>
void putout(int * num,int m) 
{
  int i;
  for (i=0;i<m;i++) 
  {
    if(*(num+i))
       printf("%d ",i+1);
  }
  printf("\n");
}
int check(int *num,int m,int n) 
{
  int flag=1,i;
  //当flag=1时，继续while循环 反之，退出循环
  for (i=0;i<m-n;i++) 
  {
    if(*(num+i)) 
    {
      return  1;
    }
  }
  return 0;
}
void choseNum(int *num,int m,int n) 
{
  int i,j;
  putout(num,m);
  //输出第一个组合
  while(1) 
  {
    int count=0;
    //注意count位置  就他调试了半天
    //找第一个1 0组合
    for (i=0;i<m-1;i++) 
    {
      if(*(num+i)==1&&*(num+i+1)==0) 
      {
        *(num+i)=0;
        *(num+i+1)=1;
        break;
      }
      if(*(num+i))  //统计前面出现出现1的次数
      count++;
    }
    for (j=0;j<i;j++) 
    {
      if(j<count)  //将前面几个数全为1 
      {
        *(num+j)=1;
      } else       //后几个数为0 
      {
        *(num+j)=0;
      }
    }
    putout(num,m);
    if(check(num,m,n)!=1)
       break;
  }
  free(num);
}
int main() 
{
  int m,n;
  //从m个数中找n个求组合
  printf("从m个数中n个数的组合：");
  scanf("%d %d",&m,&n);
  int *num,i;
  //int count;
  num=(int *)malloc(sizeof(int)*m);
  for (i=0;i<m;i++) 
  {
    if(i<n)
       *(num+i)=1; else
       *(num+i)=0;
  }
  choseNum(num,m,n);
  return 0;
}     