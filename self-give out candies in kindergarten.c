#include<stdio.h>
 int judge();
void main()
{
    int s[]={10,2,8,22,16,4,10,6,14,20};
    
    int t[10],i,n=0;
    printf("round  1  2  3  4  5  6  7  8  9  10\n");
    printf("---------------------------------------------------\n");
    while(judge(s,10))
    {
        for(i=0;i<9;i++)       //重新分配2-10
        {
            if(s[i]%2==0)
                {
                    if(s[i+1]%2==0)
                    t[i]=s[i]/2+s[i+1]/2;
                    else
                    t[i]=s[i]/2+(s[i+1]+1)/2;
                }
            else
                {
                    if(s[i+1]%2==0)//没模除
                    t[i]=(s[i]+1)/2+s[i+1]/2;
                    else
                    t[i]=(s[i]+1)/2+((s[i+1]+1)/2);//s[i+1]+1加括号
                }
        }
    
    n++;
    
           if(s[0]%2==0&&s[9]%2==0)     //重新分配1，并赋值1
               s[0]=s[0]/2+s[9]/2;
           else if(s[0]%2==1&&s[9]%2==0)
               s[0]=(s[0]+1)/2+s[9]/2;
           else if(s[0]%2==0&&s[9]%2==1)
               s[0]=s[0]/2+(s[9]+1)/2;
           else if(s[0]%2==1&&s[9]%2==1)
               s[0]=(s[0]+1)/2+(s[9]+1)/2;
  
            for(i=1;i<10;i++)       //赋值2-10
            s[i]=t[i-1];
        
        printf("%7d",n);
    for(i=0;i<10;i++)
        printf("%4d",s[i]);
                 printf("\n");
    }
    
                
}
int judge(int s[],int j)
{
for(int k=1;k<j;k++)
{
    if(s[0]!=s[k])
        {
         return 1;
         break;
        }
}
            return 0;
}

