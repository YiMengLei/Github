//
//  main.cpp
//  c++
//
//  Created by sherry on 14-9-18.
//  Copyright (c) 2014年 sherry. All rights reserved.
//
#include "class.h"
#include <iostream>

int main(void)
{
    int flag=1;
    double x;
    int y;
    List list1,list2;
    cout<<"Please insert the coefficient and the pow in pairs as '2 3/n 7 9/n 3 0/n 0 0/n'means'2x^3+7x^9+3x^0('0' is stop sign)'for the first polinomial"<<endl;
    do {
        cout<<"Please insert"<<endl;
        cin>>x>>y;
        if(x==0)
            break;
        list1.InsertNode(x,y);
    }while (x!=0);

    cout<<"The first polinomial is"<<endl;
    cout<<"f(x)=";
    list1.DisplayList();
    cout<<endl<<endl<<"Please insert the coefficient and the pow in pairs for the second polinomial"<<endl;
    do {
        cout<<"Please insert"<<endl;
        cin>>x>>y;
        if(x==0)
            break;
        list2.InsertNode(x,y);
    }while (x!=0);
    
    cout<<"The second polinomial is"<<endl;
    cout<<"g(x)=";
    list2.DisplayList();
    cout<<endl<<endl<<"If you want to add this two polynomials,please insert '1'"<<endl
    <<"If you want to minus the second polynomial from the first polynomial,please insert '0'"<<endl<<endl;
    cin>>flag;
    if(flag)
        list1.AddList(list2);
    else
        list1.minusList(list2);
    if(flag)
        cout<<"F(x)=f(x)+g(x)=";
    else
        cout<<"F(x)=f(x)-g(x)=";
    list1.DisplayList();
    return 0;
}


