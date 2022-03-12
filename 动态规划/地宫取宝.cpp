#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;

const int N = 55, Mod = 1000000007;

int n, m, k;
int w[N][N];
int f[N][N][13][14];

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> w[i][j];
			w[i][j] ++;//-1 到13 每个往上加一
		}

	f[1][1][1][w[1][1]] = 1;
	f[1][1][0][0] = 1;

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 && j == 1) continue;
			for (int u = 0; u <= k; u ++)
				for (int v = 0; v <= 13; v++)
				{
					int& val = f[i][j][u][v];
					val = (val + f[i - 1][j][u][v]) % Mod;
					val = (val + f[i][j - 1][u][v]) % Mod;//先更新i和j
					if (u > 0 && v == w[i][j])
					{
						for (int c = 0; c < v; c++)
						{
							val = (val + f[i - 1][j][u - 1][c]) % Mod;
							val = (val + f[i][j - 1][u - 1][c]) % Mod;
						}
					}
				}
		}
	
	int res = 0; 
	for (int i = 0; i <= 13; i++) res = (res + f[n][m][k][i]) % Mod;

	cout << res << endl;

	return 0;
}
