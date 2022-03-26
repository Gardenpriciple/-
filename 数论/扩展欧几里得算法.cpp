#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }//边界条件
    int d = exgcd(b, a % b, x, y);
    y -= a / b * x;
    return d;
}


int main()
{
    int a, b, x, y;
    cin >> a >> b;
    int d = exgcd(a, b, y, x);
    
    printf("%d * %d + %d * %d = %d\n", a, x, b, y, d);
    return 0;
}
