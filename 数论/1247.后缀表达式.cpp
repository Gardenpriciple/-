#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 200010;

int n, m;
int a[N];

int main()
{
    scanf("%d%d", &n, &m);
    int k = n + m + 1;
    for (int i = 0; i < k; i ++ ) scanf("%d", &a[i]);
    
    
    LL res = 0;
    
    if (!m)
    {
        for (int i = 0; i < k; i ++ ) res += a[i];
    }
    else
    {    
        sort(a, a + k);//找到最大最小值即可

        res = a[k - 1] - a[0];
        for (int i = 1; i < k - 1; i ++) res += abs(a[i]);
    }
    printf("%lld\n", res);
    
    
    return 0;
}
