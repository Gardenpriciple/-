#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

double x;


int main()
{
    cin >> x;
    double l = -10000, r = 10000;
    while(r - 1 > 1e-8) //比较保险
    {
        double mid = (l + r)/2;
        if (mid * mid * mid >= x) r = mid;
        else l = mid;//mid可以取任何值，因为实数是稠密的
    }
    
    printf("%lf\n", l);// %.4lf是保留四位小数
    
    return 0;
}
