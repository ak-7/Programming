#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;

struct node{
int data;
struct node* prev;
struct node* next;
};
struct node* getnew(int d)
{
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    if(!temp)
    {
        cout<<"Memory Error";
        return NULL;
    }
    temp->prev=temp;
    temp->next=temp;
    temp->data = d;
    return temp;
};
struct bintree{
int data;
struct bintree*left, *right;
};
struct bintree* gettreenode(int data)
{
    struct bintree* node = (struct bintree*)malloc(sizeof(struct bintree));
    node->data = data;
    node->left=NULL;
    node->right=NULL;
    return node;
};
void print_inorder(struct bintree* root)
{
    if(root==NULL)
        return;
    print_inorder(root->left);
    cout<<root->data;
    print_inorder(root->right);
}
struct bintree* add_node(struct bintree* root, int data)
{
    if(root==NULL)
       {
           root =gettreenode(data);
       }
       else{

    if(root->data>data)
        root->left = add_node(root->left, data);
    else if(root->data<=data)
        root->right=add_node(root->right, data);
       }
   return root;

}
void convertBstToCircularDLL(struct bintree* root, struct bintree* &head, struct bintree* &tail)
{
    struct bintree* headleft, *headright,*tailleft, *tailright;
    headleft=NULL;
    headright=NULL;
    tailleft=NULL;
    tailright=NULL;
    if(root==NULL)
    {
        head=tail=NULL;
        return;
    }
    convertBstToCircularDLL(root->left, headleft, tailleft);
    convertBstToCircularDLL(root->right, headright, tailright);

    if(headright==NULL)
        tail=root;
    else
    {
        root->right=headright;
        tail=tailright;
    }
    if(headleft==NULL)
        head= root;
    else
        {tailleft->right=root;
        head = headleft;}
};
void print_ll(struct node* head)
{
    if(head==NULL)
    {
    cout<<"Empty\n";
    return;
    }
    cout<<"\n\nPrinting Linked List...\n";
    struct node* temp = head;
    while(temp!=head)
    {
        //getchar();
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
       struct bintree* root=NULL;
       struct bintree* head, *tail=NULL;
    root = add_node(root, 5);
    root = add_node(root, 4);
    root = add_node(root, 6);
    root = add_node(root, 1);
    root = add_node(root, 8);
    root = add_node(root,7);
    print_inorder(root);
    convertBstToCircularDLL(root,head, tail);
    tail->right=head;
    head->left=tail;
    struct bintree* temp=head;
    cout<<endl<<temp->data;
    temp=temp->right;
    while(temp!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    cout<<tail->right->data;
    return 0;
}
