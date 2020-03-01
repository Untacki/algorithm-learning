#include<string>
#include<iostream>
using namespace std;
void str(string a)
{
    //a[0]+=1;
    cout<<a.size();
    //return a;
}
int main()
{
    string a="haha";
    cout<<a<<endl;
    str(a);
    //cout<<a<<endl;
    return 0;
}