#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector> //保留每个余数前三大的数,用vector来存

using namespace std;

const int N = 1010;

int n, m;
vector<int> a[N];
int f[4][N];//从大到小循环第二维就能省掉一维空间

int main()
{
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n; i ++ )
    {
        int x;
        scanf("%d", &x);
        a[x % m].push_back(x);
    }
    
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    
    for (int i = 0; i < n; i ++ )
    {
        sort(a[i].begin(), a[i].end());
        reverse(a[i].begin(), a[i].end());//从大到小
        
        for (int u = 0; u < 3 && u < a[i].size(); u ++ )//可能i余数这一组不足三个
        {
            int x = a[i][u];
            for (int j = 3; j >= 1; j -- )
                for (int k = 0; k < m; k ++ )
                    f[j][k] = max(f[j][k], f[j - 1][(k - x % m + m) % m] + x);
        }//联想背包问题优化
    }
    
    printf("%d", f[3][0]);
    
    return 0;
}
