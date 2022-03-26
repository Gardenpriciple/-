#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 50000;//预处理前50000个质数即可

int primes[N], cnt;
bool st[N];

int ans[N], len;

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; i * primes[j] <= n; j ++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

bool is_prime(int x)
{
    if (x < N) return !st[x];//x一定不等于1
    for (int i = 0; primes[i] <= x / primes[i]; i ++)
        if (x % primes[i] == 0)
            return false;
    return true;        
}



void dfs(int last, int prod, int s)//上一个用到的质数的下标,当前这个数是多少，剩余s
{
    if (s == 1)//S被凑出来了
    {
        ans[len ++ ] = prod;
        return;
    }
    
    if (s - 1 > (last < 0 ? 1 : primes[last]) && is_prime(s - 1))
    {
        ans[len ++ ] = prod * (s - 1);
    }
    
    for (int i = last + 1; primes[i] <= s / primes[i]; i ++ )//两个相乘可能爆int
    {
        int p = primes[i];
        for (int j = 1 + p, t = p; j <= s; t *= p, j += t)//t最大次幂,j所有数和
            if (s % j == 0)
                dfs(i, prod * t, s / j);
    }
}//prod存的是乘积


int main()
{
    get_primes(N - 1);
    
    int s;
    while(cin >> s)
    {
        len = 0;
        dfs(-1, 1, s);
    
        cout << len << endl;
        if (len)
        {
            sort(ans, ans + len);
            for(int i = 0; i < len; i ++) cout << ans[i] << ' ';
            cout << endl;
        }
        
    }
    
    return 0;
}

/*
城市中人们总是拿着号码牌，不停寻找，不断匹配，可是谁也不知道自己等的那个人是谁。

可是燕姿不一样，燕姿知道自己等的人是谁，因为燕姿数学学得好！

燕姿发现了一个神奇的算法：假设自己的号码牌上写着数字 S，那么自己等的人手上的号码牌数字的所有正约数之和必定等于 S。

所以燕姿总是拿着号码牌在地铁和人海找数字（喂！这样真的靠谱吗）。

可是她忙着唱《绿光》，想拜托你写一个程序能够快速地找到所有自己等的人。

输入格式
输入包含 k 组数据。

对于每组数据，输入包含一个号码牌 S。

输出格式
对于每组数据，输出有两行。

第一行包含一个整数 m，表示有 m 个等的人。

第二行包含相应的 m 个数，表示所有等的人的号码牌。

注意：你输出的号码牌必须按照升序排列。

数据范围
1≤k≤100,
1≤S≤2×109
输入样例：
42
输出样例：
3
20 26 41
*/
