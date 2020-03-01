#include<iostream>
#include<cstdio>
#include<set>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    string s1,s2;
    while(cin>>s1)
    {
        cin>>s2;
        int a1[26] = { 0 };
        int a2[26] = { 0 };
        int is_ac=1;
        for(auto i:s1)
        {
            a1[i-65]+=1;
        }
        for(auto i:s2)
        {
            a2[i-65]+=1;
        }
        if(sizeof(a1)!=sizeof(a2))
        {
            is_ac=0;
        }
        else
        {
            sort(a1,a1+26);
            sort(a2,a2+26);
            for(int i=0;i<(sizeof(a1)/sizeof(int));i++)
            {
                if(a1[i]!=a2[i])
                {
                    is_ac=0;
                }
            }
        }
        if(is_ac)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}