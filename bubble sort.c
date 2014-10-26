#include<stdio.h>
int main()
{int circ,num,a[10],temp;
    printf("Please insert 10 numbers!");
    for(num=0;num<10;num++)//输入
        scanf("%d",&a[num]);
    for(circ=0;circ<9;circ++)//控制轮数
        for(num=0;num<9-circ;num++)//在每一轮中比较大小并将最大的放到后面去
        {
            if(a[num]>a[num+1])//比较大小并将最大的移到后面去
                temp=a[num];
                a[num]=a[num+1];
                a[num+1]=temp;
        }
    for(num=0;num<10;num++)
        printf("%d ",a[num]);
}

    
