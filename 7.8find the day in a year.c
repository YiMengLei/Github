#include<stdio.h>
int day_in_a_year(int leap_normal_day[2][13],int year,int month,int day);//要写分号
main()
{
    int year,month,day;
    static int leap_normal_day[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
    printf("please insert the date");
    scanf("%d%d%d",&year,&month,&day);
    
    printf("%d",day_in_a_year(leap_normal_day[][13],year,month,day));
           }
          int day_in_a_year(leap_normal_day[][13],year,month,day)
        int leap_normal_day[][13];//为什么书上可以讲前两行写在大括号外面
        int year,month,day;
{int i,j;
        i=(year%4==0&&year%100==0)||year%400==0;
        for(j=1;j<month;j++)
            day+=;//*(leap_normal_day+i*13+j);
        return(day);
    }




