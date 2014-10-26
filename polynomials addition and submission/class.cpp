//
//  class.cpp
//  c++
//
//  Created by sherry on 14-9-18.
//  Copyright (c) 2014年 sherry. All rights reserved.
//

#include "class.h"
List::~List(void) {
    Node* currNode = head, *nextNode = NULL;
    while (currNode != NULL)
    {
        nextNode = currNode->next;
        // destroy the current node
        delete currNode;
        currNode = nextNode;
    }
}

Node* List::InsertNode(double coe,int p)
{
	int currIndex	= 1;
    Node* newNode	= new Node;
    newNode->coefficient=coe;
    newNode->pow=p;
 
    Node* currNode	= head;
    while (currNode)
    {
        
        if(currNode->pow<p)
        {
            break;
        }
        else if(currNode->pow==p)
        {
            currNode->coefficient+=coe;
            delete newNode;
            return currNode;
        }
      
        currIndex++;
        if(currNode->next)
        {
            currNode=currNode->next;
         
        }
        else
        {
            newNode->before=currNode;
            currNode->next=newNode;
            return newNode;
            break;
        }
	}
    if (currIndex==1&&currNode==NULL)
    {
		newNode->next= head;
		head = newNode;
        return newNode;
    }

	if (currIndex == 1)
    {
        currNode->before=newNode;
		newNode->next= head;
		head = newNode;
    }
	else
    {
        newNode->next=currNode;
        newNode->before=currNode->before;
        currNode=currNode->before;
        currNode->next=newNode;
	}
	return newNode;
}
int List::DeleteNode(double x)
{
	Node* prevNode	= NULL;
	Node* currNode	= head;
	int currIndex	= 1;
	while (currNode && currNode->coefficient!=0)
    {
		prevNode = currNode;
		currNode = currNode->next;
		currIndex++;
	}
	if (currNode)
    {
		if (prevNode)
        {
			prevNode->next	= currNode->next;
			delete currNode;
		}
		else
        {
			head =	currNode->next;
			delete currNode;
		}
		return currIndex;
	}
	return 0;
}
void List::DisplayList(void)
{
    int num = 0;
    Node* currNode =head;
    Node* nextNode=currNode->next;
    if(currNode->coefficient<0)
    {
        if(currNode->pow<0)
            cout << currNode->coefficient<<"x^"<<"("<<currNode->pow<<")";
        else if(currNode->pow>0&&currNode->pow!=1)
            cout << currNode->coefficient<<"x^"<<currNode->pow;
        else if(currNode->pow==1)
            cout << currNode->coefficient<<"x";
        else
            cout<<currNode->coefficient;
    }
    else if(currNode->coefficient>0&&currNode->coefficient!=1)
    {
        if(currNode->pow<0)
            cout << currNode->coefficient<<"x^"<<"("<<currNode->pow<<")";
        else if(currNode->pow>0&&currNode->pow!=1)
            cout << currNode->coefficient<<"x^"<<currNode->pow;
        else if(currNode->pow==1)
            cout << currNode->coefficient<<"x";
        else
            cout<<currNode->coefficient;
        }
    else if(currNode->coefficient==1)
    {
        if(currNode->pow<0)
            cout << "x^"<<"("<<currNode->pow<<")";
        else if(currNode->pow>0&&currNode->pow!=1)
            cout << "x^"<<currNode->pow;
        else if(currNode->pow==1)
            cout << "x";
        else
            cout<<currNode->coefficient;
    }
    while(currNode->next)
    {
        currNode = currNode->next;
        nextNode = currNode->next;
        num++;
        if(currNode->coefficient<0)
        {
            if(currNode->pow<0)
                cout << currNode->coefficient<<"x^"<<"("<<currNode->pow<<")";
            else if(currNode->pow>0&&currNode->pow!=1)
                cout << currNode->coefficient<<"x^"<<currNode->pow;
            else if(currNode->pow==1)
                cout << currNode->coefficient<<"x";
            else
                cout<<currNode->coefficient;
        }
        else if(currNode->coefficient>0&&currNode->coefficient!=1)
        {
            if(currNode->pow<0)
                cout << "+"<<currNode->coefficient<<"x^"<<"("<<currNode->pow<<")";
            else if(currNode->pow>0&&currNode->pow!=1)
                cout << "+"<<currNode->coefficient<<"x^"<<currNode->pow;
            else if(currNode->pow==1)
                cout << "+"<<currNode->coefficient<<"x";
            else
                cout<<"+"<<currNode->coefficient;
        }
        else if(currNode->coefficient==1)
        {
            if(currNode->pow<0)
                cout << "+"<<"x^"<<"("<<currNode->pow<<")";
            else if(currNode->pow>0&&currNode->pow!=1)
                cout << "+"<<"x^"<<currNode->pow;
            else if(currNode->pow==1)
                cout << "+"<<"x";
            else
                cout<<"+"<<currNode->coefficient;
        }
    }
}
void List::AddList(List list1)
{
    int flag=0;
    Node* kurrNode=list1.head;
    Node* CurrNode=head;
    int kurrIndex=0;
    for(kurrIndex=0;kurrNode&&CurrNode->next;kurrIndex++)
    {
        flag=0;
        if(kurrNode->pow==CurrNode->pow)
        {
           CurrNode->coefficient+=kurrNode->coefficient;
           CurrNode=CurrNode->next;
           flag=1;
        }
        else if(kurrNode->pow>CurrNode->pow)
        {
           InsertNode(kurrNode->coefficient, kurrNode->pow);
           flag=1;
        }
        else
        {
            if(CurrNode->next)
                CurrNode=CurrNode->next;
            else
                InsertNode(kurrNode->coefficient,kurrNode->pow);
        
        }
        if(flag==1)
        {
            kurrNode=kurrNode->next;
            kurrIndex++;
        }
    }
    
    while(kurrNode)
    {
        if(kurrNode->pow==CurrNode->pow)
        {
            CurrNode->coefficient+=kurrNode->coefficient;
            CurrNode=CurrNode->next;
            flag=1;
        }
        else if(kurrNode->pow>CurrNode->pow)
        {
            InsertNode(kurrNode->coefficient, kurrNode->pow);
            flag=1;
        }
        else
        {
            CurrNode->next=kurrNode;
        }
        if(flag==1)
        {
            kurrNode=kurrNode->next;
            kurrIndex++;
        }
    }
    
}
void List::minusList(List list2)
{
    int flag=0;
    Node* kurrNode=list2.head;
    Node* CurrNode=head;
    int kurrIndex=0;
    for(kurrIndex=0;kurrNode&&CurrNode->next;kurrIndex++)
    {
        flag=0;
        if(kurrNode->pow==CurrNode->pow)
        {
            CurrNode->coefficient-=kurrNode->coefficient;
            CurrNode=CurrNode->next;
            flag=1;
        }
        else if(kurrNode->pow>CurrNode->pow)
        {
            InsertNode(kurrNode->coefficient, kurrNode->pow);
            flag=1;
        }
        else
        {
            if(CurrNode->next)
                CurrNode=CurrNode->next;
            else
                InsertNode(kurrNode->coefficient,kurrNode->pow);
            
        }
        if(flag==1)
        {
            kurrNode=kurrNode->next;
            kurrIndex++;
        }
    }
    
    while(kurrNode)
    {
        if(kurrNode->pow==CurrNode->pow)
        {
            CurrNode->coefficient-=kurrNode->coefficient;
            CurrNode=CurrNode->next;
            flag=1;
        }
        else if(kurrNode->pow>CurrNode->pow)
        {
            InsertNode(kurrNode->coefficient, kurrNode->pow);
            flag=1;
        }
        else
        {
            CurrNode->next=kurrNode;
        }
        if(flag==1)
        {
            kurrNode=kurrNode->next;
            kurrIndex++;
        }
    }
    

}
