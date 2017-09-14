#include <stdio.h>
//思路  分别求出以1 2 3 4 5 开头 剩下数字的全排列  一直到简化为一个数字
void swap(int a[],int k) 
{
  int i,m,t=0;
  if(k==5) 
  {
    for (i=0;i<5;i++) 
    {
      printf("%d ",a[i]);
    }
    //k++;
    printf("\n");
  }
  for (i=k;i<5;i++) 
  { 
    {
      m=a[k];
      a[k]=a[i];
      a[i]=m;
    }
    swap(a,k+1); 
    {
      m=a[k];
      a[k]=a[i];
      a[i]=m;
    }
  }
}
int main() 
{
  int a[5]={1,2,3,4,5};
  //进行递归运算的数值
  swap(a,0);
  //函数调用
  return 0;
}