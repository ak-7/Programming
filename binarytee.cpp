#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

vector<int> v;
struct bintree{
int data;
struct bintree* left, *right;
};
struct bintree* newnode(int data){
struct bintree* node = new struct bintree;
node->data = data;
node->left = NULL;
node->right = NULL;
return node;
};
void preorder(struct bintree* root)
{
    if(root==NULL)
        return ;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void iterative_preorder(struct bintree* root)
{
    stack<struct bintree*> s;
    while(1){
        while(root)
        {
            cout<<root->data<<" ";
            s.push(root);
            root=root->left;
        }

        if(s.empty())
            break;

        root=s.top();
        s.pop();
        root=root->right;
    }

}
void iterative_inorder(struct bintree * root){
    stack<struct bintree*> s;
while(1)
{
    while(root)
    {
        s.push(root);
        root=root->left;

    }
    if(s.empty())
        break;
    root=s.top();
    s.pop();
    cout<<root->data<<" ";
    root=root->right;
}
}
void iterative_postorder(struct bintree* root)
{
    stack<struct bintree*>s;
    cout<<"\n\nPostorder....\n\n";
    while(1){
        if(root)
        {
            s.push(root);
            root=root->left;
        }

        else{
            if(s.empty())
                return ;
            else if(s.top()->right==NULL)
            {
                root=s.top();
                s.pop();
                cout<<root->data<<" ";

                if(root==s.top()->right)
                {
                    cout<<s.top()->data<<" ";
                    s.pop();
                }
            }

        if(!s.empty())
            {
                getchar();
                root=s.top()->right;}
        else
            root=NULL;
        }

    }
}
void levelorder(struct bintree* root)
{
    queue<struct bintree*>q;
    q.push(root);
    cout<<"\n\nLevel Order....\n\n";
    while(1)
    {
        if(!q.empty())
        {
            root=q.front();
            q.pop();
            cout<<root->data<<" ";
            if(root->left)
            q.push(root->left);
            if(root->right)
                q.push(root->right);

        }
        else
            break;
    }
}
int max(int a, int b)
{
    return a>b?a:b;
}
int max(int a,int b, int c)
{
    int d= max(a,b);
    return max(d,c);
}
int heightofTree(struct bintree* root)
{

    if(root==NULL)
        return 0;
int lefth=heightofTree(root->left);
int righth=heightofTree(root->right);
    int hght = max(lefth, righth)+1;
    return (hght);
}
int deepestNode(struct bintree* root)
{
    queue<struct bintree*>q;
    q.push(root);

    int max_level =0;
    while(!q.empty())
    {
        root = q.front();
        q.pop();

        if(root->left&&root->right)
        {
            max_level++;

        }
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);

    }
   return max_level;
}
int diameter(struct bintree* root)
{
    if(root==NULL)
        return 0;
    return max(diameter(root->left),diameter(root->right),heightofTree(root->left)+heightofTree(root->right) +1);
}
void printpath(int arr[], int len)
{
    for(int i=0;i<len;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void root_to_leaf_path(struct bintree*root, int arr[], int pathlen)
{
    if(root==NULL)
        return;
    else{
        arr[pathlen] = root->data;
        pathlen++;
        if(root->left==NULL&&root->right==NULL)
        printpath(arr,pathlen);

        root_to_leaf_path(root->left, arr, pathlen);
        root_to_leaf_path(root->right, arr, pathlen);
    }
}
void roottoleaf(struct bintree* root)
{
    int pathlen=0;
    int arr[10];
    root_to_leaf_path(root, arr,pathlen);
}
int ancestors(struct bintree* root, int data)
{
    if(root==NULL)
        return 0;
    if(root->data ==data)
        return 1;
    if(ancestors(root->left,data)||ancestors(root->right, data))
    cout<<root->data<<" ";
}
struct bintree* lca(struct bintree*root, int n1, int n2)
{
    struct bintree* left, *right;
    if(root==NULL)
        return root;
    if(root->data==n1||root->data==n2)
    return root;
    left = lca(root->left,n1,n2);
    right = lca(root->right, n1, n2);
    if(left&&right)
        return root;
    return left?left:right;
}
int vertexcover( struct bintree* root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL&&root->right==NULL)
        return 0;

    int incl = 1 + vertexcover(root->left) + vertexcover(root->right);
    int excl =0;
    if(root->left)
        excl+= 1+ vertexcover(root->left->left)+vertexcover(root->left->right);
    if(root->right)
        excl+=1+vertexcover(root->right->left) + vertexcover(root->right->right);

    if(incl<=excl)
    {
        cout<<root->data;
        v.push_back(root->data);
        return incl;
    }
    else
        return excl;
}
int main()
{
    struct bintree* root = newnode(1);

    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left=newnode(9);
    root->left->right = newnode(10);
    root->right->right = newnode(12);
    root->left->left->left=newnode(13);
    root->right->right->left =newnode(30);
    iterative_preorder(root);
    cout<<"\n";
    iterative_inorder(root);
    //iterative_postorder(root);
    levelorder(root);
    cout<<"\n\nHeight of tree: "<<heightofTree(root)<<endl;
    cout<<"\n\nDeepest Node: "<<deepestNode(root)<<endl;
    cout<<"\n\nDiameter: "<<diameter(root)<<endl;
    cout<<"\n\nRoot to leaf paths: ";
    roottoleaf(root);
    cout<<"\nAncestors: \n";
    ancestors(root, 13);
    cout<<"\nLeast Common Ancestor: \n";
    struct bintree* anc = lca(root, 9,13);
    cout<<anc->data;
cout<<"\nPrinting Paths on way:";
    cout<<"\n\nVertex Cover: "<<vertexcover(root)<<endl;
    for(vector<int>::iterator it=v.begin();it!=v.end();++it)
        cout<<*it<<" ";
    return 0;
}
