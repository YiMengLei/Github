#include<stdio.h>
strlens();
main()
{char str[100];
    printf("please enter the string which you want to find the length\n");
    scanf("%s",str);
    printf("the length of '%s' is %d",str,strlens(str));
    
}

strlens(string)
char *string;
{
    int i=0;
    while(*(string++))
        i++;
    return i;
    
}


