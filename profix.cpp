//
//  profix.cpp
//  c++
//
//  Created by sherry on 14-10-31.
//  Copyright (c) 2014年 sherry. All rights reserved.
//

#include "profix.h"
stack::stack(int size)
{
    MaxTop=size-1;
    Top=-1;
    values=new double [size];
    symbol=new char [size];
    values[0]=0;
}

stack::~stack()
{
    delete [] values;
    delete [] symbol;
}

bool stack::IsEmpty()
{
    return Top==-1;
}

bool stack::IsFull()
{
    return MaxTop==Top;
}

double stack::TopNumber()
{
    return values[Top];
}

char stack::TopSymbol()
{
    return symbol[Top];
}

void stack::PushNumber(double x)
{
    if(IsFull())
       cout<<"Error!The stack is full!";
    else
    {
        Top=Top+1;
        values[Top]=x;
    }
}

double stack::PopNumber()
{
    if(IsEmpty())
    {
        cout<<"Error!The stack is empty!";
        return 0;
    }
    else
        return values[Top--];
}
    
void stack::PushSymbol(char x,stack NumberStack)
{
    if(IsFull())
        cout<<"Error!The stack is full!";
    else if(IsEmpty()||TopSymbol()=='(')
        symbol[++Top]=x;
    else if(x==')')
    {
        while (TopSymbol()!='(')
        {
          Calculate(TopSymbol(), NumberStack);
        }
        PopSymbol();
    }
    else if(x=='=')
    {
        while(!IsEmpty())
        {
            Calculate(TopSymbol(), NumberStack);
        }
            
    }
    else
    {
        if((x=='*' || x=='/') && (symbol[Top]=='+' ||symbol[Top]=='-'))
        {
            Calculate(x,NumberStack);
        }
        else
        {
            Calculate(TopSymbol(), NumberStack);
            PopSymbol();
            Top=Top+1;
            symbol[Top]=x;
        }
    }

}
char stack::PopSymbol()
{
    if(IsEmpty())
    {
        cout<<"Error!The stack is empty!";
        return 0;
    }
    else
        return symbol[Top--];
}

void stack::DisplayNumberStack()
{
    for(Top;Top>-1;Top--)
        cout<<values[Top]<<endl;
}

void stack::DisplaySymbolStack()
{
    for(Top;Top>-1;Top--)
        cout<<symbol[Top];
}

void stack::Calculate(char x,stack y)
{
    double number1=y.TopNumber();
    y.PopNumber();
    double number2=y.TopNumber();
    y.PopNumber();
    if(x=='+')
        number1+=number2;
    else if(x=='-')
        number1-=number2;
    else if(x=='*')
        number1*=number2;
    else if(x=='/')
        number1/=number2;
    y.PushNumber(number1);
}
