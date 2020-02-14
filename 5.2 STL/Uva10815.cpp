// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<set>
// #include<sstream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,line;
    set<string> res;
    while(cin>>line)
    {        
        for(int i=0;i<line.size();i++)
        {
            if(isalpha(line[i]))
            {
                line[i]=tolower(line[i]); 
            }
            else
            {
                line[i]=' ';
            }
        }
        stringstream temp;
        temp<<line;
        while(temp>>a)
        {
            res.insert(a);
        }
    }
    // for(auto it = res.begin();it!=res.end();it++)
    // {
    //     printf("%s\n",(*it).c_str());
    // }
    for(auto be:res)
    {
        printf("%s\n",be.c_str());
    }
    //printf("666 Congratulations!\n");
    return 0;
}