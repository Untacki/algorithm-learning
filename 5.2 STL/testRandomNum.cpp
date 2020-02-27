#include<ctime>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
//#include<bits/stdc++.h>
using namespace std;
void randCreate(vector<int>& v,int num)
{
    srand(time(NULL));
    while(num--)
    {
        v.push_back(rand());
    }
}
void testSort(vector<int> v)
{
    sort(v.begin(),v.end());
    for(int i=0;i<v.size()-1;i++)
    {
        assert(v[i]<=v[i+1]);
    }
}
int main()
{
    vector<int> v;
    randCreate(v,1000000);
    testSort(v);
    return 0;
}