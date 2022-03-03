#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 10;

int n;
int state[N]; // 0表示还没放数，1~n表示放了哪个数
bool used[N]; //每个数有没有被用过，true表示用过

void dfs(int u)
{
    if (u > n)
    {
        for (int i = 1; i <= n; i++) printf(" %d", state[i]);
        puts("");
        
        return;
    }
    
    //枚举每个分支，即当前位置可以填哪些数
    for (int i = 1; i <= n; i ++)
        if (!used[i])
        {
            state[u] = i;
            used[i] = true;
            dfs(u + 1);
            
            //恢复现场
            state[u] = 0;
            used[i] = false;
        }
    
}


int main()
{
    scanf("%d", &n);
    
    dfs(1);
    
    return 0;
}
