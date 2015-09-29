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
    if(!temp)
    {
        cout<<"Memory Error";
        return NULL;
    }
    temp->link=temp;
    temp->data = d;
    return temp;
};
void addCircular(struct node**head, int data){
struct node *  newnode = getnew(data);
if(*head==NULL)
{
    newnode->link = newnode;
    *head = newnode;

}
else{
    struct node* cur = *head;
    struct node*temp;
    do{
        temp=cur;
        cur = cur->link;
    }while(cur!=*head);

    newnode->link = *head;
    temp->link = newnode;

}
}
void print(struct node**head)
{
    int count=0;
    if((*head)!=NULL){
        struct node*cur = *head;
        do{
            cout<<cur->data<<" ";
            cur=cur->link;
            count++;
        }while(cur!=*head);
    }
    else
        cout<<"Empty";
    cout<<"Total No of nodes: "<<count<<endl;
}
void print_ll(struct node* head)
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
void split(struct node *head, struct node**first, struct node**second)
{
    struct node* slow_ptr = head;
    struct node * fast_ptr= head;
    struct node * fast_ptr_prev;


    while(fast_ptr->link!=head&&fast_ptr->link->link!=head)
    {
        fast_ptr_prev = fast_ptr;
        fast_ptr=fast_ptr->link->link;
        slow_ptr=slow_ptr->link;

    }
fast_ptr=fast_ptr->link;
    //Split the list into two
    *first = head;
    *second = slow_ptr->link;
    slow_ptr->link = NULL;

    fast_ptr->link = NULL;
}
struct node* last_remaining(struct node*head, int m)
{
    if(head->link==head)
        return head;
        print(&head);
    struct node* cur= head;
    struct node*prev;
    for(int i=0;i<m;++i)
    {
        prev=cur;
        cur=cur->link;
        if(cur->link==cur)
        {
            cout<<"One element left\n";
            return head;
        }
    }
    prev->link = cur->link;
    cout<<"Deleting: "<<cur->data<<endl;
    free(cur);
    last_remaining(prev->link, m);
};
void add( struct node**head, struct node*first, struct node*second, int*carry)
{
    int sum =0;
    struct node* res=(struct node*)malloc(sizeof(struct node));
    if(first==NULL)
        return;
cout<<first->data;
getchar();
    add(head, first->link, second->link, carry);
    sum = first->data + second->data +(*carry);
    cout<<"Sum is: "<<sum<<"   \n";
    *carry = sum/10;
    sum=sum%10;
    res->data = sum;

    res->link= *head;
    *head= res;

    return ;
}
int main()
{
    struct node * head = (struct node *)malloc(sizeof(struct node));
    struct node * first = (struct node *)malloc(sizeof(struct node));
    struct node * second = (struct node *)malloc(sizeof(struct node));
    struct node * result = (struct node *)malloc(sizeof(struct node));
    result=NULL;
    int sum=0;
    int carry=0;
    head=NULL;
    cout<<"Begin\n";
    addCircular(&head, 1);
    addCircular(&head, 2);
    addCircular(&head, 3);
    addCircular(&head, 4);
    addCircular(&head, 5);
    addCircular(&head, 6);
cout<<"Printing...\n";
    print(&head);
    split(head, &first, &second);
    print_ll(first);
    print_ll(second);
    //struct node* last = last_remaining(head, 2);
    //cout<<"Last one remaining: "<<last->data<<endl;
    add( &result, first, second, &carry);
    print_ll(result);
    return 0;
}
