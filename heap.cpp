#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
using namespace std;

int main()
{
    int arr[]={5,6,1,3,4,7};
    vector<int> v(arr, arr+6);
    cout<<v.size();

    make_heap(v.begin(), v.end());
    cout<<"\nFront: "<<v.front();
    pop_heap(v.begin(), v.end());
    v.pop_back();
    cout<<"\nFront: "<<v.front()<<endl;
    sort(v.begin(), v.end());

    for(int i=0;i<v.size();++i)
        cout<<v[i];
    cout<<endl;

    vector<int>:: iterator low , up;
    low =lower_bound(v.begin(),v.end(),2);
    up = upper_bound(v.begin(),v.end(),7);
    cout<<*low<<*up;

    int a,*p;
    cout<<"----------\n";
    a=0x33;
    p = &a;
    cout<<typeid((char*)p).name();
    cout<<(char*)&a+1<<endl;
    cout<<&a<<endl;
    cout<<typeid((char*)(&a+1)-(char*)(&a)).name();
    cout<<5/2;
    //cout<<*a;
    return 0;


}
