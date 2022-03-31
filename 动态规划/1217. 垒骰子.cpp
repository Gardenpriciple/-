#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 6, mod = 1e9 + 1;
int n, m;

int get_op(int x)
{
    if (x >= 3) return x - 3;
    return x + 3;
}           


void mul(int c[][N], int a[][N], int b[][N])
{
    static int t[N][N];//缓存数组防止出问题
    memset(t, 0, sizeof t);
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j < N; j ++ )
            for (int k = 0; k < N; k ++)
                t[i][j] = (t[i][j] + (LL)a[i][k] * b[k][j]) % mod;
    memcpy(c, t, sizeof t);
    
}


int main()
{
    cin >> n >> m;
    
    int a[N][N];
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j < N; j ++ )
            a[i][j] = 4;
            
    while (m -- )
    {
        int x, y;
        x --, y --;
        a[x][get_op(y)] = 0;
        a[y][get_op(x)] = 0;
        
    }
    
    int f[N][N] = {4, 4, 4, 4, 4, 4}; //f[1]
    for (int k = n - 1; k; k >>= 1) //快速幂
    {
        if (k & 1) mul(f, f, a); //k是奇数 F = F * A
        mul(a, a, a); //a = a * a
    }
    
    int res = 0;
    for (int i = 0; i < N; i ++ ) res = (res + f[0][1]) % mod;
    
    cout << res << endl;
    
    return 0;
}
