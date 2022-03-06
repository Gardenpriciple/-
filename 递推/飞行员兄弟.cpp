#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define x first
#define y second

using namespace std;

typedef pair<int , int> PII; //用vector存方案

const int N = 5; //字符串最后会有一个\0



char g[N][N], backup[N][N];

int get(int x, int y)
{
    return 4 * x + y;
}

void turn_one(int x, int y)
{
    if (g[x][y] == '+') g[x][y] = '-';
    else g[x][y] = '+'; 
}



void turn_all(int x, int y)
{
    for (int i = 0; i < 4; i ++)
    {
        turn_one(x, i);
        turn_one(i, y);
    }
    
    turn_one(x, y);
}



int main()
{
    for (int i = 0; i < 4; i ++) cin >> g[i];
    
    vector<PII> res;
    for (int op = 0; op < 1 << 16; op ++)
    {
        vector<PII> temp;
        memcpy(backup, g, sizeof backup); //备份,backup和g长度相等
        
        //操作
        for (int i = 0; i < 4; i ++)
            for (int j = 0; j < 4; j ++)
                if (op >> get(i, j) & 1)
                {
                    temp.push_back({i, j});
                    turn_all(i, j);
                }
                
        // 判断是否全亮
        bool has_closed = false;
        for (int i = 0; i < 4; i ++)
            for (int j = 0; j < 4; j ++)
                if (g[i][j] == '+')
                    has_closed = true; 
        
        if (has_closed == false)
        {
            if (res.empty() || res.size() > temp.size()) res = temp;
        }//储存一种最佳方案
        
        memcpy(g, backup, sizeof g);//还原
    }
    
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i ++ ) cout << res[i].x+1 << ' ' << res[i].y+1 <<endl;
    
    return 0;
}

/*
飞行员兄弟”这个游戏，需要玩家顺利的打开一个拥有 16 个把手的冰箱。

已知每个把手可以处于以下两种状态之一：打开或关闭。

只有当所有把手都打开时，冰箱才会打开。

把手可以表示为一个 4×4 的矩阵，您可以改变任何一个位置 [i,j] 上把手的状态。

但是，这也会使得第 i 行和第 j 列上的所有把手的状态也随着改变。

请你求出打开冰箱所需的切换把手的次数最小值是多少。

输入格式
输入一共包含四行，每行包含四个把手的初始状态。

符号 + 表示把手处于闭合状态，而符号 - 表示把手处于打开状态。

至少一个手柄的初始状态是关闭的。

输出格式
第一行输出一个整数 N，表示所需的最小切换把手次数。

接下来 N 行描述切换顺序，每行输出两个整数，代表被切换状态的把手的行号和列号，数字之间用空格隔开。

注意：如果存在多种打开冰箱的方式，则按照优先级整体从上到下，同行从左到右打开。

数据范围
1≤i,j≤4
输入样例：
-+--
----
----
-+--
输出样例：
6
1 1
1 3
1 4
4 1
4 3
4 4
*/
