#include<iostream>
#include<queue>
#include<algorithm>

#define x first
#define y second


using namespace std;

typedef pair<int , int> PII;

const int N = 25;

int n, m;
char g[N][N];

int bfs(int sx, int sy)
{
    queue<PII> q;
    q.push({sx, sy});
    g[sx][sy] = '#';//起点被遍历
    int res = 0;
    
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        res ++;
        
        for (int i = 0; i < 4; i ++ )
        {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] != '.') continue;
            
            g[x][y] = '#';
            q.push({x, y});
        }
    }
    
    return res;
}


int main()
{
    while (cin >> m >> n, n || m)
    {
        for (int i = 0; i < n; i ++) cin >> g[i];
        int x, y;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (g[i][j] == '@')
                {
                    x = i;
                    y = j;
                }
                
        cout << bfs(x, y) << endl;
    }
}

/*
有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。

你站在其中一块黑色的瓷砖上，只能向相邻（上下左右四个方向）的黑色瓷砖移动。

请写一个程序，计算你总共能够到达多少块黑色的瓷砖。

输入格式
输入包括多个数据集合。

每个数据集合的第一行是两个整数 W 和 H，分别表示 x 方向和 y 方向瓷砖的数量。

在接下来的 H 行中，每行包括 W 个字符。每个字符表示一块瓷砖的颜色，规则如下

1）‘.’：黑色的瓷砖；
2）‘#’：红色的瓷砖；
3）‘@’：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。

当在一行中读入的是两个零时，表示输入结束。

输出格式
对每个数据集合，分别输出一行，显示你从初始位置出发能到达的瓷砖数(记数时包括初始位置的瓷砖)。

数据范围
1≤W,H≤20
输入样例：
6 9 
....#. 
.....# 
...... 
...... 
...... 
...... 
...... 
#@...# 
.#..#. 
0 0
输出样例：
45
*/
