//
//  class.h
//  c++
//
//  Created by sherry on 14-9-18.
//  Copyright (c) 2014年 sherry. All rights reserved.
//


#include <iostream>
using namespace std;

class Node
{
public:
	double coefficient;	
    int pow;
	Node*	next;		// pointer to next
    Node*   before;
    
};
class List {
public:
	List(void) { head = NULL; }	// constructor
	~List(void);				// destructor
    
	bool IsEmpty() { return head == NULL; }
	Node* InsertNode(double coe,int p);
    
	//int FindNode(double x);
    
	int DeleteNode(double x);
	void DisplayList(void);
    void AddList(List);
    void minusList(List);
private:
	Node* head;
};