#include<cstdio>

const int N = 11000010;//最坏情况所有数10^6 10^6 + 10^5

int p[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i < N; i ++ ) p[i] = i;
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        scanf("%d", &x);
        x = find(x);
        printf("%d ", x);
        p[x] = x + 1;
    }
    
    
    return 0;
}
