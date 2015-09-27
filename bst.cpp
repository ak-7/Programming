#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<limits.h>
using namespace std;
struct bintree{
int data;
struct bintree*left, *right;
};
struct bintree* getnode(int data)
{
    struct bintree* node = (struct bintree*)malloc(sizeof(struct bintree));
    node->data = data;
    node->left=NULL;
    node->right=NULL;
    return node;
};
struct bintree* add_node(struct bintree* root, int data)
{
    if(root==NULL)
       {
           root =getnode(data);

       }
       else{

    if(root->data>data)
        root->left = add_node(root->left, data);
    else if(root->data<=data)
        root->right=add_node(root->right, data);
       }
   return root;

}
struct bintree* findMax(struct bintree * root)
{

    if(root==NULL)
        return NULL;

    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
};
struct bintree* delete_node(struct bintree * root, int data)
{
    cout<<endl<<root->data;
    struct bintree* temp;
    if(root==NULL)
        cout<<"Element not found\n";
    if(root->data>data)
        root->left = delete_node(root->left, data);
    else if(root->data<data)
        root->right = delete_node(root->right, data);
    else
    {
        if(root->left&&root->right)
        {
            temp = findMax(root->left);
            cout<<"Deleting... "<<temp->data;
            root->data = temp->data;
            root->left = delete_node(root->left ,temp->data);
        }
        else {
                cout<<"\nOne child element: "<<root->data<<endl;
                temp = root;
        if(root->left==NULL)
            root=root->right;

        else if(root->right ==NULL)
            root= root->left;
        free(temp);
        }
    }
return root;



};
struct bintree* lca(struct bintree* root, int n1, int n2)
{
    while(1)
    {
        //cout<<root->data<<endl;
        if((n1<=root->data&&root->data<=n2)||(n2<=root->data&&root->data<=n1))
            return root;
        if(root->data<n1)
            root = root->right;
        else
            root=root->left;

    }
}
bool isBst(struct bintree*root, int min_r, int max_l)
{
    if(root==NULL)
        return true;
    if(root->data<min_r&&root->data>max_l)
    {
        //cout<<max_l<<" "<<root->data<<" "<<min_r<<endl;
        if(isBst(root->left,root->data,max_l)&&isBst(root->right,min_r,root->data))
            return true;
    }
    return false;
}
struct bintree* kthsmallest(struct bintree* root, int k, int* cnt)
{
    if(root==NULL)
        return root;

    struct bintree* left=kthsmallest(root->left,k,cnt);
    if(left)
        return left;
    if(++*cnt==k)
        return root;
    return kthsmallest(root->right,k,cnt);
};
void print_inorder(struct bintree* root)
{
    if(root==NULL)
        return;
    print_inorder(root->left);
    cout<<root->data;
    print_inorder(root->right);
}
int main()
{
    struct bintree* root=NULL;
    root = add_node(root, 5);
    root = add_node(root, 4);
    root = add_node(root, 6);
    root = add_node(root, 1);
    root = add_node(root, 8);
    root = add_node(root,7);
root = add_node(root, 3);
    print_inorder(root);
    delete_node(root, 4);
    print_inorder(root);
    cout<<"\nLCA "<<lca(root, 7,6)->data<<endl;
    cout<<"\n Is Bst?: "<< (isBst(root,INT_MAX,INT_MIN));
    int cnt =0;
    cout<<"\n\n3rd smallest in Bst:\n"<<kthsmallest(root,8,&cnt)->data;
    return 0;
}
