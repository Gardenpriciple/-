#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

typedef long long LL;//int 范围2**31 - 1

LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    
    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


int main()
{
    LL a, b, c, k;
    
    while(cin >> a >> b >> c >> k, a || b || c || k)//逗号表达式,值是最后一个式子值
    {
        LL x, y;
        LL z = 1ll << k;//longlong 类型的1
        LL d = exgcd(c, z, x, y);
        if ((b - a) % d) cout << "FOREVER" << endl;
        else
        {
            x *= (b - a) / d;
            z /= d;
            cout << (x % z + z) % z << endl; 
        }
    }
    
    return 0;
}

/*
对于 C 语言的循环语句，形如：

for (variable = A; variable != B; variable += C)
  statement;
请问在 k 位存储系统中循环几次才会结束。

若在有限次内结束，则输出循环次数。否则输出死循环。

输入格式
多组数据，每组数据一行四个整数 A,B,C,k。

读入以 0 0 0 0 结束。

输出格式
若在有限次内结束，则输出循环次数。

否则输出 FOREVER。

数据范围
1≤k≤32,
0≤A,B,C<2k
输入样例：
3 3 2 16
3 7 2 16
7 3 2 16
3 4 2 16
0 0 0 0
输出样例：
0
2
32766
FOREVER

*/
