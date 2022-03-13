#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010, Mod = 100000007;
int f[N][N];

int get_mod(int a, int b)
{
	return (a % b + b) % b; //求正余数
}

int main()
{
	int n, s, a, b;
	cin >> a >> s >> n >> b;

	f[0][0] = 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j++)
		{
			f[i][j] = (f[i - 1][get_mod(j - a * i, n)] + f[i - 1][get_mod(j + b * i, n)]) % Mod;
		}//后面用i和n-i一样

	cout << f[n - 1][s % n] << endl;

	return 0;
}
