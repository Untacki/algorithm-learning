#include<iostream>
#include<queue>
#include<map>
using namespace std;
const int maxTeam=1010;
map<int,int> m;
int main()
{
    int teams=0;
    int j=1;
    while(scanf("%d",&teams)&&teams!=0)//队伍数量
    {
        for(int i=0;i<teams;i++) //读入每个队伍的项的值
        {
           int teamNum=0;
           scanf("%d",&teamNum);//队伍所包含项数量
           while(teamNum--)
           {
               int temp=0;
               scanf("%d",&temp);
               m[temp]=i;
           }
        }
        string temp1;
        queue<int> total,part[maxTeam];
        printf("Scenario #%d\n",j++);
        while(cin>>temp1&&temp1[0]!='S')
        {
            if(temp1[0]=='E')
            {
                int temp2=0;
                cin>>temp2;
                if(part[m[temp2]].empty())
                {
                    total.push(m[temp2]);
                }
                part[m[temp2]].push(temp2);
            }
            if(temp1[0]=='D')
            {
                cout<<part[total.front()].front()<<endl;
                part[total.front()].pop();
                if(part[total.front()].empty())
                {
                    total.pop();
                }
            }
        }
    printf("\n");
    }
    return 0;
}