#include<cstdio>
#include<string.h>

const int N = 1010;

char s[N];
int f[N][N];

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    
    for (int len = 1; len <= n; len ++)
        for (int l = 0; l + len - 1 < n; l ++)
        {
            int r = l + len - 1;
            if (len == 1) f[l][r] = 1;
            else
            {
                if (s[l] == s[r]) f[l][r] = f[l + 1][r - 1] + 2;
                if (f[l][r - 1] > f[l][r]) f[l][r] = f[l][r - 1];
                if (f[l + 1][r] > f[l][r]) f[l][r] = f[l + 1][r];
            }
        }
        
    printf("%d\n", n - f[0][n - 1]);//注意是n-1
    
    return 0;//没有加其他头文件，所以非常快
}
