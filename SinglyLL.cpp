#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;

struct node{
int data;
struct node* link;
};
struct node* getnew(int d)
{
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->link=NULL;
    temp->data = d;
    return temp;
};
struct node * add(struct node * head, int data)
{
    struct node * newnode = getnew(data);
    if(!newnode)
    {
        cout<<"Memory Error\n";
        return NULL;
    }
    if(head==NULL)
        return newnode;
    newnode->link = head;
    head = newnode;
    return head;

};
void addSorted(struct node ** head, int data)
{
    struct node* newnode =getnew(data);
    if(!newnode)
    {
        cout<<"Memory Error\n";
       return;
    }
    if(*head ==NULL)
    {
        newnode->link = *head;
     *head= newnode;
    }
    else if((*head)->data>=data)
        {
            newnode->link = *head;
            *head = newnode;
        }
    else{
            struct node * temp = *head;
            while(temp->link!=NULL&&temp->link->data<data)
                temp=temp->link;

            newnode->link = temp->link;
            temp->link= newnode;

        }

};
void print(struct node* head)
{
    if(head==NULL)
    {
    cout<<"Empty\n";
    return;
    }
    cout<<"\n\nPrinting Linked List...\n";
    struct node* temp = head;
    while(temp!=NULL)
    {
        //getchar();
        cout<<temp->data<<"-->";
        temp=temp->link;
    }
    cout<<endl;
}
void delete_node(struct node ** head){
    struct node * temp = *head;
    struct node * aux;
while(temp!=NULL)
    {
        aux = temp->link;
        free(temp);
        temp = aux;

}
*head = NULL;
}
void nth_element_end(struct node**head, int pos){
struct node * p1,*p2;
p1=p2=*head;
for(int i=0;p2!=NULL&&i<pos;++i)
    p2=p2->link;

while(p2!=NULL){
    p2=p2->link;
    p1=p1->link;
}
cout<<pos<<"th element from the end is: "<<p1->data<<endl;
}
void reverse_iterative(struct node**head)
{
    struct node*prev, *cur, *next;
    prev= NULL;
    cur= *head;
    while(cur!=NULL)
    {
        next = cur->link;
        cur->link= prev;
        prev= cur;
        cur=next;
    }
    *head = prev;
}
void reverse_rec( struct node**head_ref)
{
    struct node* first ;
    struct node* rest;
 if(*head_ref==NULL)
    return;
first = *head_ref;
rest=first->link;
if(rest==NULL)
    return;
reverse_rec(&rest);

first->link->link =first;
first->link=NULL;

*head_ref=rest;

};
struct node * reverse_k( struct node * cur, int k){
    if(cur==NULL)
        return NULL;
    struct node * temp = cur;
    struct node* next;
    struct node*prev = NULL;

for(int i=0;i<k;++i){

next = cur->link;
    cur->link = prev;
    prev = cur;
    cur= next;
    if(cur==NULL)
        break;
}

temp->link = reverse_k(cur,k );

return prev;
};
void palindrome(struct node* head)
{
    struct node* slow_ptr = head;
    struct node * fast_ptr= head;

    while(fast_ptr->link!=NULL&&fast_ptr->link->link!=NULL)
    {
        fast_ptr=fast_ptr->link->link;
        slow_ptr=slow_ptr->link;
    }
    struct node* first= head;
    struct node * second = slow_ptr->link;
    cout<<first->data<<second->data;
    reverse_iterative(&second);
    print(second);

}

int main()
{

    struct node * head = (struct node*)malloc(sizeof(struct node));
    head = NULL;

    addSorted(&head, 5);
    //print(head);
    addSorted(&head, 1);
    addSorted(&head, 4);
    addSorted(&head, 3);
    addSorted(&head, 2);
    addSorted(&head,7);
    print(head);
    reverse_rec(&head);
    print(head);
    nth_element_end(&head, 4);

    delete_node(&head);
    return 0;
}

