#include<stdio.h>
float max(float,float);
int main()
{
    float a,b;
    int c;
    scanf("%f %f",&a,&b);
    c=max(a,b);
    printf("MAX is %d\n",c);
}
float max(float x,float y)
{
    float z;
    z=x>y?x:y;
    return z;
}
r



