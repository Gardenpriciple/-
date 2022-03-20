#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int n;
char g[N][N];
bool st[N][N];
PII q[N * N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void bfs(int sx, int sy, int &total, int &bound)//需要修改值，得用引用
{
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    st[sx][sy] = true;
    
    while (hh <= tt)
    {
        PII t = q[hh ++];
        
        total ++;
        bool is_bound = false;//下面这个for循环搜的是自己，所以这里是false
        for (int i = 0; i < 4; i ++ )
        {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= n) continue;
            if (!st[x][y]) continue;
            if (g[x][y] == '.')
            {
                is_bound = true;
                continue;
            }
            
            q[ ++ tt] = {x, y};
            st[x][y] = true;
        }
        
        if (is_bound) bound ++;
    }
}

int main()
{
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++ ) scanf("%s", &g[i]);
    
    int cnt = 0;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            if (!st[i][j] && g[i][j] == '#')
            {
                int total = 0, bound = 0;
                bfs(i, j, total, bound);
                if (total == bound) cnt ++;
            }
            
    printf("%d\n", cnt);
    
    return 0;
}
