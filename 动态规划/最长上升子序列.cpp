#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N], f[N];


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++)
	{
		f[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (a[i] > a[j])
				f[i] = max(f[i], f[j] + 1);
		}
	}

	cout << *max_element(f, f + n + 1) << endl; //记得f是从1开始计数的，所以要+1

	//int res = 0; 
	//for (int i = 1; i <= n; i++) res = max(res, f[i]);
	//cout << res << endl;

	//for (int i = 1; i <= n; i++)
	//	cout << f[i] << endl;

	return 0;
}
