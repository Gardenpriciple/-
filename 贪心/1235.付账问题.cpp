#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 500010;

int n;
int a[N];

int main()
{
    double s;
    scanf("%d%lf", &n, &s); //double输入也要注意
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
    
    double res = 0, avg = s / n;
    sort(a, a + n);
    
    for (int i = 0; i < n; i ++ )
    {
        double cur = s / (n - i);
        if (a[i] < cur) cur = a[i];
        res += (cur - avg) * (cur - avg);
        s -= cur;
    }
    
    printf("%.4lf\n", sqrt(res / n));
    
    return 0;
}

/*
几个人一起出去吃饭是常有的事。

但在结帐的时候，常常会出现一些争执。

现在有 n 个人出去吃饭，他们总共消费了 S 元。

其中第 i 个人带了 ai 元。

幸运的是，所有人带的钱的总数是足够付账的，但现在问题来了：每个人分别要出多少钱呢？

为了公平起见，我们希望在总付钱量恰好为 S 的前提下，最后每个人付的钱的标准差最小。

这里我们约定，每个人支付的钱数可以是任意非负实数，即可以不是 1 分钱的整数倍。

你需要输出最小的标准差是多少。

标准差的介绍：标准差是多个数与它们平均数差值的平方平均数，一般用于刻画这些数之间的“偏差有多大”。

形式化地说，设第 i 个人付的钱为 bi 元，那么标准差为 :

p1.png

输入格式
第一行包含两个整数 n、S；

第二行包含 n 个非负整数 a1, …, an。

输出格式
输出最小的标准差，四舍五入保留 4 位小数。

数据范围
1≤n≤5×105,
0≤ai≤109,
0≤S≤1015。

输入样例1：
5 2333
666 666 666 666 666
输出样例1：
0.0000
输入样例2：
10 30
2 1 4 7 4 8 3 6 4 7
输出样例2：
0.7928

*/
