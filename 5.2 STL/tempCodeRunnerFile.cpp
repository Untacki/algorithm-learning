#include<iostream>
#include<algorithm>
#include<stack>
#include<map>
#include<vector>
#include<set>
using namespace std;
typedef set<string> Set;
#define all(x) x.begin(),x.end()
#define ins(x) inserter(x,x.begin())
map<Set,int> m;
vector<Set> v;
int getID(Set id) //给新出现的set分配ID
{
    if(m.count(id)==0) //新出现的set
    {
       v.push_back(id);
       m[id]=v.size()-1; 
    }
    return  m[id];
}
int main()
{
    stack<set<string>> s;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        string input;
        for(int i=0;i<n;i++)
        {
            cin>>input;
            if (input[0]=='P')
            {
                s.push(v[getID(Set())]);
            }
            else
            {
                if(input[0]=='D')
                {
                    s.push(v[getID(s.top())]);
                }
                else
                {
                    Set s1=s.top();
                    s.pop();
                    Set s2=s.top();
                    s.pop();
                    Set res;
                    if(input[0]=='U')
                    {
                        set_union(all(s1),all(s2),ins(res)); //取并集
                        //s.push(v[getID(res)]);
                    }
                    if(input[0]=='I')
                    {
                        set_intersection(all(s1),all(s2),ins(res));
                    }
                    if(input[0]=='A')
                    {
                        res=s2;
                        s2.insert(s1.begin(),s1.end());
                    }
                    s.push(v[getID(res)]);
                }
            }
        printf("%d\n",s.top().size());
        }
        printf("***\n");
    }
    return 0;
}