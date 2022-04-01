
#include<iostream>

using namespace std;

const int N = 25;

int n, m;
int s = 1;

int a[N];
bool st[N];

void dfs(int u)
{
    if (u > m)
    {
        for (int j = 1; j <= m; j ++) cout << a[j] << ' ';
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i ++ )
    {
        if (!st[i] && i > a[u - 1])
        { 
            a[u] = i;
            st[i] = true;


            dfs(u + 1);
            st[i] = false;
        }
    }
}


int main()
{
    cin >> n >> m;

    for (int i = m; i > n - m; i -- ) s = i * s;

    dfs(1);

    return 0;
}

/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 30;

int n, m;
int way[N];

void dfs(int u, int start)
{
    if (u + n - start < m) return;  // 剪枝
    if (u == m + 1)
    {
        for (int i = 1; i <= m; i ++ ) printf("%d ", way[i]);
        puts("");
        return;
    }

    for (int i = start; i <= n; i ++ )
    {
        way[u] = i;
        dfs(u + 1, i + 1);
        way[u] = 0; // 恢复现场
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    dfs(1, 1);

    return 0;
}
*/

/*
从 1∼n 这 n 个整数中随机选出 m 个，输出所有可能的选择方案。

输入格式
两个整数 n,m ,在同一行用空格隔开。

输出格式
按照从小到大的顺序输出所有方案，每行 1 个。

首先，同一行内的数升序排列，相邻两个数用一个空格隔开。

其次，对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面（例如 1 3 5 7 排在 1 3 6 8 前面）。

数据范围
n>0 ,
0≤m≤n ,
n+(n−m)≤25
输入样例：
5 3
输出样例：
1 2 3 
1 2 4 
1 2 5 
1 3 4 
1 3 5 
1 4 5 
2 3 4 
2 3 5 
2 4 5 
3 4 5 
*/

