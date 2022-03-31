#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int N = 110, INF = 10000000;

int n;
int f[N][N];

bool is_match(char l, char r)
{
    if (l == '(' && r == ')') return true;
    if (l == '[' && r == ']') return true;
    
    return false;
}


int main()
{
    string s;
    cin >> s;
    n = s.size();
    
    for (int i = 0; i < n; i ++ ) f[i][i] = 1;
    
    for (int len = 2; len <= n; len ++ )
        for (int i = 0; i + len - 1 < n; i ++ )
        {
            int j = i + len - 1;
            f[i][j] = INF;
            if (is_match(s[i], s[j])) f[i][j] = f[i + 1][j - 1];
            if (j >= 1) f[i][j] = min(f[i][j], min(f[i][j - 1], f[i + 1][j]) + 1);
            
            for (int k = i; k < j; k ++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
        }
        
    printf("%d\n", f[0][n - 1]);    
    
    return 0;
}

/*
Hecy 又接了个新任务：BE 处理。

BE 中有一类被称为 GBE。

以下是 GBE 的定义：

空表达式是 GBE
如果表达式 A 是 GBE，则 [A] 与 (A) 都是 GBE
如果 A 与 B 都是 GBE，那么 AB 是 GBE
下面给出一个 BE，求至少添加多少字符能使这个 BE 成为 GBE。

注意：BE 是一个仅由(、)、[、]四种字符中的若干种构成的字符串。

输入格式
输入仅一行，为字符串 BE。

输出格式
输出仅一个整数，表示增加的最少字符数。

数据范围
对于所有输入字符串，其长度小于100。

输入样例：
[])
输出样例：
1
*/
