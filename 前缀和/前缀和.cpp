#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

int n, m;
int a[N]; //原数组
int s[N], //前缀和数组

int main()
{
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}

	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", s[r] - s[l - 1]);
	}

	return 0;
}
