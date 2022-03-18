#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 210;

int n, m;
char g[N][N];
int dist[N][N];

int bfs(PII start, PII end)
{
    queue<PII> q;
    memset (dist, -1, sizeof dist);
    
    dist[start.x][start.y] = 0;
    q.push(start);
    
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};//用偏移量代替写那移动的四句话,三维的情况也更方便
    
    while(q.size())
    {
        auto t = q.front();
        q.pop();//否则陷入死循环
        
        for (int i = 0; i < 4; i ++ )
        {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m) continue; //越界
            if (g[x][y] == '#') continue; //障碍物
            if (dist[x][y] != -1) continue; //之前已经遍历过
            
            dist[x][y] = dist[t.x][t.y] + 1;
            q.push({x, y});
        }
    }
    
    return dist[end.x][end.y];
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T --)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i ++) scanf("%s", g[i]);//用字符数组存字符串,注意存字符串不是%d
        
        PII start, end;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
            {
                if (g[i][j] == 'S') start = {i, j};
                else if (g[i][j] == 'E') end = {i, j};
            }
        
        int distance = bfs(start, end);
        if (distance == -1) printf("oop!\n");
        else printf("%d\n", distance);
    }
    
    return 0;
}
