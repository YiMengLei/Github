#include<stdio.h>
main()
{
    char a[30],b[30];
    printf("enter a string");
    scanf("%s",a);
    strcopy(a,b);
    printf("a=%s\nb=%s",a,b);
}
strcopy(str1,str2)
    char *str1,*str2;
{while((*str2++)=(*str1++));
    return 0;
}




        

