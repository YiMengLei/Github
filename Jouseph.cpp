//
//  main.cpp
//  Data structure and algorithim analysis
//
//  Created by sherry on 14-10-13.
//  Copyright (c) 2014年 sherry. All rights reserved.
//
#include<iostream>
using namespace std;

int main()
{
    int N;
    int M;
    int i=0,cancle=0,num=0;
    cout<<"Josephus problem"<<endl
    <<"Please insert the number of people"<<endl;
    cin>>N;
    int* cell=new int[N];
    cout<<"Please insert the number to be eliminated"<<endl;
    cin>>M;
    cout<<"The elimission squence is"<<endl;
    for(i=0;i<N;i++)
    {
        cell[i]=1;
    }
    i=0;
        while(cancle<N-1)
        {
            if(M!=0)
            {
                while(num<M)
                {
                    if(cell[i]==1)
                        num++;
                    if(i==N-1)
                        i=0;
                    else
                        i++;
                    while(cell[i]==0)
                    {
                        if(i==N-1)
                            i=0;
                        else
                            i++;
                    }
                }
                cell[i]=0;
                cancle++;
                if(i==0)
                    cout<<1<<endl;
                else
                    cout<<i+1<<endl;
                num=0;
            }
            else
            {
                cell[i]=0;
                cancle++;
                if(i==0)
                    cout<<1<<endl;
                else
                    cout<<i+1<<endl;
                i++;
        
            }
        }
    for(i=0;i<N;i++)
    {
        if(cell[i]==1)
            break;
    }
    cout<<"The winner is "<<i+1;
}


