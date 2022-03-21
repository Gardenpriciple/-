#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

int n;
struct Edge
{
    int id, w;
};
vector<Edge> h[N];
int dist[N];

void dfs(int u, int father, int distance)
{
    dist[u] = distance;
    
    for (auto node : h[u])
        if (node.id != father) //防止遍历回来时的路
            dfs(node.id, u, distance + node.w);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        h[a].push_back({b, c});
        h[b].push_back({a, c});
    }
    
    dfs(1, -1, 0);
    
    int u = 1;
    for (int i = 1; i <= n; i ++ )
        if (dist[i] > dist[u])
            u = i;
            
    dfs(u, -1, 0);
    
    for (int i = 1; i <= n; i ++)
        if (dist[i] > dist[u])
            u = i;
    
    int s = dist[u];        
    printf("%d\n", s * 10 + s * (s + 1ll) / 2);//10e5 * 10e5 可能爆int，1ll是吧1转换为int
    
    return 0;
}
