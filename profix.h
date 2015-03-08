//
//  profix.h
//  c++
//
//  Created by sherry on 14-10-31.
//  Copyright (c) 2014年 sherry. All rights reserved.
//

#ifndef __c____profix__
#define __c____profix__

#include <iostream>
using namespace std;

class stack
{
public:
    stack(int size=10);
    ~stack();
    bool IsFull();
    bool IsEmpty();
    double TopNumber();
    char TopSymbol();
    void PushNumber(double x);
    void PushSymbol(char x,stack NumberStack);
    double PopNumber();
    char PopSymbol();
    void DisplayNumberStack();
    void DisplaySymbolStack();
    void Calculate(char x,stack y);
    
private:
    int MaxTop;
    int Top;
    double* values;
    char* symbol;
    
};

#endif /* defined(__c____profix__) */
