#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 16; 

int n;
int st[N];   //记录每个位置的当前的状态：0表示还没考虑，1表示选它，2表示不选
int ways[1 << 15][16], cnt;

void dfs(int u)
{
    if (u > n) 
    {
        for (int i = 0; i <= n; i++)
            if (st[i] == 1)
                ways[cnt][i] = i;
        cnt ++;// 记录方案
        return;
    }
    
    st[u] = 2;
    dfs(u + 1); //第一个分支不选
    st[u] = 0; //恢复现场，递归一定记得这一次不能影响上一次
    
    st[u] = 1;
    dfs(u + 1);
    st[u] = 0;
}

int main()
{
    cin >> n;
    
    dfs(1);
    
    for(int i = 0; i < cnt; i ++)
    {
        for (int j = 1; j <= n; j ++) printf(" %d", ways[i][j]);
        puts(""); //输出括号里的字符串加一个回车
    }
    
    return 0;
}//储存
