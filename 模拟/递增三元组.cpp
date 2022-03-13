#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
int a[N], b[N], c[N];
int as[N]; //as[i]表示A中多少个数小于b[i], cs同理
int cs[N];
int cnt[N], s[N];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("&d", &a[i]);
	for (int i = 0; i < n; i++) scanf("&d", &b[i]);
	for (int i = 0; i < n; i++) scanf("&d", &c[i]);

	//求as
	for (int i = 0; i < n; i++) cnt[a[i]]++;
	for (int i = 1; i < N; i++) s[i] = s[i - 1] + cnt[i];
	for (int i = 0; i < n; i++) as[i] = s[b[i] - 1];

	//求cs，记得把cnt s清空
	memset(cnt, 0, sizeof(cnt));
	memset(s, 0, sizeof(s));
	for (int i = 0; i < n; i++) cnt[c[i]]++;
	for (int i = 1; i < N; i++) s[i] = s[i - 1] + cnt[i];
	for (int i = 0; i < n; i++) cs[i] = s[N - 1] - s[b[i]];//记得是N - 1最大

	//枚举每个b[i],最多有10**15个，可能爆int
	LL res = 0;
	for (int i = 0; i < n; i++) res += (LL)as[i] * cs[i];

	cout << res << endl;


	return 0;
}
