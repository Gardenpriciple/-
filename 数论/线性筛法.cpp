#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N]; //当前数有没有筛过
int minp[N];

int get_primes(int n)
{
    for (int i = 2; i <= n; i ++)
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] * i <= n; j ++ )
        {
            st[primes[j] * i] = true;
            minp[primes[j] * i] = primes[j];// 存下最小质因子
            if (i % primes[j] == 0) break;
        }
    }
}

int main()
{
    get_primes(100000);
    
    for (int i = 0; i < N; i ++ ) printf("%d\n", primes[i]);
}
