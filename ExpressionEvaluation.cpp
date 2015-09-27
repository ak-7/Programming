#include<stdio.h>
#include<stack>
#include<iostream>
#include<cmath>
using namespace std;
bool isOperator(char c)
{
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
        return true;
        break;
    default: return false;
    }
}
int res(int a, int b, char c)
{
       switch(c){
        case '+':
            return (a + b);
        break;
        case '-':
            return (b - a);
        break;
        case '*':
            return (a * b);
        break;
        case '/': return (b / a);


    default: return 0;
    }
}
bool isGreaterPrec(char a, char b)
{
    if(a=='*'||a=='/')
        return true;
    if(b=='+'||b=='-')
        return true;
    return false;
}
void evaluate(char a[])
{
    stack<int> operand;
    stack<char> optr;
    for(int i=0;a[i]!='\0';++i)
    {
        if(!isOperator(a[i]))
        {
            operand.push(a[i]-'0');
            cout<<operand.top()<<endl;
        }
        else{
            if(!optr.empty())
            {
                cout<<a[i]<<" "<<optr.top()<<endl;
            while(!optr.empty()&&(isGreaterPrec(optr.top(),a[i])))
            {
                char c =optr.top();
                optr.pop();
                int v1 = operand.top();
                operand.pop();
                int v2=operand.top();
                operand.pop();

                cout<<v1<<c<<v2<<endl;
                int r = res(v1,v2,c);
                cout<<"Res: "<<r<<endl;
                operand.push(r);
            }
            }
            optr.push(a[i]);
        }
    }
    while(!optr.empty())
            {
                char c =optr.top();
                optr.pop();
                int v1 = operand.top();
                operand.pop();
                int v2=operand.top();
                operand.pop();
                cout<<v1<<c<<v2<<endl;

                int r = res(v1,v2,c);
                cout<<"Res: "<<r<<endl;
                operand.push(r);
            }
    cout<<operand.top();
}
int main()
{
    char a[]="1+2*3-4";
    evaluate(a);
    return 0;
}
