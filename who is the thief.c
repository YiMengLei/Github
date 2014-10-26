#include<stdio.h>
void main()
{int sus,jud,con[4];
    for(sus=0;sus<4;sus++)/*suspect one person as the thief*/
    {
        for(jud=0;jud<4;jud++)/*use value to express the person as a thief,'1'for thief,'0'for normal*/
        {
            if(jud==sus)
                con[jud]=1;
            else
                con[jud]=0;
        }
    if(con[1]+con[3]==1&&con[1]+con[2]==1&&con[0]+con[1]==1)/*judge if this person is a thief*/
        printf("THE THIEF IS %c\n",sus+'A');/*show off the result*/
    }
    }