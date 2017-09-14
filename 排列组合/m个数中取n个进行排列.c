#include <stdio.h>
void swap(int a[],int b[],int i,int size) 
{
  int k,j,temp;
  if(i==3) 
  {
    for (k=0;k<3;k++) 
    {
      printf("%d ",b[k]);
    }
    printf("\n");
    return;
  } else 
  {
    for (j=0;j<size;j++) 
    {
      b[i]=a[j];
      temp=a[j];
      a[j]=a[size-1];
      a[size-1]=temp;
      swap(a,b,i+1,size-1);
      temp=a[j];
      a[j]=a[size-1];
      a[size-1]=temp;
    }
  }
}
int main() 
{
  int a[5]={1,2,3,4,5},b[3];
  //求5个数中三个数的全排列
  swap(a,b,0,5);
  return 0;
}