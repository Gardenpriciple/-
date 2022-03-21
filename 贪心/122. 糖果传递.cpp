#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1000010;

int n;
int a[N];
long long c[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    
    long long sum = 0;
    for (int i = 1; i <= n; i ++ ) sum += a[i];
    
    long long avg = sum / n;
    for (int i = n; i > 1; i --)
    {
        c[i] = c[i + 1] + avg - a[i];
    }
    c[1] = 0;
    
    sort(c + 1, c + n + 1);//注意是n+1
    
    long long res = 0;
    for (int i = 1; i <= n; i ++) res += abs(c[i] - c[(i + 1) / 2]);//本题下标从1开始
    
    printf("%lld\n", res); //long long输出也记得改
    
    return 0;
}

/*
有 n 个小朋友坐成一圈，每人有 a[i] 个糖果。

每人只能给左右两人传递糖果。

每人每次传递一个糖果代价为 1。

求使所有人获得均等糖果的最小代价。

输入格式
第一行输入一个正整数 n，表示小朋友的个数。

接下来 n 行，每行一个整数 a[i]，表示第 i 个小朋友初始得到的糖果的颗数。

输出格式
输出一个整数，表示最小代价。

数据范围
1≤n≤1000000,
0≤a[i]≤2×109,
数据保证一定有解。

输入样例：
4
1
2
5
4
输出样例：
4
*/
