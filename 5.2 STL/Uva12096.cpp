#include<iostream>
#include<algorithm>
#include<stack>
#include<map>
#include<vector>
#include<set>
#include<iterator>
using namespace std;
typedef set<int> Set;
#define all(x) x.begin(),x.end()
#define ins(x) inserter(x,x.begin())
map<Set, int> m;
vector<Set> v;
int getID(Set id) //给新出现的set分配ID 
{
	if (m.count(id) == 0) //新出现的set
	{
		v.push_back(id);
		m[id] = v.size() - 1;
	}
	return  m[id];
}
int main()
{
	stack<int> s;
	int n = 0;
	//scanf("%d",&n);
	cin >> n;
	while (n--)
	{
		int m = 0;
		// scanf("%d",&m);
		// getchar();
		cin >> m;
		string input;
		for (int i = 0; i < m; i++)
		{
			cin >> input;
			if (input[0] == 'P')
			{
				s.push(getID(Set()));
			}
			else
			{
				if (input[0] == 'D')
				{
					s.push(s.top());
				}
				else
				{
					Set s1 = v[s.top()];
					s.pop();
					Set s2 = v[s.top()];
					s.pop();
					Set res;
					if (input[0] == 'U')
					{
						set_union(all(s1), all(s2), ins(res)); //取并集
						//s.push(v[getID(res)]);
					}
					if (input[0] == 'I')
					{
						set_intersection(all(s1), all(s2), ins(res));
					}
					if (input[0] == 'A')
					{
						res = s2;
						res.insert(getID(s1));
					}
					s.push(getID(res));
				}
			}
			//printf("%d\n",v[s.top()].size())
			cout << v[s.top()].size() << endl;
		}
		printf("***\n");
	}
	return 0;
}