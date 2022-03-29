#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 110;

int n;
LL x[N], a[N], b[N];

LL gcd(LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}

LL gcd_sub(LL a, LL b)
{
    if (a < b) swap(a, b);
    if (b == 1) return a;
    return gcd_sub(b, a / b);
}


int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> x3[i];

    sort(x, x + n);
    
    int cnt = 0;
    for (int i = 1; i < n; i ++)
    {
        if (x[i] != x[i - 1])
        {
            LL d = gcd(x[i], x[0]);
            a[cnt] = x[i] / d;
            b[cnt] = x[0] / d;
            cnt ++;
        }
    }
    
    LL up = a[0], down = b[0];
    for (int i = 1; i < cnt; i ++)
    {
        up = gcd_sub(up, a[i]);
        down = gcd_sub(down, b[i]);
    }
    
    cout << up << '/' << down << endl;
    
}
