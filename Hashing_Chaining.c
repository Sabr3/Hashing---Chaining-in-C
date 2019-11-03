//
// Created by listi on 01/11/2019.
//

#include <stdio.h>
#include<stdlib.h>

struct Chaining_Node
{
    int data;
    struct Chaining_Node *next;
};

void SortedInsert(struct Chaining_Node **H,int x)
{
    struct Chaining_Node *t,*q=NULL,*p=*H;

    t=(struct Chaining_Node*)malloc(sizeof(struct Chaining_Node));
    t->data=x;
    t->next=NULL;

    if(*H==NULL)
        *H=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==*H)
        {
            t->next=*H;
            *H=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }

}
struct Chaining_Node *Chain_Search(struct Chaining_Node *p,int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;

}

int Chaining_hash(int key)
{
    return key%10;
}
void Chain_Insert(struct Chaining_Node *H[],int key)
{
    int index=Chaining_hash(key);
    SortedInsert(&H[index],key);
}


