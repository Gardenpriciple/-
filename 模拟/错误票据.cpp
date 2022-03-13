#include<cstdio>
#include<algorithm>
#include<cstring>
#include<sstream>
#include<iostream>

using namespace std;

const int N = 10010;

int n;
int a[N];

int main()
{
	int cnt;//读入行数
	cin >> cnt;
	string line;

	getline(cin, line);// 忽略掉第一行的回车
	while (cnt --)
	{
		getline(cin, line);
		stringstream ssin(line);

		while (ssin >> a[n]) n++;
	}//直接读入忽略第一个数也可以

	sort(a, a + n);

	int res1, res2;
	for (int i = 1; i < n; i++)
		if (a[i] == a[i - 1]) res1 = a[i];
		else if (a[i] >= a[i - 1] + 2) res2 = a[i];

	cout << res1 << res2 << endl;

	return 0;
}
