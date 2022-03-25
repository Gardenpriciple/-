#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = (1 << 20) + 10;

int primes[N], cnt;
int minp[N];
bool st[N];

void get_primes(int n)
{
    int cnt = 0;
    for (int i = 2; i <= n; i ++)
    {
        if (!st[i]) 
        {    
            minp[i] = i;
            primes[cnt ++ ] = i;
            
        }    
        for (int j = 0; primes[j] * i <= n; j ++)
        {
            int t = primes[j] * i;
            st[t] = true;
            minp[t] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}



int main()
{
    get_primes(N - 1);
    
    int fact[30], sum[N];// 因子个数
    
    int x;
    while (scanf("%d", &x) != -1) //-1就是文件结束
    {
        int k = 0, tot = 0; 
        while (x > 1)
        {
            int p = minp[x];
            fact[k] = p, sum[k] = 0;//当前的质因子是p，次数是0
            while (x % p == 0)
            {
                x /= p;
                sum[k] ++;
                tot ++;
            }
            k ++ ;
        }
        
        LL res = 1; 
        for (int i = 1; i <= tot; i ++ ) res *= i;
        for (int i = 0; i < k; i ++ )
            for (int j = 1; j <= sum[i]; j ++ )
                res /= j;
    
        printf("%d %lld\n", tot, res);
        
    }
    
    
    
    return 0;
}

/*
输入正整数 X，求 X 的大于 1 的因子组成的满足任意前一项都能整除后一项的严格递增序列的最大长度，以及满足最大长度的序列的个数。

输入格式
输入包含多组数据，每组数据占一行，包含一个正整数表示 X。

输出格式
对于每组数据，输出序列的最大长度以及满足最大长度的序列的个数。

每个结果占一行。

数据范围
1≤X≤220
输入样例：
2
3
4
10
100
输出样例：
1 1
1 1
2 1
2 2
4 6
*/
