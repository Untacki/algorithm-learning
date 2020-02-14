#include<iostream>
#include<algorithm>
//#include<cstdio>
const int maxNum=10010;
using namespace std;
int main()
{
    int round=1,N=0,Q=0,snOfMB[maxNum],fdMB[maxNum];
    while(scanf("%d%d",&N,&Q)==2&&N)
    {
        int i=0,j=0;
        while(N--)
        {
            scanf("%d",&snOfMB[i++]);
        }
        std::sort(snOfMB,snOfMB+i);
        while(Q--)
        {
            scanf("%d",&fdMB[j++]);
        }
        printf("CASE# %d:\n",round++);
        for(int k=0;k<j;k++)
        {
            if(snOfMB[lower_bound(snOfMB,snOfMB+i,fdMB[k])-snOfMB]==fdMB[k])
            {
                printf("%d found at %d\n",fdMB[k],lower_bound(snOfMB,snOfMB+i,fdMB[k])-snOfMB+1);
            }
            else
            {
                printf("%d not found\n",fdMB[k]);
            }
        }
    }
    return 0;
}