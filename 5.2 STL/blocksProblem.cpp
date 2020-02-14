#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxNum=30;
int numOfBlock=0;
vector<int> block[maxNum];
void findPos(int find,int& p1,int& p2) //找到目标数字所在的堆和高度
{
    for(p1=0;p1<numOfBlock;p1++)
    {
        for(p2=0;p2<block[p1].size();p2++)
        {
            if(block[p1][p2]==find)
                return;
        }
    }
}
void back(int p1,int p2) //将上面的block归位
{
    for(int i=block[p1].size()-1;i>p2;i--)
    {
        int n=block[p1].back();
        block[n].push_back(n);
        block[p1].pop_back();
    }
}
void move(int p1,int h1,int p2,int h2) //将a和上面的block堆在b和上面的block堆上面
{
    for(int i=h1;i<block[p1].size();i++)
    {
        block[p2].push_back(block[p1][i]);
    }
    block[p1].resize(h1);
}
void print() //打印出最终结果
{
    for(int i=0;i<numOfBlock;i++)
    {
        printf("%d:",i);
        for(int j=0;j<block[i].size();j++)
        {
            printf(" %d",block[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int a,b;
    string s1,s2;
    scanf("%d",&numOfBlock);
    for(int i=0;i<numOfBlock;i++)
    {
        block[i].push_back(i);
    }
    while(cin>>s1>>a>>s2>>b)
    {
        int pa,ha,pb,hb; //分别为a和b所在的堆数和高度
        findPos(a,pa,ha);
        findPos(b,pb,hb);
        if (a==b||pa==pb) //如果a和b在同一堆或者a和b相同的话，那么跳过
        {
            continue;
        }
        if(s2=="onto")
        {
            back(pb,hb);
        }
        if(s1=="move")
        {
            back(pa,ha);
        }
        move(pa,ha,pb,hb);
    }
    print();
    return 0;
}