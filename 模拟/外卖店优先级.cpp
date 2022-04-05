#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, m, T;
int score[N], last[N]
bool st[N];

PII order[N]; //所有订单

int main()
{
    scanf("%d%d%d", &n, &m, &T);
    for (int i = 0; i < m; i ++) scanf("%d%d", &order[i].x, &order[i].y);
    sort(order, order + m);//pair自带比较函数，按先后比较两个关键字
    
    for (int i = 0; i < m;)
    {
        int j = i;
        while (j < m && order[j] == order[i]) j ++;//处理同一家店出现多家订单
        int t = order[i].x, id = order[i].y, cnt = j - i;
        i = j;
        
        score[id] -= t - last[id] - 1;
        if (score[id] < 0) score[id] = 0;
        if (score[id] <= 3) st[id] = false;//t时刻之前
        
        score[id] += cnt * 2;//开始t时刻
        if (score[id] > 5) st[id] = true;
        
        last[id] = t;//记得更新last[id]
    }
    
    for (int i = 1; i <= n; i ++)
        if (last[i] < T)
        {
            score[i] -= T - last[i];
            if (score[i] <= 3) st[i] = false;
        }
    
    int res = 0;
    for (int i = 1; i <= n; i ++) res += st[i];
    
    printf("%d", res);
    
    return 0;
}


/*
饱了么”外卖系统中维护着 N 家外卖店，编号 1∼N。

每家外卖店都有一个优先级，初始时 (0 时刻) 优先级都为 0。

每经过 1 个时间单位，如果外卖店没有订单，则优先级会减少 1，最低减到 0；而如果外卖店有订单，则优先级不减反加，每有一单优先级加 2。

如果某家外卖店某时刻优先级大于 5，则会被系统加入优先缓存中；如果优先级小于等于 3，则会被清除出优先缓存。

给定 T 时刻以内的 M 条订单信息，请你计算 T 时刻时有多少外卖店在优先缓存中。

输入格式
第一行包含 3 个整数 N,M,T。

以下 M 行每行包含两个整数 ts 和 id，表示 ts 时刻编号 id 的外卖店收到一个订单。

输出格式
输出一个整数代表答案。

数据范围
1≤N,M,T≤105,
1≤ts≤T,
1≤id≤N
输入样例：
2 6 6
1 1
5 2
3 1
6 2
2 1
6 2
输出样例：
1
样例解释
6 时刻时，1 号店优先级降到 3，被移除出优先缓存；2 号店优先级升到 6，加入优先缓存。

所以是有 1 家店 (2 号) 在优先缓存中。
*/
