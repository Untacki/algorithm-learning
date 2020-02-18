#include<queue>
#include<iostream>
#include<set>
//#include<vector>
using namespace std;
typedef long long ll;
//const ll maxN=0x3f3f3f3f;
int main()
{
    int xNum[3]={2,3,5};
    //map<ll,int> m;
    set<ll> s;
    int num=1;
    priority_queue<ll,vector<ll>,greater<ll> > res;
    res.push(num);
    s.insert(num);
    while(num!=1500)
    {
        ll x = res.top();
        res.pop();
        for(int i=0;i<3;i++)
        {                                        
            ll temp=x*xNum[i];
            if(s.count(temp)==0)
            {
                res.push(temp); 
                s.insert(temp);
            }
        }
        num++;
    }
    printf("The 1500'th ugly number is %lld.\n",res.top());
    //cout<<res.top()<<endl;
    return 0;
}