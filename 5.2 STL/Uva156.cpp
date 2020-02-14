#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;
vector<string> temp; //用来保存原始结果
map<string,int> result; //用来存入符合要求的结果与其计数
string standard(const string& a) //标准化(转成小写字母并且按照字母表顺序进行排序)
{
    string ans=a;
    for(int i=0;i<ans.size();i++)
    {
        ans[i]=tolower(ans[i]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    string s;
    while(cin>>s&&s!="#")
    {
        temp.push_back(s); //存入备选结果
        // if(!result.count(standard(s))) //如果单词未在map中出现过，那么次数初始化，否则次数加1
        // {
        //     result.insert(make_pair(standard(s),0));
        // }
        // else
        // {
            result[standard(s)]++;
       // }

        //temp.push_back(standard(s)); //vector中存入标准化后的结果
    }
    sort(temp.begin(),temp.end());
    for(auto it=temp.begin();it!=temp.end();it++)
    {         
        if(result[standard(*it)]==1)
        {
            printf("%s\n",(*it).c_str());
        }
    }
    return 0;
}