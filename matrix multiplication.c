#include<stdio.h>
#define A_row 4
#define A_column 5
#define B_row 5
#define B_column 3
void main()
{
    int A[A_row][A_column],B[B_row][B_column],C[A_row][B_column],i,j,k,s=0;
    for(i=0;i<4;i++)
    {
        printf("Please insert matrix A's %d row:\n",i);
        scanf("%d %d %d %d %d",&A[i][j],&A[i][j+1],&A[i][j+2],&A[i][j+3],&A[i][j+4]);
    }
    for(i=0;i<5;i++)
    {
        printf("Please insert matrix B's %d row:\n",i);
        scanf("%d %d %d",&B[i][j],&B[i][j+1],&B[i][j+2]);
    }
    for(i=0;i<4;i++)
        for(j=0;j<3;j++)
        {
            s=0;
            for(k=0;k<5;k++)
                s+=A[i][k]*B[k][j];
            C[i][j]=s;
        }
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
            printf("%13d ",C[i][j]);
        printf("\n");
    }
}

