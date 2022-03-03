#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 16; 

int n;
int st[N];   //记录每个位置的当前的状态：0表示还没考虑，1表示选它，2表示不选

void dfs(int u)
{
    if (u > n) 
    {
        for (int i = 1; i <= n; i++)
            if (st[i] == 1)
                printf(" %d", i);
        printf(" \n");
        return;
    }
    
    st[u] = 2;
    dfs(u + 1); //第一个分支不选
    st[u] = 0; //恢复现场
    
    st[u] = 1;
    dfs(u + 1);
    st[u] = 0;
}

int main()
{
    cin >> n;
    
    dfs(0);
}
