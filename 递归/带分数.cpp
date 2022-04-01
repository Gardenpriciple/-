#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 20;

int n;
bool st[N], backup[N];
int ans;


bool check(int a, int c)
{
    int b = n*c - a*c;
    if (!a || !b || !c) return false;
    
    memcpy(backup, st, sizeof st);
    while (b)
    {
        int x = b % 10;
        b /= 10; //取个位再把个位删掉
        if (!x || backup[x] ) return false; //题目要求不包含0
        backup[x] = true;
    }//创一个备份数组backup判重，st要用于恢复现场。
    /*
    若backup[x]真，说明x用过不行，若假，x没用过，这里b把x用了，把backup改成真，最后再判断一下是不是九个数字都被用过了
    */
    
    for (int i = 1; i <= 9; i ++ )
        if (!backup[i])
            return false;
            
    return true;
}

void dfs_c(int u, int a, int c)
{
    if (u > 9) return;
    
    if (check(a, c)) ans++;
    
    for (int i = 1; i <= 9; i ++ )
        if (!st[i])
        {
            st[i] = true;
            dfs_c(u + 1, a, c * 10 + i);
            st[i] = false;
        }
}

void dfs_a(int u, int a)
{
    if (a >= n) return;
    if (a) dfs_c(u, a, 0);
    
    for (int i = 1; i <= 9; i ++ )
        if (!st[i])
        {
            st[i] = true;
            dfs_a(u + 1, a * 10 + i);
            st[i] = false;
        }
}

int main()
{
    cin >> n;
    
    dfs_a(0, 0);//用了多少个数字
    
    cout << ans << endl;
    
    return 0;
}


/*
100 可以表示为带分数的形式：100=3+69258714
还可以表示为：100=82+3546197
注意特征：带分数中，数字 1∼9 分别出现且只出现一次（不包含 0）。

类似这样的带分数，100 有 11 种表示法。

输入格式
一个正整数。

输出格式
输出输入数字用数码 1∼9 不重复不遗漏地组成带分数表示的全部种数。

数据范围
1≤N<106
输入样例1：
100
输出样例1：
11
输入样例2：
105
输出样例2：
6
*/
