#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 200010, M = N * 2;

int n, maxd;
int h[N], e[M], ne[M], idx;
int d1[N], d2[N], p1[N], up[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs_d(int u, int father)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j != father)
        {
            dfs_d(j, u);
            int distance = d1[j] + 1;
            if (distance > d1[u])
            {
                d2[u] = d1[u], d1[u] = distance;
                p1[u] = j;//记录一下最大值是从j下去的
            }
            else if (distance > d2[u]) d2[u] = distance;
        }
    }
    
    maxd = max(maxd, d1[u] + d2[u]);
}

void dfs_u(int u, int father)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j != father)
        {
            up[j] = up[u] + 1;
            if (p1[u] == j) up[j] = max(up[j], d2[u] + 1);
            else up[j] = max(up[j], d1[u] + 1);
            dfs_u(j, u);
        }
    }
}



int main()
{
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    
    for (int i = 0; i < n - 1; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    
    dfs_d(0, -1);//传入负节点防止往上走
    dfs_u(0, -1);
    
    for (int i = 0; i < n; i ++ )
    {
        int d[3] = {d1[i], d2[i], up[i]};
        sort(d, d + 3);
        if (d[1] + d[2] == maxd) printf("%d\n", i);
    }
    
    return 0;
}

/*
W 市的交通规划出现了重大问题，市政府下定决心在全市各大交通路口安排疏导员来疏导密集的车流。

但由于人员不足，W 市市长决定只在最需要安排人员的路口安排人员。

具体来说，W 市的交通网络十分简单，由 n 个交叉路口和 n−1 条街道构成，交叉路口路口编号依次为 0,1,…,n−1 。

任意一条街道连接两个交叉路口，且任意两个交叉路口间都存在一条路径互相连接。

经过长期调查，结果显示，如果一个交叉路口位于 W 市交通网最长路径上，那么这个路口必定拥挤不堪。

所谓最长路径，定义为某条路径 p=(v1,v2,…,vk)，路径经过的路口各不相同，且城市中不存在长度大于 k 的路径（因此最长路径可能不唯一）。

因此 W 市市长想知道哪些路口位于城市交通网的最长路径上。

输入格式
第一行包含一个整数 n。

之后 n−1 行每行两个整数 u,v，表示编号为 u 和 v 的路口间存在着一条街道。

输出格式
输出包括若干行，每行包括一个整数——某个位于最长路径上的路口编号。

为了确保解唯一，请将所有最长路径上的路口编号按编号顺序由小到大依次输出。

数据范围
1≤n≤2×105
输入样例：
10
0 1
0 2
0 4
0 6
0 7
1 3
2 5
4 8
6 9
输出样例：
0
1
2
3
4
5
6
8
9
*/
