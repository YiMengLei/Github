
#include<stdio.h>
int main()
{
    int t[100002],n,k,m,i,j,p,mid,r;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&t[i]);
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        r=-1;
        p=0;
        j=n-1;
        scanf("%d",&m);
        while (p<=j)//《小于等于号
            
        {
            mid=(j+p)/2;
            if(t[mid]>=m)
            {
                j=mid-1;
                r=t[mid];
            }
            else
                
                p=mid+1;
        }
        printf("%d\n",r);
    }
}

